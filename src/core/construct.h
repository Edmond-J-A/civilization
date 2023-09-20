#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <map>

#define NO_PLAYER 0
#define MAX_CHEST_SIZE 160

class Item;
class Item_Pickup;

class Construct
{
private:
  int x, y;
  bool blockable = false;
  int ownerID = NO_PLAYER;
  int ID = -1;
  std::string name, path;
  Item_Pickup *chest = NULL;
  int chest_size = 0;
  int progress = 0;

public:
  Construct();
  Construct(int _x, int _y, std::string name, bool _blockable);
  Construct(std::string _name, int owner, int _x, int _y);
  ~Construct();
  bool SetOwnerID(int ID);
  std::string GetPath() { return this->path; }
  void TickAction(std::map<std::string, Item> &itemsList);
  bool Place();
  bool Destory();
  bool IsBlock() { return blockable; }
  Item_Pickup *GetChest();
  int GetChestSize();
  void SetChest(int i, Item_Pickup item);
  void AddToChest(Item_Pickup item);
  bool IsChest() { return chest_size != 0; }
  std::string GetName() { return this->name; }
};

#endif