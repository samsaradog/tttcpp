// file RuleFactory.cpp

#include "RuleFactory.h"
#include "Rules.h"

//---------------------------------------------------------------

Rule* RuleFactory::getRules()
{
  return new Rule1(
           new Rule2(
             new Rule3(
               new Rule4(
                 new Rule5( 
                   new Rule6(
                     new Rule7(
                       new Rule8(
                         new LastRule(NULL)
                                )
                              )
                            )
                          )
                        )
                      )
                    )
                  );
}


//---------------------------------------------------------------
