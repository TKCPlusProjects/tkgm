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

void Setting::Group::merge(std::shared_ptr<Group> new_group) {
  for (const auto& new_item : new_group->item_list) {
    auto it = std::find_if(item_list.begin(), item_list.end(), [&new_item](std::shared_ptr<Item> item){
      return item->name == new_item->name;
    });
    if (it == item_list.end()) {
      item_list.push_back(new_item);
    } else {
      *it = new_item;
    }
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

void Setting::Tab::merge(std::shared_ptr<Tab> new_tab) {
  for (const auto& new_group : new_tab->group_list) {
    auto it = std::find_if(group_list.begin(), group_list.end(), [&new_group](std::shared_ptr<Group> group){
      return group->name == new_group->name;
    });
    if (it == group_list.end()) {
      group_list.push_back(new_group);
    } else {
      std::shared_ptr<Group> it_group = *it;
      it_group->merge(new_group);
    }
  }
}

void Setting::clear() {
  JSON::clear();
  tab_list.clear();
}

void Setting::merge(std::vector<std::string> key_link, Setting new_setting) {
  for (const auto& tab_data : new_setting["root"].items()) {
    std::vector<std::string> key_link_copy(key_link);
    key_link_copy.push_back(tab_data.key());

    std::shared_ptr<Tab> new_tab = std::make_shared<Tab>(key_link_copy, tab_data.value());

    auto it = std::find_if(tab_list.begin(), tab_list.end(), [&new_tab](std::shared_ptr<Tab> tab){
      return tab->name == new_tab->name;
    });
    if (it == tab_list.end()) {
      tab_list.push_back(new_tab);
    } else {
      std::shared_ptr<Tab> it_tab = *it;
      it_tab->merge(new_tab);
    }
  }
}

}
}
