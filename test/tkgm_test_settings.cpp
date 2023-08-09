#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_setting_core) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Setting setting;
  setting.load("modules/core/setting.json");

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
}

BOOST_AUTO_TEST_CASE(tkgm_test_setting_control) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Setting setting;
  setting.load("modules/control/setting.json");

  nlohmann::json data;
  data = setting["tab_control"]["group_control"][0];
  BOOST_CHECK_EQUAL(data["name"], "setting_jump");
  BOOST_CHECK_EQUAL(data["value"], 525);
}

BOOST_AUTO_TEST_CASE(tkgm_test_setting_combine) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Setting setting;
  Setting setting_core;
  setting_core.load("modules/core/setting.json");
  Setting setting_control;
  setting_control.load("modules/control/setting.json");

  setting.merge_patch(setting_core);
  setting.merge_patch(setting_control);

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