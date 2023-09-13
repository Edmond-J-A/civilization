#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include "animation.h"
#include "item.h"

#define BAG_VOLUME 60
#define BAG_COL 10

struct Item_Pickup
{
  Item item;
  int number = -1;
  Item_Pickup() : number(-1) {}
  Item_Pickup(const Item &item, int number) : item(item), number(number) {}
  bool UseOne()
  {
    number--;
    return number == 0;
  }
};

class Player : public Creature, public Animation
{
private:
  int ID = -1;
  Item_Pickup bag[BAG_VOLUME];
  std::string name = "";

public:
  Player(int _id, Point _location, int _speed = 5);
  ~Player();
  int GetID() { return ID; }
  Point GetLocation() { return Creature::GetLocation(); }
  void Move(Point p);
  void PickUp(Item_Pickup i);
  Item_Pickup GetPickup(int i) { return this->bag[i]; }
  void SetBag(int i, Item_Pickup item);
  void Use(std::string i);
};

#endif