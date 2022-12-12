#include <iostream>
#include <cstring>
#include <map>
#include "rooms.h"

using namespace std;

void pickObject(Room* room, vector <Objects*>* inventory){
}
void dropObject(Room* room, vector <Objects*>* inventory){
}
void roomDetail(Room* room, vector <Objects*>* inventory){
  cout << You are in the " << room->getType() << endl;
  cout << "The objects in the room are: ";
  vector <Objects*>* objectlist = room->getObjectlist();
  for (int i = 0; i < objectlist->size(); i++){
    Objects* o = (*objectlist)[i];
    cout << 0->getObject() << " ";
  }
  cout << endl;
  cout << "In your inventory, you have: ";
  for (int i = 0; i < inventory->size(); i++){
    Obejcts* o = (*inventory)[i];
    cout << o->getObject() << " ";
  }
  cout << endl;
  cout << "Exists: ";
  if (room->getEast() != NULL){
    cout << "East " << endl;
  } if (room->getWest() != NULL){
    cout << "West " << endl;
  } if (room->getNorth() != NULL){
    cout << "North " << endl;
  } if (room->getSouth() != NULL){
    cout << "South " << endl;
  }
}
int main(){
  Room* office = new Room();
  office->setType("Main office");
  Room* auditorium = new Room();
  auditorium->setType("Auditorium");
  Room* cafeteria = new Room();
  cafeteria->setType("Cafeteria");
  cafeteria->addObject("milk");
  Room* biolab = new Room();
  biolab->setType("Biology Lab");
  biolab->addObject("microscope");
  Room* gym = new Room();
  gym->setType("Gym");
  Room* bathroom = new Room();
  bathroom->setType("Bathroom");
  Room* history = new Room();
  history->setType("History");
  Room* computerlab = new Room();
  computerlab->setType("Computer Lab");
  computerlab->addObject("computer");
  Room* math = new Room();
  math->setType("Math");
  math->addObject("protractor");
  Room* marketing = new Room();
  marketing->setType("Marketing");
  Room* french = new Room();
  french->setType("French");
  Room* japanese = new Room();
  japanese->setType("Japanese");
  Room* CAD = new Room();
  CAD->setType("CAD");
  Room* art = new Room();
  art->setType("Art");
  art->addObject("paintbrush");
  Room* dance = new Room();
  dance>setType("Dance");

  office->setEast(cafeteria);
  office->setNorth(auditorium);
  auditorium->setSouth(office);
  auditorium->setEast(gym);
  gym->setWest(auditorium);
  gym->setEast(history);
  gym->setSouth(bathroom);
  gym->setNorth(cafeteria);
  bathroom->setSouth(gym);
  history->setWest(gym);
  history->setEast(math);
  math->setWest(history);
  math->setSouth(marketing);
  marketing->setNorth(math);
  marketing->setWest(computerlab);
  computerlab->setEast(marketing);
  computerlab->setWest(cafeteria);
  cafeteria->setWest(office);
  cafeteria->setNorth(gym);
  cafeteria->setEast(computerlab);
  cafeteria->setSouth(french);
  french->setEast(japanese);
  french->setWest(biolab);
  japanese->setWest(french);
  biology->setEast(french);
  biology->setSouth(art);
  CAD->setNorth(french);
  CAD->setWest(art);
  art->setEast(CAD);
  art->setWest(dance);
  art->setNorth(biolab);
  dance->setEast(art);

  vector <Objects*>* inventory = new vector <Objects*>();
  
  return 0;
}
