// file Player.cpp

#include "Player.h"

#include <algorithm>

//---------------------------------------------------------------

Player::Player()
{
}

//---------------------------------------------------------------

Player::~Player()
{
}

//---------------------------------------------------------------

bool Player::hasMoved(const IntSet& moves) const
{
  return includes(begin(), end(),
                  moves.begin(), moves.end());
}

//---------------------------------------------------------------

bool Player::hasMoved(const int move) const
{
  IntSet::const_iterator it = find(move);

  return ( it != end() );
}

//---------------------------------------------------------------
