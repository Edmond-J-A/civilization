#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#define NO_PLAYER 0

class Item;

class Construct
{
private:
  int x, y;
  bool blockable = false;
  int ownerID = NO_PLAYER;
  int ID = -1;
  std::string name,path;

public:
  Construct();
  Construct(int _x, int _y, std::string name, bool _blockable);
  Construct(std::string _name, int owner, int _x, int _y);
  ~Construct();
  bool SetOwnerID(int ID);
  std::string GetPath(){return this->path;}
  bool TickAction() ;
  bool Place();
  bool Destory();
  bool IsBlock() { return blockable; }
};

#endif