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

void Player::SetBag(int i,Item_Pickup item)
{
  this->bag[i]=item;
}