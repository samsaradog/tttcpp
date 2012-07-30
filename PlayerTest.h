
#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "Player.h"
#include "Game.h"

/* 
 * A test case to exercise
 * features of the Player Class
 *
 */

class PlayerTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( PlayerTest );
  CPPUNIT_TEST( checkMoves );
  CPPUNIT_TEST( checkMove );
  CPPUNIT_TEST_SUITE_END();

public:
  PlayerTest() : human_m(), computer_m(), game_m(&human_m, &computer_m)  {};
  ~PlayerTest()
  {
    tearDown();
  }

  void setUp();
  void tearDown();

protected:
  void checkMoves();
  void checkMove();

private:
  Player human_m;
  Player computer_m;
  Game   game_m;
};


#endif // PLAYERTEST_H
