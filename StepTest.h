// StepTest.h

#ifndef STEP_TEST_H
#define STEP_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Step.h"

/* 
 * A test case to exercise
 * the different steps for processing a human move.
 *
 */

class StepTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( StepTest );
  CPPUNIT_TEST( testStep1 );
  CPPUNIT_TEST( testStep2 );
  CPPUNIT_TEST( testStep3 );
  CPPUNIT_TEST( testStep4 );
  CPPUNIT_TEST( testStep5a );
  CPPUNIT_TEST( testStep5b );
  CPPUNIT_TEST( testLastStepA );
  CPPUNIT_TEST( testLastStepB );
  CPPUNIT_TEST_SUITE_END();

public:

  StepTest() : human_m(), 
               computer_m(), 
               game_m(&human_m, &computer_m),
               step_m_p(NULL)
               {};

  ~StepTest()
  {
    tearDown();
  }

  void setUp();
  void tearDown();

protected:
  void testStep1();
  void testStep2();
  void testStep3();
  void testStep4();
  void testStep5a();
  void testStep5b();
  void testLastStepA();
  void testLastStepB();

private:
  Player human_m;
  Player computer_m;

  Game game_m;

  Step* step_m_p;
};

#endif // STEP_TEST_H
