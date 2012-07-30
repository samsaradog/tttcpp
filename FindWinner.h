
#ifndef FIND_WINNER_H
#define FIND_WINNER_H

/* 
 * Class to test whether either the human or computer has won the game.
 * Also finds whether a single move will win the game for either the
 * computer or the human.
 *
 */

#include "Game.h"
#include "Player.h"

#include <set>
#include <vector>

typedef set<IntSet> IntSetSet;
typedef vector<IntSetSet> IntSetSetVector;

class FindWinner
{

public:
  FindWinner();
  ~FindWinner();

  bool hasWinner(const Player* player_p) const;

  // returns 0 if there is no winning move
  int winningMove(const Game* game_p, const Player* player_p) const;

private:
  IntSetSet winningMoves_m;
  IntSetSetVector blockedMoves_m;

  void buildWinningMovesSet();
  void buildBlockedMovesVector();
};

#endif // FIND_WINNER_H
