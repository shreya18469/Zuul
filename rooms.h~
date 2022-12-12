#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Room{
 public:
  Room();
  void setType(char t[]);
  char* getType();
  Room* getEast();
  Room* getWest();
  Room* getNorth();
  Room* getSouth();
  void setEast(Room*, room);
  void setWest(Room*, room);
  void setNorth(Room*, room);
  void setSouth(Room*, room);
 private:
  char type[100];
  map<int, Room*>* exits;
};
