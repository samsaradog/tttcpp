#ifndef GAME_H
#define GAME_H

/* 
 * Class to model the game. Holds sets of human moves, computer
 * moves and free spaces.
 *
 */

#include <stdexcept>
#include <set>
#include "Player.h"

using namespace std;

typedef set<int> IntSet;

class Game
{

public:
  Game(Player* human_p, Player* computer_p);
  ~Game();

  void reset(Player* human_p, Player* computer_p) throw();

  void addMove(int move, Player* player_p) throw (invalid_argument);

  // Returns whether any move is available
  bool moveAvailable() const;

  // Returns whether the given move is available
  bool moveAvailable(int) const;

  // Returns a copy of the set of available moves
  const IntSet& getAvailable() const;

private:

  IntSet availableMoves_m;

  // Throws an exception if the move is not available
  void checkAvailableMoves(int move) throw (invalid_argument);
};


#endif // GAME_H
