/*
Shreya Suresh
12/13/22
Zuul- A text-based adventure game. User can exit rooms in all directions, pickup and drop objects, and quit. To win, the user must collect
all 5 objects and go to the winning room, which is unknown.
 */
#include <iostream>
#include <cstring>
#include <map>
#include "rooms.h"

using namespace std;
 void roomDetail(Room* room, vector <Objects*>* inventory){ //tell user which room they are in and where exits are                          
  cout << "You are in the " << room->getType() << endl; 
  cout << "The objects in the room are: ";
  vector <Objects*>* objectlist = room->getObjectlist();
  for (int i = 0; i < objectlist->size(); i++){ //list objects in the room                                                                        
    Objects* o = (*objectlist)[i];
    cout << o->getObject() << " ";
  }
  cout << endl;
  cout << "In your inventory, you have: ";
  for (int i = 0; i < inventory->size(); i++){ //list objects in inventory                                                             
    Objects* o = (*inventory)[i];
    cout << o->getObject() << " ";
  }
  cout << endl;
  cout << "Exits: ";
  //list all the exits                                                                                                                     
                                                                                                                                                 
  if (room->getEast() != NULL){
    cout << "East" << ",";
  } if (room->getWest() != NULL){
    cout << "West" << ",";
  } if (room->getNorth() != NULL){
    cout << "North" << ",";
  } if (room->getSouth() != NULL){
    cout << "South" << ",";
  }
  cout << endl;
  cout << "What would you like to do? Remember your commands are NORTH, SOUTH, EAST, WEST, PICK, DROP, and QUIT" << endl;
}
void pickObject(Room* room, vector <Objects*>* inventory){ //pick up object and add to inventory                                                                   
  char object[100];
  cout << "What object do you want to pick up?" << endl;
  cin >> object;
  int index = -1; //set index to impossible value to check for later                                                                                               
  vector <Objects*>* objectlist = room->getObjectlist();
  for (int i = 0; i < objectlist->size(); i++){
    Objects* o = (*objectlist)[i];
    if (strcmp(object, o->getObject()) == 0){
        index = i;
        break;
      }
  }
    if (index > -1){
      Objects* removedObject = (*objectlist)[index];
      objectlist->erase(objectlist->begin()+index);
      inventory->push_back(removedObject); //add object to inventory                                                                                               
      cout << "Item picked up" << endl;
    } else {
      cout << "Object not valid" << endl;
    }
}
void dropObject(Room* room, vector <Objects*>* inventory){ //drop object off and remove from inventory                                                                                                
  char object[100];
  cout << "What object do you want to drop?" << endl;
  cin >> object;
  int index = -1; //set index to impossible value to check for later                                                                                                                                   
  vector <Objects*>* objectlist = room->getObjectlist();
  for (int i = 0; i < inventory->size(); i++){
    Objects* o = (*inventory)[i];
    if (strcmp(object, o->getObject()) == 0){
      index = i;
      break;
    }
  }
  if (index > -1){
    Objects* removedObject = (*inventory)[index];
    inventory->erase(inventory->begin()+index); //remove object from inventory                                                                                                                         
    objectlist->push_back(removedObject);
    cout << "Item removed" << endl;
  } else {
    cout << "Invalid item" << endl;
  }
}
int main(){
  //create room and object descriptions to use later
  char off[] = "Main office";
  char aud[] = "Auditorium";
  char cafe[] = "Cafeteria";
  char blab[] = "Biology lab";
  char gymc[] = "Gym";
  char btrm[] = "Bathroom";
  char htry[] = "History room";
  char clab[] = "Computer lab";
  char mth[] = "Math room";
  char mark[] = "Marketing room";
  char fre[] = "French room";
  char jap[] = "Japanese room";
  char Ca[] = "CAD room";
  char ar[] = "Art room";
  char da[] = "Dance room";
  char ms[] = "microscope";
  char mi[] = "milk";
  char co[] = "computer";
  char pr[] = "protractor";
  char pb[] = "paintbrush";

  //set all the room descriptions and item locations
  Room* office = new Room();
  office->setType(off);
  Room* auditorium = new Room();
  auditorium->setType(aud);
  Room* cafeteria = new Room();
  cafeteria->setType(cafe);
  cafeteria->addObject(mi);
  Room* biolab = new Room();
  biolab->setType(blab);
  biolab->addObject(ms);
  Room* gym = new Room();
  gym->setType(gymc);
  Room* bathroom = new Room();
  bathroom->setType(btrm);
  Room* history = new Room();
  history->setType(htry);
  Room* computerlab = new Room();
  computerlab->setType(clab);
  computerlab->addObject(co);
  Room* math = new Room();
  math->setType(mth);
  math->addObject(pr);
  Room* marketing = new Room();
  marketing->setType(mark);
  Room* french = new Room();
  french->setType(fre);
  Room* japanese = new Room();
  japanese->setType(jap);
  Room* CAD = new Room();
  CAD->setType(Ca);
  Room* art = new Room();
  art->setType(ar);
  art->addObject(pb);
  Room* dance = new Room();
  dance->setType(da);

  //set all possible exits for each room 
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
  french->setNorth(cafeteria);
  french->setSouth(CAD);
  japanese->setWest(french);
  biolab->setEast(french);
  biolab->setSouth(art);
  CAD->setNorth(french);
  CAD->setWest(art);
  art->setEast(CAD);
  art->setWest(dance);
  art->setNorth(biolab);
  dance->setEast(art);

  vector <Objects*>* inventory = new vector <Objects*>();
  bool running = true;

  cout << "Welcome to Zuul. The commands you can enter are NORTH, SOUTH, EAST, WEST, PICK, DROP, and QUIT. The game starts now. To win, you must be carrying all the items and stand in the correct room." << endl;

  Room* curRoom = office;
  roomDetail(curRoom, inventory);
  char response[10];
  cin >> response;
  for (int i = 0; i < 10; i++){ //convert lowercase to upper
      response[i] = toupper(response[i]);
    }
    while(strcmp(response, "QUIT") != 0){ //check user input only while user still wants to play
      if (strcmp(response, "NORTH") == 0 && curRoom->getNorth() != NULL){ //exit north if user wants 
	cout << "Exiting North.." << endl;
	curRoom = curRoom->getNorth();
      if (strcmp("Japanese room", curRoom->getType()) == 0 && inventory->size() == 5){ //check for winning condition
	cout << "You win! Good job." << endl;
	return 0;
      }
      roomDetail(curRoom, inventory);
      cin >> response;
      for (int i = 0; i < 10; i++){ //convert lowercase to upper                                                                                                                                           
      response[i] = toupper(response[i]);
    }
    }
      else if (strcmp(response, "SOUTH") == 0 && curRoom->getSouth() != NULL){ //exit south if user wants
      cout << "Exiting South.." << endl;
      curRoom = curRoom->getSouth();
      if (strcmp("Japanese room", curRoom->getType()) == 0 && inventory->size() == 5){ //check for winning condition
	cout << "You win! Good job." << endl;
	return 0;
      }
      roomDetail(curRoom, inventory);
      cin >> response;
      for (int i = 0; i < 10; i++){ //convert lowercase to upper                                                                                                                                           
      response[i] = toupper(response[i]);
    }
    }
      else if (strcmp(response, "EAST") == 0 && curRoom->getEast() != NULL){ //exit east if user wants
      cout << "Exiting East.." << endl;
      curRoom = curRoom->getEast();
      if (strcmp("Japanese room", curRoom->getType()) == 0 && inventory->size() == 5){ //check for winning condition
        cout << "You win! Good job." << endl;
        return 0;
      }
      roomDetail(curRoom, inventory);
      cin >> response;
      for (int i = 0; i < 10; i++){ //convert lowercase to upper                                                                                                                                           
      response[i] = toupper(response[i]);
    }
    }
      else if (strcmp(response, "WEST") == 0 && curRoom->getWest() != NULL){ //exit west if user wants
      cout << "Exiting west" << endl;
      curRoom = curRoom->getWest();
      if (strcmp("Japanese room", curRoom->getType()) == 0 && inventory->size() == 5){ //check for winning condition
        cout << "You win! Good job." << endl;
        return 0;
      }
      roomDetail(curRoom, inventory);
      cin >> response;
      for (int i = 0; i < 10; i++){ //convert lowercase to upper                                                                                                                                           
      response[i] = toupper(response[i]);
    }
    }
      else if (strcmp(response, "PICK") == 0){ //pick up item if user wants
       pickObject(curRoom, inventory);
       roomDetail(curRoom, inventory);
       cin >> response;
       for (int i = 0; i < 10; i++){ //convert lowercase to upper                                                                                                                                           
      response[i] = toupper(response[i]);
    }
     }
      else if (strcmp(response, "DROP") == 0){ //drop item if user wants
       dropObject(curRoom, inventory);
       roomDetail(curRoom, inventory);
       cin >> response;
     } else {
       cout << "Invalid." << endl;
       cin >> response;
       for (int i = 0; i < 10; i++){ //convert lowercase to upper                                                                                                                                           
      response[i] = toupper(response[i]);
    }
     }
  }
  return 0;
}
