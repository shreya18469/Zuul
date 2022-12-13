#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Objects{
 public:
  void setObject(char o[]);
  char* getObject();
 private:
  char object[100];

};

class Room{
 public:
  Room();
  void addObject(char ob[]);
  Objects* deleteObject(char ob[]);
  vector <Objects*>* getObjectlist();
  void setType(char t[]);
  char* getType();
  Room* getEast();
  Room* getWest();
  Room* getNorth();
  Room* getSouth();
  void setEast(Room* room);
  void setWest(Room* room);
  void setNorth(Room* room);
  void setSouth(Room* room);
 private:
  vector <Objects*>* objectlist;
  char type[100];
  map<int, Room*>* exits;
};
