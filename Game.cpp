// file Game.cpp

#include <cppunit/config/SourcePrefix.h>
#include "Game.h"

#include <algorithm>
#include <iostream>

//---------------------------------------------------------------

Game::Game(Player* human_p, Player* computer_p)
{
  reset(human_p, computer_p);
}

//---------------------------------------------------------------

Game::~Game()
{
}

//---------------------------------------------------------------

void Game::reset(Player* human_p, Player* computer_p) throw()
{
  human_p->clear();
  computer_p->clear();

  availableMoves_m.clear();

  for ( int i = 0; i <= 8; i++ )
    availableMoves_m.insert(i);
}

//---------------------------------------------------------------

void Game::addMove(int move, Player* player_p) throw (invalid_argument)
{
  checkAvailableMoves(move);

  player_p->insert(move);
}

//---------------------------------------------------------------

void Game::checkAvailableMoves(int move) throw (invalid_argument)
{
  IntSet::iterator it = availableMoves_m.find(move);

  if ( availableMoves_m.end() == it )
    throw invalid_argument("move not valid");

  availableMoves_m.erase(it);
}

//---------------------------------------------------------------

bool Game::moveAvailable() const
{
  return !availableMoves_m.empty();
}

//---------------------------------------------------------------

bool Game::moveAvailable(int move) const
{
  bool returnValue = false;
  IntSet::const_iterator it = availableMoves_m.find(move);

  if ( availableMoves_m.end() != it )
    returnValue = true;

  return returnValue;
}

//---------------------------------------------------------------

const IntSet& Game::getAvailable() const
{
  return availableMoves_m;
}

//---------------------------------------------------------------



