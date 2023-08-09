#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_module_core) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Module module;
  module.load("modules/core/module.json");

  BOOST_CHECK_EQUAL(module["name"], "core");
  BOOST_CHECK_EQUAL(module["version"], "1.0.0");
}

BOOST_AUTO_TEST_CASE(tkgm_test_module_control) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Module module;
  module.load("modules/control/module.json");

  BOOST_CHECK_EQUAL(module["name"], "control");
  BOOST_CHECK_EQUAL(module["version"], "1.0.0");
}
