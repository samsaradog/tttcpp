// file FindWinnerTest.cpp

#include <cppunit/config/SourcePrefix.h>
#include "FindWinnerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( FindWinnerTest );

const int WINNING_MOVE_SIZE = 3;

int winningMoveCombinations[][WINNING_MOVE_SIZE] = {
  { 0, 1, 2 },
  { 7, 8, 3 },
  { 6, 5, 4 },
  { 0, 7, 6 },
  { 1, 8, 5 },
  { 2, 3, 4 },
  { 0, 8, 4 },
  { 2, 8, 6 },
};

const int WINNING_MOVE_COUNT = sizeof(winningMoveCombinations)/
                              (sizeof(int)*WINNING_MOVE_SIZE);


const int BLOCKED_MOVE_COMBINATION_SIZE = 2;

int blockedMoveCombinations[][BLOCKED_MOVE_COMBINATION_SIZE] = {
  { 0, 1 },
  { 0, 2 },
  { 0, 8 },
  { 0, 4 },
  { 0, 7 },
  { 0, 6 },
  { 1, 2 },
  { 1, 8 },
  { 1, 5 },
  { 2, 3 },
  { 2, 4 },
  { 2, 8 },
  { 2, 6 },
  { 3, 8 },
  { 3, 7 },
  { 3, 4 },
  { 4, 5 },
  { 4, 6 },
  { 4, 8 },
  { 5, 8 },
  { 5, 6 },
  { 6, 7 },
  { 6, 8 },
  { 7, 8 },
};

const int BLOCKED_MOVE_COUNT = sizeof(blockedMoveCombinations)/
                              (sizeof(int)*BLOCKED_MOVE_COMBINATION_SIZE);

int notBlockedMoveCombinations[][BLOCKED_MOVE_COMBINATION_SIZE] = {
  { 0, 3 },
  { 0, 5 },
  { 1, 3 },
  { 1, 4 },
  { 1, 6 },
  { 1, 7 },
  { 2, 5 },
  { 2, 7 },
  { 3, 5 },
  { 3, 6 },
  { 4, 7 },
  { 5, 7 },
};

const int NOT_BLOCKED_MOVE_COUNT = sizeof(notBlockedMoveCombinations)/
                                  (sizeof(int)*BLOCKED_MOVE_COMBINATION_SIZE);


//---------------------------------------------------------------

void FindWinnerTest::setUp()
{
  game_m.reset(&human_m, &computer_m);
}

//---------------------------------------------------------------

void FindWinnerTest::tearDown()
{
}

//---------------------------------------------------------------

void FindWinnerTest::humanWinner()
{
  game_m.addMove(0, &human_m);
  game_m.addMove(1, &human_m);
  game_m.addMove(6, &computer_m);
  game_m.addMove(8, &computer_m);
  game_m.addMove(3, &computer_m);

  CPPUNIT_ASSERT(!finder_m.hasWinner(&human_m));

  game_m.addMove(2, &human_m);

  CPPUNIT_ASSERT(finder_m.hasWinner(&human_m));
}

//---------------------------------------------------------------

void FindWinnerTest::allHumanWinners()
{
  for (int i = 0; i < WINNING_MOVE_COUNT; i++)
  {
    game_m.reset(&human_m, &computer_m);

    for ( int j = 0; j < WINNING_MOVE_SIZE; j++ )
      game_m.addMove(winningMoveCombinations[i][j], &human_m);

    CPPUNIT_ASSERT(finder_m.hasWinner(&human_m));
  }
}

//---------------------------------------------------------------

void FindWinnerTest::computerWinner()
{
  game_m.addMove(0, &computer_m);
  game_m.addMove(1, &computer_m);
  game_m.addMove(3, &human_m);
  game_m.addMove(8, &human_m);
  game_m.addMove(4, &human_m);

  CPPUNIT_ASSERT(!finder_m.hasWinner(&computer_m));

  game_m.addMove(2, &computer_m);

  CPPUNIT_ASSERT(finder_m.hasWinner(&computer_m));

}

//---------------------------------------------------------------

void FindWinnerTest::allComputerWinners()
{
  for (int i = 0; i < WINNING_MOVE_COUNT; i++)
  {
    game_m.reset(&human_m, &computer_m);

    for ( int j = 0; j < WINNING_MOVE_SIZE; j++ )
      game_m.addMove(winningMoveCombinations[i][j], &computer_m);

    CPPUNIT_ASSERT(finder_m.hasWinner(&computer_m));
  }
}

//---------------------------------------------------------------

void FindWinnerTest::makeWinner(void)
{
  game_m.addMove(0, &human_m);
  game_m.addMove(3, &human_m);

  int winningMove = finder_m.winningMove(&game_m, &human_m);

  CPPUNIT_ASSERT( 0 > winningMove );

  game_m.addMove(1, &human_m);
  game_m.addMove(2, &computer_m);

  // 3 would be a winning move for the human, but
  // since the computer is there, it should not be
  // available

  winningMove = finder_m.winningMove(&game_m, &human_m);

  CPPUNIT_ASSERT( 0 > winningMove );

  game_m.addMove(8, &human_m);
  winningMove = finder_m.winningMove(&game_m, &human_m);

  CPPUNIT_ASSERT( 0 <= winningMove );

  game_m.addMove(winningMove, &human_m);
  CPPUNIT_ASSERT(finder_m.hasWinner(&human_m));
}

//---------------------------------------------------------------

void FindWinnerTest::checkBlockedMoves()
{
  int winningMove = 0;

  for ( int i = 0; i < BLOCKED_MOVE_COUNT; i++ )
  {
    game_m.addMove(blockedMoveCombinations[i][0], &human_m);
    game_m.addMove(blockedMoveCombinations[i][1], &human_m);

    winningMove = finder_m.winningMove(&game_m, &human_m);

    CPPUNIT_ASSERT( 0 <= winningMove );

    game_m.addMove(winningMove, &human_m);
    CPPUNIT_ASSERT(finder_m.hasWinner(&human_m));

    game_m.reset(&human_m, &computer_m);
  }
}

//---------------------------------------------------------------

void FindWinnerTest::checkNotBlockedMoves()
{
  int winningMove = 0;

  for ( int i = 0; i < NOT_BLOCKED_MOVE_COUNT; i++ )
  {
    game_m.addMove(notBlockedMoveCombinations[i][0], &human_m);
    game_m.addMove(notBlockedMoveCombinations[i][1], &human_m);

    winningMove = finder_m.winningMove(&game_m, &human_m);

    CPPUNIT_ASSERT( 0 > winningMove );

    game_m.reset(&human_m, &computer_m);
  }
}

//---------------------------------------------------------------
