#ifndef STEP_FACTORY_H
#define STEP_FACTORY_H

/* 
 * Factory for creating chains of Step objects. Based
 * on Chain of Responsibility pattern.
 *
 */

#include "Step.h"

using namespace std;

class StepFactory
{
public:
  StepFactory() {};
  ~StepFactory() {};

  Step* getSteps();
};


#endif // STEP_FACTORY_H
