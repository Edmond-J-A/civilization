#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <iostream>

#define DEFAULT_MAX_STACK 64

class Construct;

class Item
{
private:
  int ID = -1;
  std::string name = "";
  int maxStack = 1;
  double durability = -1;
  std::string path = "";
  double buildingtime = 0;

public:
  Item();
  Item(int _ID, std::string _name, int _maxStack, std::string _path, double _durability = -1.0, double buildingtime = 0);
  ~Item();
  int GetID() { return this->ID; }
  std::string GetName() { return this->name; }
  int GetMax() { return this->maxStack; }
  void SetDurability(double d) { this->durability = d; }
  double GetDurability() { return this->durability; }
  bool operator==(const Item &other) { return (this->ID == other.ID && this->name == other.name); }
  bool IsValid() { return ID >= 0; }
  std::string GetPath() { return this->path; }
  bool Put(std::vector<std::vector<Construct *>> &gameMap, int x, int y, int owner);
};
#endif