#include <tkgm/tkgm.hpp>

int main(int argc, char** argv) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;
  SubscribeSignalList({SIGSEGV, SIGABRT});

  std::filesystem::path local(argv[0]);
  
  Manager::Shared().load(local.parent_path());
  Manager::Shared().merge();

  for (std::shared_ptr<Setting::Tab> tab: Manager::Shared().setting.tab_list) {
    Msg("Tab: %s", Manager::Shared().localization.string(tab->name).c_str());
    for (std::shared_ptr<Setting::Group> group: tab->group_list) {
      Msg(" Group: %s", Manager::Shared().localization.string(group->name).c_str());
      for (std::shared_ptr<Setting::Item> item: group->item_list) {
        switch (item->type) {
        case Setting::Item::Type::Keybutton: {
          std::shared_ptr<Setting::Keybutton> type_item = std::static_pointer_cast<Setting::Keybutton>(item);
          Msg("  Keybutton: %s %d",
          Manager::Shared().localization.string(type_item->name).c_str(),
          type_item->value);
        } break;
        case Setting::Item::Type::Checkbox: {
          std::shared_ptr<Setting::Checkbox> type_item = std::static_pointer_cast<Setting::Checkbox>(item);
          Msg("  Checkbox: %s %s", 
          Manager::Shared().localization.string(type_item->name).c_str(),
          type_item->value ? "true" : "false");
        } break;
        case Setting::Item::Type::Slideint: {
          std::shared_ptr<Setting::Slideint> type_item = std::static_pointer_cast<Setting::Slideint>(item);
          Msg("  Slideint: %s %d", 
          Manager::Shared().localization.string(type_item->name).c_str(),
          type_item->value);
        } break;
        case Setting::Item::Type::Slidefloat: {
          std::shared_ptr<Setting::Slidefloat> type_item = std::static_pointer_cast<Setting::Slidefloat>(item);
          Msg("  Slidefloat: %s %.2f", 
          Manager::Shared().localization.string(type_item->name).c_str(),
          type_item->value);
        } break;
        default:
          break;
        }
      }
    }
  }

  return 1;
}