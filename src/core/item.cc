#include "item.h"

Item::Item()
{
}

Item::Item(int _ID, std::string _name, int _maxStack, std::string _path, double _durability)
{
  this->ID = _ID;
  this->name = _name;
  this->maxStack = _maxStack;
  this->path = _path;
  this->durability = _durability;
}

Item::~Item()
{
}
