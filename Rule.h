#ifndef RULE_H
#define RULE_H

/* 
 * Virtual base class for rules to determine computer move. Based
 * on Chain of Responsibility pattern.
 *
 */

#include "Player.h"
#include "Game.h"

using namespace std;

class Rule
{

public:
  Rule(Rule* next_p) : next_m_p(next_p) {};
  virtual ~Rule() 
  { 
    if ( NULL != next_m_p )
      delete next_m_p;
  };

  virtual int getMove(const Player* human_p, 
                      const Player* computer_p,
                      const Game*   game_p) = 0;

protected:

  Rule* next_m_p;
};


#endif // RULE_H
