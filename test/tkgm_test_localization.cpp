#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_localization_core) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Localization localization;
  localization.load("modules/core/localization.json");

  localization.check("Chinese");
  BOOST_CHECK_EQUAL(localization.string("tab_core"), "核心");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "控制");
  BOOST_CHECK_EQUAL(localization.string("group_core"), "核心");
  BOOST_CHECK_EQUAL(localization.string("setting_check"), "选择");
  BOOST_CHECK_EQUAL(localization.string("setting_hp"), "生命值");
  BOOST_CHECK_EQUAL(localization.string("setting_mp"), "魔法值");
  BOOST_CHECK_EQUAL(localization.string("setting_left"), "左");
  BOOST_CHECK_EQUAL(localization.string("setting_right"), "右");
  BOOST_CHECK_EQUAL(localization.string("setting_up"), "上");
  BOOST_CHECK_EQUAL(localization.string("setting_down"), "下");

  localization.check("English");
  BOOST_CHECK_EQUAL(localization.string("tab_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("group_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("setting_check"), "Check");
  BOOST_CHECK_EQUAL(localization.string("setting_hp"), "HP");
  BOOST_CHECK_EQUAL(localization.string("setting_mp"), "MP");
  BOOST_CHECK_EQUAL(localization.string("setting_left"), "Left");
  BOOST_CHECK_EQUAL(localization.string("setting_right"), "Right");
  BOOST_CHECK_EQUAL(localization.string("setting_up"), "Up");
  BOOST_CHECK_EQUAL(localization.string("setting_down"), "Down");
  
  localization.check("Japanese");
  BOOST_CHECK_EQUAL(localization.string("tab_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("group_core"), "Core");
  BOOST_CHECK_EQUAL(localization.string("setting_check"), "Check");
  BOOST_CHECK_EQUAL(localization.string("setting_hp"), "HP");
  BOOST_CHECK_EQUAL(localization.string("setting_mp"), "MP");
  BOOST_CHECK_EQUAL(localization.string("setting_left"), "Left");
  BOOST_CHECK_EQUAL(localization.string("setting_right"), "Right");
  BOOST_CHECK_EQUAL(localization.string("setting_up"), "Up");
  BOOST_CHECK_EQUAL(localization.string("setting_down"), "Down");
}

BOOST_AUTO_TEST_CASE(tkgm_test_localization_control) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Localization localization;
  localization.load("modules/control/localization.json");

  localization.check("Chinese");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "控制");
  BOOST_CHECK_EQUAL(localization.string("group_control"), "控制");
  BOOST_CHECK_EQUAL(localization.string("setting_jump"), "跳");

  localization.check("English");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("group_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("setting_jump"), "Jump");
  
  localization.check("Japanese");
  BOOST_CHECK_EQUAL(localization.string("tab_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("group_control"), "Control");
  BOOST_CHECK_EQUAL(localization.string("setting_jump"), "Jump");
}

BOOST_AUTO_TEST_CASE(tkgm_test_localization_merge) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Localization localization;
  Localization localization_core;
  localization_core.load("modules/core/localization.json");
  Localization localization_control;
  localization_control.load("modules/control/localization.json");
  
  localization.merge_patch(localization_core);
  localization.merge_patch(localization_control);

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
}