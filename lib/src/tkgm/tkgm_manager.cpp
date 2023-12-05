#include <tkgm/tkgm_manager.hpp>

namespace tkht
{
namespace tkgm
{
void Manager::clear() {
  module_map.clear();
  localization_map.clear();
  setting_map.clear();

  sequlist->clear();
  localization->clear();
  setting->clear();
}

void Manager::load(std::filesystem::path path) {
  clear();

  sequlist->load(path / "modules/sequlist.json");

  for (const std::filesystem::directory_entry entry :
       std::filesystem::directory_iterator(path / "modules")) {
    if (std::filesystem::is_directory(entry)) {
      Module module;
      module.load((entry.path() / "module.json").string());
      module_map[module["name"]] = module;

      Localization localization;
      localization.load((entry.path() / "localization.json").string());
      localization_map[module["name"]] = localization;

      Setting setting;
      setting.load((entry.path() / "setting.json").string());
      setting_map[module["name"]] = setting;

      if (!std::count(sequlist->begin(), sequlist->end(), module["name"])) {
        sequlist->push_back(module["name"]);
      }
    }
  }
}

void Manager::save_sequlist() {
  sequlist->save();
}

void Manager::save_setting() {
  for (std::shared_ptr<Setting::Tab> tab: Manager::Shared().setting->tab_list) {
    for (std::shared_ptr<Setting::Group> group: tab->group_list) {
      for (std::shared_ptr<Setting::Item> item: group->item_list) {
        setting_map
        .at(item->key_link[0])
        .at("root").at(std::stoi(item->key_link[1]))
        .at("content").at(std::stoi(item->key_link[2]))
        .at("content").at(std::stoi(item->key_link[3]))
        .merge_patch(*item);
      }
    }
  }

  for (std::pair<std::string, Setting> pair_setting : setting_map) {
    pair_setting.second.save();
  }
}

void Manager::merge() {
  localization->clear();
  setting->clear();
  for (int i = 0; i < sequlist->size(); i++) {
    std::string name = sequlist->at(i);
    localization->merge(localization_map[name]);
    setting->merge({name}, setting_map[name]);
  }
}

void Manager::move(unsigned int from, unsigned int to) {
  sequlist->move(from, to);
}
}
}