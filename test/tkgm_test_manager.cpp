#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_manager) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Manager::Shared().load();

  std::shared_ptr<Sequlist> sequlist = Manager::Shared().sequlist;

  BOOST_CHECK_EQUAL(sequlist->at(0), "core");
  BOOST_CHECK_EQUAL(sequlist->at(1), "control");

  Manager::Shared().merge();

  std::shared_ptr<Localization> localization = Manager::Shared().localization;

  localization->check("Chinese");
  BOOST_CHECK_EQUAL(localization->string("tab_core"), "核心");
  BOOST_CHECK_EQUAL(localization->string("tab_control"), "控制");
  BOOST_CHECK_EQUAL(localization->string("group_core"), "核心");
  BOOST_CHECK_EQUAL(localization->string("group_control"), "控制");
  BOOST_CHECK_EQUAL(localization->string("setting_check"), "选择");
  BOOST_CHECK_EQUAL(localization->string("setting_hp"), "生命值");
  BOOST_CHECK_EQUAL(localization->string("setting_mp"), "魔法值");
  BOOST_CHECK_EQUAL(localization->string("setting_left"), "左");
  BOOST_CHECK_EQUAL(localization->string("setting_right"), "右");
  BOOST_CHECK_EQUAL(localization->string("setting_up"), "上");
  BOOST_CHECK_EQUAL(localization->string("setting_down"), "下");
  BOOST_CHECK_EQUAL(localization->string("setting_jump"), "跳");

  localization->check("English");
  BOOST_CHECK_EQUAL(localization->string("tab_core"), "Core");
  BOOST_CHECK_EQUAL(localization->string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization->string("group_core"), "Core");
  BOOST_CHECK_EQUAL(localization->string("group_control"), "Control");
  BOOST_CHECK_EQUAL(localization->string("setting_check"), "Check");
  BOOST_CHECK_EQUAL(localization->string("setting_hp"), "HP");
  BOOST_CHECK_EQUAL(localization->string("setting_mp"), "MP");
  BOOST_CHECK_EQUAL(localization->string("setting_left"), "Left");
  BOOST_CHECK_EQUAL(localization->string("setting_right"), "Right");
  BOOST_CHECK_EQUAL(localization->string("setting_up"), "Up");
  BOOST_CHECK_EQUAL(localization->string("setting_down"), "Down");
  BOOST_CHECK_EQUAL(localization->string("setting_jump"), "Jump");
  
  localization->check("Japanese");
  BOOST_CHECK_EQUAL(localization->string("tab_core"), "Core");
  BOOST_CHECK_EQUAL(localization->string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization->string("group_core"), "Core");
  BOOST_CHECK_EQUAL(localization->string("group_control"), "Control");
  BOOST_CHECK_EQUAL(localization->string("setting_check"), "Check");
  BOOST_CHECK_EQUAL(localization->string("setting_hp"), "HP");
  BOOST_CHECK_EQUAL(localization->string("setting_mp"), "MP");
  BOOST_CHECK_EQUAL(localization->string("setting_left"), "Left");
  BOOST_CHECK_EQUAL(localization->string("setting_right"), "Right");
  BOOST_CHECK_EQUAL(localization->string("setting_up"), "Up");
  BOOST_CHECK_EQUAL(localization->string("setting_down"), "Down");
  BOOST_CHECK_EQUAL(localization->string("setting_jump"), "Jump");

  std::shared_ptr<Setting> setting = Manager::Shared().setting;
  std::shared_ptr<Setting::Item> item;
  item = setting->tab_list[0]->group_list[0]->item_list[0];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_check");
  BOOST_CHECK_EQUAL(item->at("value"), 1);
  item = setting->tab_list[0]->group_list[0]->item_list[1];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_hp");
  BOOST_CHECK_EQUAL(item->at("min"), 0);
  BOOST_CHECK_EQUAL(item->at("max"), 100);
  BOOST_CHECK_EQUAL(item->at("value"), 100);
  item = setting->tab_list[0]->group_list[0]->item_list[2];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_mp");
  BOOST_CHECK_EQUAL(item->at("min"), 0.0);
  BOOST_CHECK_EQUAL(item->at("max"), 100.0);
  BOOST_CHECK_EQUAL(item->at("value"), 100.0);
  item = setting->tab_list[1]->group_list[0]->item_list[0];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_left");
  BOOST_CHECK_EQUAL(item->at("value"), 513);
  item = setting->tab_list[1]->group_list[0]->item_list[1];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_right");
  BOOST_CHECK_EQUAL(item->at("value"), 514);
  item = setting->tab_list[1]->group_list[0]->item_list[2];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_up");
  BOOST_CHECK_EQUAL(item->at("value"), 515);
  item = setting->tab_list[1]->group_list[0]->item_list[3];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_down");
  BOOST_CHECK_EQUAL(item->at("value"), 516);
  item = setting->tab_list[1]->group_list[1]->item_list[0];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_jump");
  BOOST_CHECK_EQUAL(item->at("value"), 525);
}
