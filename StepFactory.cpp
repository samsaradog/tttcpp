// file StepFactory.cpp

#include "StepFactory.h"
#include "Steps.h"

//---------------------------------------------------------------

Step* StepFactory::getSteps()
{
  return new Step1(
           new Step2(
             new Step3(
               new Step4(
                 new Step5(
                   new LastStep()
                          )
                        )
                      )
                    )
                  );
}



//---------------------------------------------------------------
