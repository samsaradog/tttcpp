// file ViewTest.cpp

#include <iostream>

#include <cppunit/config/SourcePrefix.h>
#include "ViewTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( ViewTest );

#define VT_ONE_POS 	1
#define VT_TWO_POS 	5
#define VT_THREE_POS	9
#define VT_FOUR_POS	25
#define VT_FIVE_POS	29
#define VT_SIX_POS 	33
#define VT_SEVEN_POS 	49
#define VT_EIGHT_POS 	53
#define VT_NINE_POS 	57

//---------------------------------------------------------------

void ViewTest::setUp()
{
  result_m  = " 1 | 2 | 3 \n";
  result_m += "-----------\n";
  result_m += " 4 | 5 | 6 \n";
  result_m += "-----------\n";
  result_m += " 7 | 8 | 9 \n";

  game_m.reset(&human_m, &computer_m);
}

//---------------------------------------------------------------

void ViewTest::tearDown()
{
}

//---------------------------------------------------------------

void ViewTest::showEmpty()
{
  string result = view_m.show(&human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( result_m == result );
}

//---------------------------------------------------------------

void ViewTest::showOneMove()
{
  game_m.addMove(mapper_m.humanToComputer(6), &human_m);
  game_m.addMove(mapper_m.humanToComputer(8), &computer_m);

  result_m.replace(VT_SIX_POS, 1, 1, 'X');
  result_m.replace(VT_EIGHT_POS, 1, 1, 'O');

  string result = view_m.show(&human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( result_m == result );
}

//---------------------------------------------------------------
