#include <tkgm/tkgm_setting.hpp>

namespace tkht
{
namespace tkgm
{
Setting::Item::Item(std::vector<std::string> key_link, nlohmann::json json):
  JSON(std::string()), 
  key_link(key_link) {
  merge_patch(json);
  name = json["name"];
}

Setting::Group::Group(std::vector<std::string> key_link, nlohmann::json json):
  JSON(std::string()) {
  merge_patch(json);
  name = json["name"];

  for (const auto& item : json["content"].items()) {
    std::vector<std::string> key_link_copy(key_link);
    key_link_copy.push_back(item.key());
    std::string type = item.value()["type"];
    if (type == "keybutton") item_list.push_back(std::make_shared<Keybutton>(key_link_copy, item.value()));
    if (type == "checkbox") item_list.push_back(std::make_shared<Checkbox>(key_link_copy, item.value()));
    if (type == "slideint") item_list.push_back(std::make_shared<Slideint>(key_link_copy, item.value()));
    if (type == "slidefloat") item_list.push_back(std::make_shared<Slidefloat>(key_link_copy, item.value()));
  }
}

Setting::Tab::Tab(std::vector<std::string> key_link, nlohmann::json json):
  JSON(std::string()) {
  merge_patch(json);
  name = json["name"];
  
  for (const auto& group : json["content"].items()) {
    std::vector<std::string> key_link_copy(key_link);
    key_link_copy.push_back(group.key());
    group_list.push_back(std::make_shared<Group>(key_link_copy, group.value()));
  }
}

void Setting::clear() {
  JSON::clear();
  tab_list.clear();
}

void Setting::merge(std::vector<std::string> key_link, Setting new_setting) {
  for (const auto& tab : new_setting["root"].items()) {
    std::vector<std::string> key_link_copy(key_link);
    key_link_copy.push_back(tab.key());
    tab_list.push_back(std::make_shared<Tab>(key_link_copy, tab.value()));
  }
}

}
}
