#include "item.h"
#include "construct.h"

Item::Item()
{
}

Item::Item(int _ID, std::string _name, int _maxStack, std::string _path, double _durability, double buildingtime)
{
  this->ID = _ID;
  this->name = _name;
  this->maxStack = _maxStack;
  this->path = _path;
  this->durability = _durability;
  this->buildingtime = buildingtime;
}

Item::~Item()
{
}

bool Item::Put(std::vector<std::vector<Construct *>> &gameMap, int x, int y, int owner)
{
  if (gameMap[x][y] == NULL)
  {
    if (this->name == "castle")
    {
      gameMap[x][y] = new Construct("castle", owner, x, y);
      return true;
    }else if(this->name =="workbench"){
      gameMap[x][y] = new Construct("workbench", owner, x, y);
      return true;
    }
    else
    {
    }
  }
  return false;
}