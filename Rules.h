#ifndef RULES_H
#define RULES_H

/* 
 * Generates declarations for Rule classes.
 *
 */

#include "Rule.h"

using namespace std;

#define DECLARE_RULE(X)                          \
class X : public Rule                            \
{                                                \
public:                                          \
  X(Rule* next_p) : Rule(next_p) {};             \
  virtual ~X() {};                               \
                                                 \
  virtual int getMove(const Player* human_p,     \
                      const Player* computer_p,  \
                      const Game*   game_p);     \
};

DECLARE_RULE(Rule1)
DECLARE_RULE(Rule2)
DECLARE_RULE(Rule3)
DECLARE_RULE(Rule4)
DECLARE_RULE(Rule5)
DECLARE_RULE(Rule6)
DECLARE_RULE(Rule7)
DECLARE_RULE(Rule8)
DECLARE_RULE(LastRule)

#endif // RULES_H
