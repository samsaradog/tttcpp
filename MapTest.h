
#ifndef MAPTEST_H
#define MAPTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Mapper.h"

/* 
 * A test case that is designed to produce
 * example errors and failures
 *
 */

class MapTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( MapTest );
  CPPUNIT_TEST( computerToHuman );
  CPPUNIT_TEST( humanToComputer );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

protected:
  void computerToHuman();
  void humanToComputer();

private:
  Mapper mapper_m;
};


#endif // MAPTEST_H
