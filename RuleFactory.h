#ifndef RULE_FACTORY_H
#define RULE_FACTORY_H

/* 
 * Factories for creating chains of Rule objects. Based
 * on Chain of Responsibility pattern.
 *
 */

#include "Rule.h"

using namespace std;

class RuleFactory
{
public:
  RuleFactory() {};
  ~RuleFactory() {};

  Rule* getRules();
};

#endif // RULE_FACTORY_H
