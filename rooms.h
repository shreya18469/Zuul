#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Objects{ //object class
 public:
  void setObject(char o[]);
  char* getObject();
 private:
  char object[100];

};

class Room{ //room class
 public:
  //rooms, objects, and exits
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
  //map, objects, room name
  vector <Objects*>* objectlist;
  char type[100];
  map<int, Room*>* exits;
};
