#ifndef PLAYER_H
#define PLAYER_H

/* 
 * Class to model a player. Will let Game be a friend.
 *
 */

#include <stdexcept>
#include <set>

using namespace std;

typedef set<int> IntSet;

class Game;	// Forward declaration to allow Game to be a friend.

class Player : private IntSet
{

public:
  Player();
  ~Player();

  bool hasMoved(const IntSet& moves) const;

  bool hasMoved(const int move) const;

  friend class Game;
};


#endif // PLAYER_H
