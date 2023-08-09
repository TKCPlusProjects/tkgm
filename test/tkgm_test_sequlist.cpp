#include <boost/test/unit_test.hpp>

#include <tkgm/tkgm.hpp>

BOOST_AUTO_TEST_CASE(tkgm_test_sequlist) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Sequlist sequlist;
  sequlist.load("modules/sequlist.json");

  BOOST_CHECK_EQUAL(sequlist[0], "core");
}

BOOST_AUTO_TEST_CASE(tkgm_test_sequlist_edit) {
  using namespace tkht;
  using namespace tkht::tkgm;

  Debug = true;

  Sequlist sequlist;
  sequlist.load("modules/sequlist.json");

  sequlist.push_back("control");

  BOOST_CHECK_EQUAL(sequlist[0], "core");
  BOOST_CHECK_EQUAL(sequlist[1], "control");

  sequlist.move(1, 0);

  BOOST_CHECK_EQUAL(sequlist[0], "control");
  BOOST_CHECK_EQUAL(sequlist[1], "core");
}
