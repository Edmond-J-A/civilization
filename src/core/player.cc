#include "player.h"
#include <fstream>

Player::Player(int _id, Point _location, int _speed) : Creature(_location, _speed)
{
  this->ID = _id;
}

Player::~Player()
{
}

void Player::Move(Point p)
{
  this->SetLocation(p);
}

void Player::PickUp(Item_Pickup itm)
{
  if (itm.number <= 0)
  {
    return;
  }
  for (int i = 0; i < BAG_VOLUME; i++)
  {
    if (this->bag[i].item.GetName() == itm.item.GetName())
    {
      if (this->bag[i].item.GetMax() > this->bag[i].number)
      {
        this->bag[i].number += itm.number;
        itm.number = this->bag[i].number - this->bag[i].item.GetMax();
        if (itm.number > 0)
        {
          this->bag[i].number = this->bag[i].item.GetMax();
        }
        else
        {
          return;
        }
      }
    }
  }
  for (int i = 0; i < BAG_VOLUME; i++)
  {
    if (!this->bag[i].item.IsValid())
    {
      this->bag[i] = itm;
      return;
    }
  }
}

void Player::SetBag(int i, Item_Pickup item)
{
  this->bag[i] = item;
}

void Player::Use(int i) // i指背包栏位下标
{
  if (this->bag[i].UseOne())
  {
    Item_Pickup it;
    this->bag[i] = it;
  }
}

bool Player::Use(std::map<int, int> recipe)
{
  std::map<int, int> bag_count = CountBag();
  for (auto i = recipe.begin(); i != recipe.end(); i++)
  {
    if (bag_count[(*i).first] < (*i).second)
    {
      return false;
    }
  }
  for (auto i = recipe.begin(); i != recipe.end(); i++)
  {
    for (int j = 0; j < BAG_VOLUME; j++)
    {
      if (bag[j].item.GetID() == (*i).first)
      {
        bag[j].number -= (*i).second;
        if (bag[j].number < 0)
        {
          (*i).second = abs(bag[j].number);
          bag[j].number = 0;
          Item_Pickup it;
          this->bag[j] = it;
          continue;
        }
        break;
      }
    }
  }
  return true;
}

std::map<int, int> Player::CountBag()
{
  std::map<int, int> bag_count;
  for (int i = 0; i < BAG_VOLUME; i++)
  {
    bag_count[bag[i].item.GetID()] += bag[i].number;
  }
  return bag_count;
}