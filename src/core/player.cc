#include "player.h"

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

void Player::Use(std::string i)
{
  for (int j = 0; j < BAG_VOLUME; j++)
  {
    if (this->bag[j].item.GetName() == i)
    {
      this->bag[j].UseOne();
      if (this->bag[j].number <= 0)
      {
        Item_Pickup it;
        this->bag[j] = it;
      }
      return;
    }
  }
}