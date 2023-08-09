#include <tkgm/tkgm_manager.hpp>

namespace tkht
{
namespace tkgm
{
void Manager::clear() {
  sequlist.clear();
  localization.clear();
  setting.clear();

  module_map.clear();
  localization_map.clear();
  setting_map.clear();
}

void Manager::load() {
  clear();

  sequlist.load("modules/sequlist.json");

  for (const std::filesystem::directory_entry entry :
       std::filesystem::directory_iterator("modules")) {
    if (std::filesystem::is_directory(entry)) {
      Module module;
      module.load(std::filesystem::path(entry).append("module.json").string());
      module_map[module["name"]] = module;

      Localization localization;
      localization.load(std::filesystem::path(entry).append("localization.json").string());
      localization_map[module["name"]] = localization;

      Setting setting;
      setting.load(std::filesystem::path(entry).append("setting.json").string());
      setting_map[module["name"]] = setting;

      if (!std::count(sequlist.begin(), sequlist.end(), module["name"])) {
        sequlist.push_back(module["name"]);
      }
    }
  }
}

void Manager::save_sequlist() {
  sequlist.save();
}

void Manager::save_setting() {
  for (std::pair<std::string, Setting> pair_setting : setting_map) {
    pair_setting.second.save();
  }
}

void Manager::merge() {
  for (int i = 0; i < sequlist.size(); i++) {
    localization.merge_patch(localization_map[sequlist[i]]);
    setting.merge_patch(setting_map[sequlist[i]]);
  }
}

void Manager::move(unsigned int from, unsigned int to) {
  sequlist.move(from, to);
}
}
}