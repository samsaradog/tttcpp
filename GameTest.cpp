// file GameTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "GameTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( GameTest );

//---------------------------------------------------------------

void GameTest::setUp()
{
  human_m_p    = new Player();
  computer_m_p = new Player();

  game_m_p     = new Game(human_m_p, computer_m_p);
}

//---------------------------------------------------------------

void GameTest::tearDown()
{
  if ( NULL != game_m_p )
  {
    delete game_m_p;
    game_m_p = NULL;
  }
  if ( NULL != human_m_p )
  {
    delete human_m_p;
    human_m_p = NULL;
  }
  if ( NULL != computer_m_p )
  {
    delete computer_m_p;
    computer_m_p = NULL;
  }
}

//---------------------------------------------------------------

void GameTest::addMoves()
{
  CPPUNIT_ASSERT_NO_THROW(game_m_p->addMove(1, human_m_p));

  CPPUNIT_ASSERT_THROW(game_m_p->addMove(1, human_m_p), invalid_argument);
  CPPUNIT_ASSERT_THROW(game_m_p->addMove(1, computer_m_p), invalid_argument);

  CPPUNIT_ASSERT_NO_THROW(game_m_p->addMove(2, computer_m_p));

  // Try some moves not on the grid
  CPPUNIT_ASSERT_THROW(game_m_p->addMove(-1, computer_m_p), invalid_argument);
  CPPUNIT_ASSERT_THROW(game_m_p->addMove(10, computer_m_p), invalid_argument);

  // Reset the game and try adding the same move as above
  CPPUNIT_ASSERT_NO_THROW(game_m_p->reset(human_m_p, computer_m_p));
  CPPUNIT_ASSERT_NO_THROW(game_m_p->addMove(1, human_m_p));
}

//---------------------------------------------------------------

void GameTest::isMoveAvailable(void)
{
  CPPUNIT_ASSERT(game_m_p->moveAvailable());

  for ( int i = 0; i < 8; i++ )
    game_m_p->addMove(i, human_m_p);

  CPPUNIT_ASSERT(game_m_p->moveAvailable());
  CPPUNIT_ASSERT(game_m_p->moveAvailable(8));

  game_m_p->addMove(8, computer_m_p);

  CPPUNIT_ASSERT(!game_m_p->moveAvailable());

}

//---------------------------------------------------------------

void GameTest::availableMoves(void)
{
  for ( int i = 0; i < 9; i += 2 )
    game_m_p->addMove(i, human_m_p);

  IntSet a_set = game_m_p->getAvailable();

  IntSet::const_iterator it = a_set.begin();

  int move = 1;

  while ( a_set.end() != it )
  {
    CPPUNIT_ASSERT( move == *it );
    move += 2;
    it++;
  }
}

//---------------------------------------------------------------
