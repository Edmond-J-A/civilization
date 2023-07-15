#ifndef CHEST_H
#define CHEST_H

#include "item.h"

class Chest
{
private:
  Item *contents;
  unsigned int capacity;

public:
  Chest(int _capacity);
  ~Chest();
};

#endif