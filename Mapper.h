
#ifndef MAPPER_H
#define MAPPER_H

/* 
 * Class to map the game grid represented to the human to that used
 * by the computer, and vice versa.
 * 
 * Human
 *
 *  1 | 2 | 3
 * -----------
 *  4 | 5 | 6 
 * ___________
 *  7 | 8 | 9
 *
 * Computer
 *
 *  0 | 1 | 2
 * -----------
 *  7 | 8 | 3 
 * ___________
 *  6 | 5 | 4
 *
 */

#include <stdexcept>

using namespace std;

class Mapper
{

public:
  Mapper();
  ~Mapper();

  int computerToHuman(int) throw (invalid_argument);
  int humanToComputer(int) throw (invalid_argument);

private:
  int humanGrid[9];
  int computerGrid[10];
};


#endif // MAPPER_H
