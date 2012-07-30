// file StepTest.cpp

#include <iostream>

#include <cppunit/config/SourcePrefix.h>
#include "StepTest.h"
#include "StepFactory.h"

CPPUNIT_TEST_SUITE_REGISTRATION( StepTest );

//---------------------------------------------------------------

void StepTest::setUp()
{
  StepFactory the_factory;

  step_m_p = the_factory.getSteps();
}

//---------------------------------------------------------------

void StepTest::tearDown()
{
  if ( NULL != step_m_p )
  {
    delete step_m_p;
    step_m_p = NULL;
  }
}

//---------------------------------------------------------------

// This step checks for a valid user move

void StepTest::testStep1()
{
  game_m.addMove(1, &human_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(1, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == 
                 "Square 2 not available. Please choose another.\n" );

  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------

// This step says that if adding the human move means the
// human wins, announce the win and end the game.

void StepTest::testStep2()
{
  game_m.addMove(2, &human_m);
  game_m.addMove(3, &human_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(4, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "The Human has won. Congratulations!\n");

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This step says that if there is no move left after the human
// moves, declare a draw and end the game.

void StepTest::testStep3()
{
  for ( int i = 1; i < 9; i++ )
    game_m.addMove(i, &computer_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(0, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "Draw Game.\n");

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This step checks whether the computer can make a winning move.
// If so, make the move and announce the win.

void StepTest::testStep4()
{
  game_m.addMove(3, &computer_m);
  game_m.addMove(8, &computer_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(1, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "Computer Wins!\n" );

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This step is for the computer making a blocking move. This first
// version is when the blocking move is the last available, creating
// a draw

void StepTest::testStep5a()
{
  game_m.addMove(0, &computer_m);
  game_m.addMove(1, &computer_m);
  game_m.addMove(3, &computer_m);
  game_m.addMove(8, &computer_m);

  game_m.addMove(2, &human_m);
  game_m.addMove(4, &human_m);
  game_m.addMove(7, &human_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(5, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "Draw Game.\n" );

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This next case is as above, but the game can continue

void StepTest::testStep5b()
{
  game_m.addMove(3, &computer_m);
  game_m.addMove(8, &computer_m);

  game_m.addMove(2, &human_m);
  game_m.addMove(7, &human_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(6, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "" );

  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------

// This step is the last in the chain. It has the computer pick
// a square based on its rules. The first case creates a draw.

void StepTest::testLastStepA()
{
  game_m.addMove(1, &computer_m);
  game_m.addMove(4, &computer_m);
  game_m.addMove(6, &computer_m);
  game_m.addMove(8, &computer_m);

  game_m.addMove(2, &human_m);
  game_m.addMove(3, &human_m);
  game_m.addMove(5, &human_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(0, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "Draw Game.\n" );

  CPPUNIT_ASSERT( !keep_playing );
}

//---------------------------------------------------------------

// This case does not create a draw

void StepTest::testLastStepB()
{
  game_m.addMove(1, &computer_m);

  game_m.addMove(3, &human_m);

  string message("");

  bool keep_playing = 
         step_m_p->makeMove(6, message, &human_m, &computer_m, &game_m);

  CPPUNIT_ASSERT( message == "" );

  CPPUNIT_ASSERT( keep_playing );
}

//---------------------------------------------------------------
