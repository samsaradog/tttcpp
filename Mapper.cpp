// file Mapper.cpp

#include <cppunit/config/SourcePrefix.h>
#include "Mapper.h"

//---------------------------------------------------------------

Mapper::Mapper()
{
  humanGrid[0] = 1;
  humanGrid[1] = 2;
  humanGrid[2] = 3;
  humanGrid[3] = 6;
  humanGrid[4] = 9;
  humanGrid[5] = 8;
  humanGrid[6] = 7;
  humanGrid[7] = 4;
  humanGrid[8] = 5;

  computerGrid[0] = 666;
  computerGrid[1] = 0;
  computerGrid[2] = 1;
  computerGrid[3] = 2;
  computerGrid[4] = 7;
  computerGrid[5] = 8;
  computerGrid[6] = 3;
  computerGrid[7] = 6;
  computerGrid[8] = 5;
  computerGrid[9] = 4;
}

//---------------------------------------------------------------

Mapper::~Mapper()
{
}

//---------------------------------------------------------------

int Mapper::computerToHuman(int computerPosition) throw (invalid_argument)
{
  if ( ( 0 > computerPosition ) || ( 9 <= computerPosition ) )
    throw invalid_argument("computerToHuman value passed in is out of range");

  return humanGrid[computerPosition];
}

//---------------------------------------------------------------

int Mapper::humanToComputer(int humanPosition) throw (invalid_argument)
{
  if ( ( 0 >= humanPosition ) || ( 10 <= humanPosition ) )
    throw invalid_argument("humanToComputer value passed in is out of range");

  return computerGrid[humanPosition];
}

//---------------------------------------------------------------

