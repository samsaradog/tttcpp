// file Rules.cpp

#include <cstdlib>
#include <time.h>

#include <iostream>

#include "Rules.h"

//---------------------------------------------------------------

// This rule says if there is only one square left, take it

int Rule1::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  // Seed the random sequencer for any of the following rules

  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  if ( 1 == available_moves.size() )
  {
    IntSet::const_iterator it = available_moves.begin();
    return_value = *it;
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;

}

//---------------------------------------------------------------

// This rule says that if the center square is available, take it

int Rule2::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  if ( available_moves.count(8) )
  {
    return_value = 8;
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;

}

//---------------------------------------------------------------

// This rule says that if the human has taken the 8 square 
// pick an even square

int Rule3::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  if ( ( 8 == available_moves.size() ) && ( human_p->hasMoved(8) ) )
  {
    return_value =  2 * (rand() % 4);
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;

}

//---------------------------------------------------------------

// This rule says that if the computer has the 9, and the human has
// one other, pick ((human + 3) mod 8)

int Rule4::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  if ( ( 7 == available_moves.size() ) && ( computer_p->hasMoved(8) ) )
  {
    int human_move = 1;

    while ( ( human_move < 8 ) && ( available_moves.count(human_move) ) )
      human_move++;

    return_value = ( ( human_move + 3 ) % 8 );
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;

}

//---------------------------------------------------------------

// This rule says that if the computer has the center, and the human has
// two other even, pick an odd square

int Rule5::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  if ( ( 6 == available_moves.size() ) && 
       ( computer_p->hasMoved(8)     ) &&
       ( ( ( human_p->hasMoved(0) ) && ( human_p->hasMoved(4))) ||
         ( ( human_p->hasMoved(2) ) && ( human_p->hasMoved(6)))   )
     )
  {
    return_value = (2 * (rand() % 4)) + 1;
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This rule says that if the computer has the center, and the human has
// an odd and an even, pick a square based on a formula

int Rule6::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  bool odd_found = false;
  int odd_move = 1;

  while ( ( false == odd_found ) && ( odd_move < 8 ) )
  {
    odd_found = human_p->hasMoved(odd_move);
    odd_move += 2;
  }

  odd_move -= 2;	// reset after coming out of loop

  bool even_found = false;
  int even_move = 0;

  while ( ( false == even_found ) && ( even_move < 8 ) )
  {
    even_found = human_p->hasMoved(even_move);
    even_move += 2;
  }

  even_move -= 2; // set back to how it was tested

  if ( ( 6 == available_moves.size() ) && 
       ( computer_p->hasMoved(8)     ) &&
       ( odd_found                   ) &&
       ( even_found                  )
     )
  {
    if ( odd_move == ( ( even_move + 3) % 8 ) )
      return_value = ( ( odd_move + 2 ) % 8 );

    else if ( odd_move == ( ( even_move + 5) % 8 ) )
      return_value = ( ( even_move + 3 ) % 8 );

  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// If the computer has an even square, and the human has the center
// and another even square, pick an even square one more than
// the computer's square.

int Rule7::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  bool even_found = false;
  int computer_move = 0;

  while ( ( false == even_found ) && ( computer_move < 8 ) )
  {
    even_found = computer_p->hasMoved(computer_move);
    computer_move += 2;
  }

  computer_move -= 2; // Reset the counter after ending the loop

  if ( ( 6 == available_moves.size() ) && 
       ( human_p->hasMoved(8)     ) &&
       ( even_found               ) &&
       ( human_p->hasMoved((computer_move + 4) % 8) )
     )
  {
    return_value = ( (computer_move + 2) % 8 );
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This one has the computer at the center and the human with two odd
// moves. Need to pick one greater than the greater of the two
// human moves.

int Rule8::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  int return_value = 0;

  IntSet available_moves = game_p->getAvailable();

  int odd_found = 0;
  int human_move = 1;

  while ( ( 2 > odd_found ) && ( human_move < 8 ) )
  {
    if ( human_p->hasMoved(human_move) )
      odd_found++;

    human_move += 2;
  }

  human_move -= 2; // Reset the counter after ending the loop

  if ( ( 6 == available_moves.size() ) && 
       ( computer_p->hasMoved(8)     ) &&
       ( 2 == odd_found             )
     )
  {
    return_value = (( human_move + 1 ) % 8 );
  }
  else if ( NULL != next_m_p )
  {
    return_value = next_m_p->getMove(human_p, computer_p, game_p);
  }

  return return_value;
}

//---------------------------------------------------------------

// This should be the last in the chain. It says just take any 
// available move.

int LastRule::getMove(const Player* human_p, 
                   const Player* computer_p,
                   const Game*   game_p)
{
  IntSet available_moves = game_p->getAvailable();

  int position = ( rand() % available_moves.size() );

  IntSet::const_iterator it = available_moves.begin();

  for( int i = 0; i < position; i++ ) it++;

  return *it;
}

//---------------------------------------------------------------
