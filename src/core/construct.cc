#include "item.h"
#include "construct.h"

Construct::Construct()
{
}

Construct::Construct(int _x, int _y, std::string name, bool _blockable)
{
  this->x = _x;
  this->y = _y;
  this->blockable = _blockable;
}

Construct::Construct(std::string _name, int owner, int _x, int _y)
{
  if (_name == "castle")
  {
    ID = 0;
    ownerID = owner;
    x = _x;
    y = _y;
    this->name = _name;
    blockable = false;
    path="./res/game/construct/0-castle.png";
  }
}

bool Construct::SetOwnerID(int ID)
{
  if (this->ownerID == 0)
  {
    this->ownerID = ID;
    return true;
  }
  return false;
}

Construct::~Construct()
{
}
