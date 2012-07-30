// file MapTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "MapTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( MapTest );

//---------------------------------------------------------------

void MapTest::setUp()
{
}

//---------------------------------------------------------------

void MapTest::tearDown()
{
}

//---------------------------------------------------------------

void MapTest::computerToHuman()
{
  CPPUNIT_ASSERT_EQUAL(1, mapper_m.computerToHuman(0));
  CPPUNIT_ASSERT_EQUAL(2, mapper_m.computerToHuman(1));
  CPPUNIT_ASSERT_EQUAL(3, mapper_m.computerToHuman(2));
  CPPUNIT_ASSERT_EQUAL(6, mapper_m.computerToHuman(3));
  CPPUNIT_ASSERT_EQUAL(9, mapper_m.computerToHuman(4));
  CPPUNIT_ASSERT_EQUAL(8, mapper_m.computerToHuman(5));
  CPPUNIT_ASSERT_EQUAL(7, mapper_m.computerToHuman(6));
  CPPUNIT_ASSERT_EQUAL(4, mapper_m.computerToHuman(7));
  CPPUNIT_ASSERT_EQUAL(5, mapper_m.computerToHuman(8));

  CPPUNIT_ASSERT_THROW(mapper_m.computerToHuman(-1), invalid_argument);
  CPPUNIT_ASSERT_THROW(mapper_m.computerToHuman(9), invalid_argument);
}

//---------------------------------------------------------------

void MapTest::humanToComputer()
{
  CPPUNIT_ASSERT_EQUAL(0, mapper_m.humanToComputer(1));
  CPPUNIT_ASSERT_EQUAL(1, mapper_m.humanToComputer(2));
  CPPUNIT_ASSERT_EQUAL(2, mapper_m.humanToComputer(3));
  CPPUNIT_ASSERT_EQUAL(7, mapper_m.humanToComputer(4));
  CPPUNIT_ASSERT_EQUAL(8, mapper_m.humanToComputer(5));
  CPPUNIT_ASSERT_EQUAL(3, mapper_m.humanToComputer(6));
  CPPUNIT_ASSERT_EQUAL(6, mapper_m.humanToComputer(7));
  CPPUNIT_ASSERT_EQUAL(5, mapper_m.humanToComputer(8));
  CPPUNIT_ASSERT_EQUAL(4, mapper_m.humanToComputer(9));

  CPPUNIT_ASSERT_THROW(mapper_m.humanToComputer(0), invalid_argument);
  CPPUNIT_ASSERT_THROW(mapper_m.humanToComputer(10), invalid_argument);
}

//---------------------------------------------------------------

