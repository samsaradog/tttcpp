// ViewTest.h

#ifndef VIEWTEST_H
#define VIEWTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "View.h"

/* 
 * A test case to exercise
 * features of the View Class
 *
 */

class ViewTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( ViewTest );
  CPPUNIT_TEST( showEmpty );
  CPPUNIT_TEST( showOneMove );
  CPPUNIT_TEST_SUITE_END();

public:

  ViewTest() : human_m(), 
               computer_m(), 
               game_m(&human_m, &computer_m),
               view_m(),
               result_m(""),
               mapper_m() {};

  ~ViewTest()
  {
    tearDown();
  }

  void setUp();
  void tearDown();

protected:
  void showEmpty();
  void showOneMove();

private:
  Player human_m;
  Player computer_m;

  Game game_m;

  View view_m;

  string result_m;

  Mapper mapper_m;
};

#endif // VIEWTEST_H
