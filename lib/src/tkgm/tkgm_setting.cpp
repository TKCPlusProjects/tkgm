#include <tkgm/tkgm_setting.hpp>

namespace tkht
{
namespace tkgm
{
Setting::Item::Item(nlohmann::json json):
  name(json["name"]),
  json_ptr(std::make_shared<nlohmann::json>(json)) {
}

Setting::Group::Group(nlohmann::json json):
  name(json["name"]) {
  for (const auto& item : json["content"].items()) {
    std::string type = item.value()["type"];
    if (type == "keybutton") item_list.push_back(std::make_shared<Keybutton>(item.value()));
    if (type == "checkbox") item_list.push_back(std::make_shared<Checkbox>(item.value()));
    if (type == "slideint") item_list.push_back(std::make_shared<Slideint>(item.value()));
    if (type == "slidefloat") item_list.push_back(std::make_shared<Slidefloat>(item.value()));
  }
}

Setting::Tab::Tab(nlohmann::json json):
  name(json["name"]) {
  for (const auto& group : json["content"].items()) {
    group_list.push_back(std::make_shared<Group>(group.value()));
  }
}

void Setting::Setting::merge(Setting new_setting) {
  for (const auto& tab : new_setting["root"].items()) {
    tab_list.push_back(std::make_shared<Tab>(tab.value()));
  }
}

}
}
