#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_setting_core) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  std::shared_ptr<Setting> setting = std::make_shared<Setting>();

  Setting setting_core;
  setting_core.load("modules/core/setting.json");

  setting->merge({"core"}, setting_core);

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
}

BOOST_AUTO_TEST_CASE(tkgm_test_setting_control) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  std::shared_ptr<Setting> setting = std::make_shared<Setting>();

  Setting setting_control;
  setting_control.load("modules/control/setting.json");

  setting->merge({"core"}, setting_control);

  std::shared_ptr<Setting::Item> item;
  item = setting->tab_list[0]->group_list[0]->item_list[0];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_jump");
  BOOST_CHECK_EQUAL(item->at("value"), 525);
}

BOOST_AUTO_TEST_CASE(tkgm_test_setting_combine) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  std::shared_ptr<Setting> setting = std::make_shared<Setting>();
  Setting setting_core;
  setting_core.load("modules/core/setting.json");
  Setting setting_control;
  setting_control.load("modules/control/setting.json");

  setting->merge({"core"}, setting_core);
  setting->merge({"control"}, setting_control);

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
  item = setting->tab_list[2]->group_list[0]->item_list[0];
  BOOST_CHECK_EQUAL(item->at("name"), "setting_jump");
  BOOST_CHECK_EQUAL(item->at("value"), 525);
}