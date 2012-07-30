
#ifndef FIND_WINNER_TEST_H
#define FIND_WINNER_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "FindWinner.h"

/* 
 * A test case to exercise
 * features of the FindWinner Class
 *
 */

class FindWinnerTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( FindWinnerTest );
  CPPUNIT_TEST( humanWinner );
  CPPUNIT_TEST( allHumanWinners );
  CPPUNIT_TEST( computerWinner );
  CPPUNIT_TEST( allComputerWinners );
  CPPUNIT_TEST( makeWinner );
  CPPUNIT_TEST( checkBlockedMoves );
  CPPUNIT_TEST( checkNotBlockedMoves );
  CPPUNIT_TEST_SUITE_END();

public:
  FindWinnerTest() : human_m(), computer_m(), game_m(&human_m, &computer_m) {};
  ~FindWinnerTest() {};

  void setUp();
  void tearDown();

protected:
  void humanWinner();
  void allHumanWinners();
  void computerWinner();
  void allComputerWinners();
  void makeWinner();
  void checkBlockedMoves();
  void checkNotBlockedMoves();

private:
  Player     human_m;
  Player     computer_m;

  Game       game_m;

  FindWinner finder_m;
};


#endif // FIND_WINNER_TEST_H
