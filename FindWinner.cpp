// file FindWinner.cpp

#include <cppunit/config/SourcePrefix.h>
#include "FindWinner.h"

#include <algorithm>

// Array to define what sets of moves win a game

const int WINNER_ARRAY_COLS = 3;

//---------------------------------------------------------------

int winningMovesArray_m[][WINNER_ARRAY_COLS] = {
	{ 0, 1, 2 },
	{ 0, 4, 8 },
	{ 0, 6, 7 },
	{ 1, 5, 8 },
	{ 2, 3, 4 },
	{ 2, 6, 8 },
	{ 3, 7, 8 },
	{ 4, 5, 6 }  };

const int WINNER_ARRAY_ROWS = sizeof(winningMovesArray_m)/
                              (sizeof(int)*WINNER_ARRAY_COLS);

//---------------------------------------------------------------

// This gets read into a vector of IntSetSet's. The first number
// is added mostly for clarity. It will be (index+1) into the array,
// The following pairs are the moves that can produce a winning move
// if the first number is played. The 0 at the end of each line serves
// to mark where the line should stop reading.

#define BMA_END_MARKER 99

int blockedMovesArray_m[] = {
0, 1, 2, 6, 7, 8, 4, BMA_END_MARKER,
1, 5, 8, 0, 2, BMA_END_MARKER,
2, 0, 1, 6, 8, 3, 4, BMA_END_MARKER,
3, 7, 8, 2, 4, BMA_END_MARKER,
4, 2, 3, 0, 8, 5, 6, BMA_END_MARKER,
5, 1, 8, 4, 6, BMA_END_MARKER,
6, 4, 5, 2, 8, 0, 7, BMA_END_MARKER,
7, 0, 6, 3, 8, BMA_END_MARKER,
8, 0, 4, 1, 5, 2, 6, 3, 7, BMA_END_MARKER,
};

// This will come in handy for building the vector
#define FW_POSSIBLE_MOVES 9

//---------------------------------------------------------------

FindWinner::FindWinner()
{
  buildWinningMovesSet();
  buildBlockedMovesVector();
}

//---------------------------------------------------------------

FindWinner::~FindWinner()
{
}

//---------------------------------------------------------------

bool FindWinner::hasWinner(const Player* player_p) const
{
  IntSetSet::const_iterator moves_it = winningMoves_m.begin();
  bool found = false;

  while ( ( false == found ) && ( winningMoves_m.end() != moves_it ) )
  {
    found = player_p->hasMoved(*moves_it);
    moves_it++;
  }

  return found;
}

//---------------------------------------------------------------

void FindWinner::buildWinningMovesSet()
{
  winningMoves_m.clear();
  IntSet moves;

  moves.clear();

  for ( int row = 0; row < WINNER_ARRAY_ROWS; row++ )
  {
    for ( int col = 0; col < WINNER_ARRAY_COLS; col++ )
    {
      moves.insert(winningMovesArray_m[row][col]);
    }
   
    winningMoves_m.insert(moves);
    moves.clear();
  }

}

//---------------------------------------------------------------

void FindWinner::buildBlockedMovesVector()
{
  // Clear out the vector
  blockedMoves_m.clear();

  // Create a set of int sets to load into the vector
  IntSetSet setOfSets;

  // Create a set of ints to load into the set of int sets
  IntSet currentSet;

  int* array_p = blockedMovesArray_m;

  int move1 = 0;
  int move2 = 0;

  for ( int i = 0; i < FW_POSSIBLE_MOVES; i++ )
  {
    // Read the first number out of the set and move the pointer
    if ( i != *array_p )
      throw runtime_error("Problem in blockedMovesArray reader");

    array_p++;

    // While the value referred to by the pointer isn't 0, get two 
    // numbers, put them in a set, then put that set into the current 
    // set of sets, and clear that set.

    while ( BMA_END_MARKER != *array_p )
    {
      move1 = *array_p++;
      move2 = *array_p++;

      currentSet.insert(move1);
      currentSet.insert(move2);

      setOfSets.insert(currentSet);

      currentSet.clear();
    }

    // When the pointer is at a 0, add the set of sets to the
    // vector, clear the set of sets, and move the pointer

    blockedMoves_m.push_back(setOfSets);
    setOfSets.clear();

    array_p++;
  }
}

//---------------------------------------------------------------

int FindWinner::winningMove(const Game* game_p, const Player* player_p) const
{
  int returnValue = -1;

  bool found = false;

  // Since we're using position as an array index, it is the
  // the same as what we're looking for

  int position = 0;

  for ( position = 0; 
       (( false == found ) && ( FW_POSSIBLE_MOVES > position ) );
        position++ )
  { 
    // No sense looking at this move if it is not available
    if ( ! game_p->moveAvailable(position) )
      continue;

    IntSetSet currentBlockedMoves = blockedMoves_m[position];

    IntSetSet::const_iterator it = currentBlockedMoves.begin();

    while ( ( false == found ) && ( it != currentBlockedMoves.end() ) )
    {
      found = player_p->hasMoved(*it);
      it++;
    }

  } // end for positions in the vector and winning move not found

  // decrement since it was incremented on its way out of the loop

  position--;

  if ( found ) 
    returnValue = position;

  return returnValue;
}

//---------------------------------------------------------------
