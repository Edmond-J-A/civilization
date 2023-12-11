#include "player.h"
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
    path = "./res/game/construct/0-castle.png";
    chest_size = 60;
    chest = new Item_Pickup[chest_size];
  }
  else if (_name == "workbench")
  {
    ID = 1;
    ownerID = owner;
    x = _x;
    y = _y;
    this->name = _name;
    blockable = false;
    path = "./res/game/construct/1-workbench.png";
  }  
  else if (_name == "farm")
  {
    ID = 2;
    ownerID = owner;
    x = _x;
    y = _y;
    this->name = _name;
    blockable = false;
    chest_size = 10;
    path = "./res/game/construct/2-farm.png";
    chest = new Item_Pickup[chest_size];
  }
}

void Construct::TickAction(std::map<std::string, Item> &itemsList)
{
  if (this->name == "castle")
  {
    this->progress += 1;
    if (this->progress == 100)
    {
      this->progress = this->progress % 100;
      this->AddToChest(Item_Pickup(itemsList["wood"], 1));
    }
  }
  else if (this->name == "farm")
  {
    this->progress += 1;
    if (this->progress == 100)
    {
      this->progress = this->progress % 100;
      this->AddToChest(Item_Pickup(itemsList["food"], 1));
    }
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

Item_Pickup *Construct::GetChest()
{
  return chest;
}

int Construct::GetChestSize()
{
  return chest_size;
}

void Construct::SetChest(int i, Item_Pickup item)
{
  this->chest[i] = item;
}

Construct::~Construct()
{
  if (chest != NULL)
  {
    delete chest;
  }
}

void Construct::AddToChest(Item_Pickup itm)
{
  for (int i = 0; i < this->chest_size; i++)
  {
    if (this->chest[i].item.GetName() == itm.item.GetName())
    {
      if (this->chest[i].item.GetMax() > this->chest[i].number)
      {
        this->chest[i].number += itm.number;
        itm.number = this->chest[i].number - this->chest[i].item.GetMax();
        if (itm.number > 0)
        {
          this->chest[i].number = this->chest[i].item.GetMax();
        }
        else
        {
          return;
        }
      }
    }
  }
  for (int i = 0; i < this->chest_size; i++)
  {
    if (!this->chest[i].item.IsValid())
    {
      this->chest[i] = itm;
      return;
    }
  }
}