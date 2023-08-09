#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_manager) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Manager::Shared().load();

  BOOST_CHECK_EQUAL(Manager::Shared().sequlist[0], "core");
  BOOST_CHECK_EQUAL(Manager::Shared().sequlist[1], "control");

  Manager::Shared().merge();

  Localization localization = Manager::Shared().localization;

  localization.check("Chinese");
  BOOST_CHECK_EQUAL(localization.string("tab_core"), "核心");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "控制");
  BOOST_CHECK_EQUAL(localization.string("group_core"), "核心");
  BOOST_CHECK_EQUAL(localization.string("group_control"), "控制");
  BOOST_CHECK_EQUAL(localization.string("setting_check"), "选择");
  BOOST_CHECK_EQUAL(localization.string("setting_hp"), "生命值");
  BOOST_CHECK_EQUAL(localization.string("setting_mp"), "魔法值");
  BOOST_CHECK_EQUAL(localization.string("setting_left"), "左");
  BOOST_CHECK_EQUAL(localization.string("setting_right"), "右");
  BOOST_CHECK_EQUAL(localization.string("setting_up"), "上");
  BOOST_CHECK_EQUAL(localization.string("setting_down"), "下");
  BOOST_CHECK_EQUAL(localization.string("setting_jump"), "跳");

  localization.check("English");
  BOOST_CHECK_EQUAL(localization.string("tab_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("group_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("group_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("setting_check"), "Check");
  BOOST_CHECK_EQUAL(localization.string("setting_hp"), "HP");
  BOOST_CHECK_EQUAL(localization.string("setting_mp"), "MP");
  BOOST_CHECK_EQUAL(localization.string("setting_left"), "Left");
  BOOST_CHECK_EQUAL(localization.string("setting_right"), "Right");
  BOOST_CHECK_EQUAL(localization.string("setting_up"), "Up");
  BOOST_CHECK_EQUAL(localization.string("setting_down"), "Down");
  BOOST_CHECK_EQUAL(localization.string("setting_jump"), "Jump");
  
  localization.check("Japanese");
  BOOST_CHECK_EQUAL(localization.string("tab_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("group_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("group_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("setting_check"), "Check");
  BOOST_CHECK_EQUAL(localization.string("setting_hp"), "HP");
  BOOST_CHECK_EQUAL(localization.string("setting_mp"), "MP");
  BOOST_CHECK_EQUAL(localization.string("setting_left"), "Left");
  BOOST_CHECK_EQUAL(localization.string("setting_right"), "Right");
  BOOST_CHECK_EQUAL(localization.string("setting_up"), "Up");
  BOOST_CHECK_EQUAL(localization.string("setting_down"), "Down");
  BOOST_CHECK_EQUAL(localization.string("setting_jump"), "Jump");

  Setting setting = Manager::Shared().setting;
  nlohmann::json data;
  data = setting["tab_core"]["group_core"][0];
  BOOST_CHECK_EQUAL(data["name"], "setting_check");
  BOOST_CHECK_EQUAL(data["value"], 1);
  data = setting["tab_core"]["group_core"][1];
  BOOST_CHECK_EQUAL(data["name"], "setting_hp");
  BOOST_CHECK_EQUAL(data["min"], 0);
  BOOST_CHECK_EQUAL(data["max"], 100);
  BOOST_CHECK_EQUAL(data["value"], 100);
  data = setting["tab_core"]["group_core"][2];
  BOOST_CHECK_EQUAL(data["name"], "setting_mp");
  BOOST_CHECK_EQUAL(data["min"], 0.0);
  BOOST_CHECK_EQUAL(data["max"], 100.0);
  BOOST_CHECK_EQUAL(data["value"], 100.0);
  data = setting["tab_control"]["group_core"][0];
  BOOST_CHECK_EQUAL(data["name"], "setting_left");
  BOOST_CHECK_EQUAL(data["value"], 513);
  data = setting["tab_control"]["group_core"][1];
  BOOST_CHECK_EQUAL(data["name"], "setting_right");
  BOOST_CHECK_EQUAL(data["value"], 514);
  data = setting["tab_control"]["group_core"][2];
  BOOST_CHECK_EQUAL(data["name"], "setting_up");
  BOOST_CHECK_EQUAL(data["value"], 515);
  data = setting["tab_control"]["group_core"][3];
  BOOST_CHECK_EQUAL(data["name"], "setting_down");
  BOOST_CHECK_EQUAL(data["value"], 516);
  data = setting["tab_control"]["group_control"][0];
  BOOST_CHECK_EQUAL(data["name"], "setting_jump");
  BOOST_CHECK_EQUAL(data["value"], 525);
}
