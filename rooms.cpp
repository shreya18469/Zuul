#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "rooms.h"

using namespace std;

void Objects::setObjects(char o[]){
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

}
Room* Room::getEast(){

}
void Room::setWest(Room* room){

}
Room* Room::getWest(){

}
void Room::setNorth(Room* room){
  
}
Room* Room::getNorth(){

}
void Room::setSouth(Room* room){

}
Room* Room::getSouth(){

}

vector <Objects*>* Room::getObjectList(){
  return objectlist;
}

Room::Room(){
  objectList = new vector<Objects*>();
  exits = new map<int, Room*>();
}
void Room::addObject(char ob[]){
  Objects* o = new Objects();
  o->setObject(ob);

  if (objectList == NULL){
    cout << "No object list" << endl;
  }
  objectList->push_back(o);
}

Objects* Room::deleteObject(char ob[]){

}
