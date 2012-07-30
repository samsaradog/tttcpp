// RuleTest.h

#ifndef RULETEST_H
#define RULETEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Rule.h"

/* 
 * A test case to exercise
 * the different rules for determining a computer move.
 *
 */

class RuleTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( RuleTest );
  CPPUNIT_TEST( testRule1 );
  CPPUNIT_TEST( testRule2 );
  CPPUNIT_TEST( testRule3 );
  CPPUNIT_TEST( testRule4Odd );
  CPPUNIT_TEST( testRule4Even );
  CPPUNIT_TEST( testRule5a );
  CPPUNIT_TEST( testRule5b );
  CPPUNIT_TEST( testRule6a );
  CPPUNIT_TEST( testRule6b );
  CPPUNIT_TEST( testRule6c );
  CPPUNIT_TEST( testRule6d );
  CPPUNIT_TEST( testRule6e );
  CPPUNIT_TEST( testRule7a );
  CPPUNIT_TEST( testRule7b );
  CPPUNIT_TEST( testRule7c );
  CPPUNIT_TEST( testRule7d );
  CPPUNIT_TEST( testRule8a );
  CPPUNIT_TEST( testRule8b );
  CPPUNIT_TEST( testRule8c );
  CPPUNIT_TEST( testRule8d );
  CPPUNIT_TEST( testLastRule );
  CPPUNIT_TEST_SUITE_END();

public:

  RuleTest() : human_m(), 
               computer_m(), 
               game_m(&human_m, &computer_m),
               rule_m_p(NULL)
               {};

  ~RuleTest()
  {
    tearDown();
  }

  void setUp();
  void tearDown();

protected:
  void testRule1();
  void testRule2();
  void testRule3();
  void testRule4Odd();
  void testRule4Even();
  void testRule5a();
  void testRule5b();
  void testRule6a();
  void testRule6b();
  void testRule6c();
  void testRule6d();
  void testRule6e();
  void testRule7a();
  void testRule7b();
  void testRule7c();
  void testRule7d();
  void testRule8a();
  void testRule8b();
  void testRule8c();
  void testRule8d();
  void testLastRule();

private:
  Player human_m;
  Player computer_m;

  Game game_m;

  Rule* rule_m_p;
};

#endif // RULETEST_H
