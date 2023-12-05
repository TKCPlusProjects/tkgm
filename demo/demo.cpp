#include <tkgm/tkgm.hpp>

void log() {
  using namespace tkht;
  using namespace tkht::tkgm;

  Msg("-----------------------------------");

  std::shared_ptr<Setting> setting = Manager::Shared().setting;
  
  for (int tab_i = 0; tab_i < setting->tab_list.size(); tab_i++) {
    std::shared_ptr<Setting::Tab> tab = setting->tab_list[tab_i];
    Msg("Tab: %d %s", tab_i, Manager::Shared().localization->string(tab->name).c_str());
    for (int group_i = 0; group_i < tab->group_list.size(); group_i++) {
    std::shared_ptr<Setting::Group> group = tab->group_list[group_i];
      Msg(" Group: %d %s", group_i, Manager::Shared().localization->string(group->name).c_str());
      for (int item_i = 0; item_i < group->item_list.size(); item_i++) {
      std::shared_ptr<Setting::Item> item = group->item_list[item_i];
        switch (item->type) {
        case Setting::Item::Type::Keybutton: {
          std::shared_ptr<Setting::Keybutton> type_item = std::static_pointer_cast<Setting::Keybutton>(item);
          Msg("  Keybutton: %d %s %d",
          item_i,
          Manager::Shared().localization->string(type_item->name).c_str(),
          type_item->value);
        } break;
        case Setting::Item::Type::Checkbox: {
          std::shared_ptr<Setting::Checkbox> type_item = std::static_pointer_cast<Setting::Checkbox>(item);
          Msg("  Checkbox: %d %s %s", 
          item_i,
          Manager::Shared().localization->string(type_item->name).c_str(),
          type_item->value ? "true" : "false");
        } break;
        case Setting::Item::Type::Slideint: {
          std::shared_ptr<Setting::Slideint> type_item = std::static_pointer_cast<Setting::Slideint>(item);
          Msg("  Slideint: %d %s %d", 
          item_i,
          Manager::Shared().localization->string(type_item->name).c_str(),
          type_item->value);
        } break;
        case Setting::Item::Type::Slidefloat: {
          std::shared_ptr<Setting::Slidefloat> type_item = std::static_pointer_cast<Setting::Slidefloat>(item);
          Msg("  Slidefloat: %d %s %.2f", 
          item_i,
          Manager::Shared().localization->string(type_item->name).c_str(),
          type_item->value);
        } break;
        default:
          break;
        }
      }
    }
  }
}

int main(int argc, char** argv) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;
  SubscribeSignalList({SIGSEGV, SIGABRT});

  std::filesystem::path local(argv[0]);
  
  Manager::Shared().load(local.parent_path());
  Manager::Shared().merge();

  log();

  std::static_pointer_cast<Setting::Checkbox>(
    Manager::Shared().setting
    ->tab_list[0]
    ->group_list[0]
    ->item_list[0]
  )->SetValue(0);
  Manager::Shared().save_setting();
  Manager::Shared().merge();

  log();

  std::static_pointer_cast<Setting::Checkbox>(
    Manager::Shared().setting
    ->tab_list[0]
    ->group_list[0]
    ->item_list[0]
  )->SetValue(1);
  Manager::Shared().save_setting();
  Manager::Shared().merge();

  log();

  return 1;
}