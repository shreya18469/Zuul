#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"

using namespace std;

//getters and setters for objects and exits
void Objects::setObject(char o[]){
  strcpy(object, o);
}
char* Objects::getObject(){
  return object;
}
void Room::setType(char t[]){
  strcpy(type, t);
}
char* Room::getType(){
  return type;
}
void Room::setEast(Room* room){
  exits->insert(make_pair(0, room));
}
Room* Room::getEast(){
  map<int, Room*>::iterator it;
  it = exits->find(0);
  if (it != exits->end()){
    return it->second;
  } else {
    return NULL;
  }
}
void Room::setWest(Room* room){
  exits->insert(make_pair(1, room));
}
Room* Room::getWest(){
  map<int, Room*>::iterator it;
  it = exits->find(1);
  if (it != exits->end()){
    return it->second;
  } else {
    return NULL;
  }
}
void Room::setNorth(Room* room){
  exits->insert(make_pair(2, room)); 
}
Room* Room::getNorth(){
  map<int, Room*>::iterator it;
  it = exits->find(2);
  if (it != exits->end()){
    return it->second;
  } else {
    return NULL;
  }
}
void Room::setSouth(Room* room){
  exits->insert(make_pair(3, room));
}
Room* Room::getSouth(){
  map<int, Room*>::iterator it;
  it = exits->find(3);
  if (it != exits->end()){
    return it->second;
  } else {
    return NULL;
  }
}

vector <Objects*>* Room::getObjectlist(){
  return objectlist;
}

Room::Room(){
  objectlist = new vector<Objects*>();
  exits = new map<int, Room*>();
}
void Room::addObject(char ob[]){
  Objects* o = new Objects();
  o->setObject(ob);

  if (objectlist == NULL){
    cout << "No object list" << endl;
  }
  objectlist->push_back(o);
}

Objects* Room::deleteObject(char ob[]){
  int index = -1;
  char item[100];
  cout << "What do you want to pick up?" << endl;
  cin >> item;
  for (int i = 0; i < objectlist->size();i++){
    Objects* o = (*objectlist)[i];
    if (strcmp(o->getObject(), item) == 0){
      index = i;
      break;
    }
  }
  if (index >= 0){
    Objects* o = (*objectlist->begin()+index);
    return o;
  } else {
    return NULL;
  }
}
