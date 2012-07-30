// file PlayerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "PlayerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( PlayerTest );

//---------------------------------------------------------------

void PlayerTest::setUp()
{
  game_m.reset(&human_m, &computer_m);
}

//---------------------------------------------------------------

void PlayerTest::tearDown()
{
}

//---------------------------------------------------------------

void PlayerTest::checkMoves()
{
  // For this test, we want to make some moves for the human
  // and computer and then send a set of moves to the players
  // to find if they are present

  for ( int i = 0; i < 4; i++ )
    game_m.addMove(i, &human_m);

  IntSet moves;
  moves.insert(1);
  moves.insert(3);
  moves.insert(6);

  CPPUNIT_ASSERT(!human_m.hasMoved(moves));

  game_m.addMove(6, &human_m);

  CPPUNIT_ASSERT(human_m.hasMoved(moves));

  CPPUNIT_ASSERT(!computer_m.hasMoved(moves));

  // Reset the game and add some computer moves

  game_m.reset(&human_m, &computer_m);

  for ( int i = 3; i < 7; i++ )
    game_m.addMove(i, &computer_m);

  CPPUNIT_ASSERT(!computer_m.hasMoved(moves));

  game_m.addMove(1, &computer_m);

  CPPUNIT_ASSERT(computer_m.hasMoved(moves));
}

//---------------------------------------------------------------

void PlayerTest::checkMove()
{
  for ( int move = 0; move < 9; move++ )
  {

    game_m.addMove(move, &human_m);
    CPPUNIT_ASSERT( human_m.hasMoved(move) );

    game_m.reset(&human_m, &computer_m);
  }
}

//---------------------------------------------------------------
