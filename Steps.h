#ifndef STEPS_H
#define STEPS_H

/* 
 * Declarations for the different steps used to
 * process a human move
 *
 */

#include "Step.h"
#include "Rule.h"

using namespace std;

#define DECLARE_STEP(X)                      \
class X : public Step                        \
{                                            \
public:                                      \
  X(Step* next_p) : Step(next_p) {};         \
  virtual ~X() {};                           \
                                             \
  virtual bool makeMove(int human_move,      \
                        string& message,     \
                        Player* human_p,     \
                        Player* computer_p,  \
                        Game* game_p);       \
};


DECLARE_STEP(Step1)
DECLARE_STEP(Step2)
DECLARE_STEP(Step3)
DECLARE_STEP(Step4)
DECLARE_STEP(Step5)

class LastStep : public Step
{                                            \
public:     
  LastStep();
  virtual ~LastStep();
                                            
  virtual bool makeMove(int human_move,      
                        string& message,   
                        Player* human_p,  
                        Player* computer_p,
                        Game* game_p);    
private:
  Rule* rule_m_p;
};


#endif // STEPS_H
