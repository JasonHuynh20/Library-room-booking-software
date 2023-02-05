#include "Room.h"
#include <iostream>

//getters
std::string Room::getName(){
  return name;
}

int Room::getCapacity(){
  return capacity;
}

int Room::getComputers(){
  return computers;
}
//check if there is a whiteboard for the room
bool Room::hasWhiteboard(){
  return whiteboard;
}

//constructor
Room::Room(const std::string& name, int capacity, int computers, bool whiteboard){
  this->name = name;
  this->capacity = capacity;
  this->computers = computers;
  this->whiteboard = whiteboard;
}
//copy constructor
Room::Room(Room &room){
  name = room.getName();
  capacity = room.getCapacity();
  computers = room.getComputers();
  whiteboard = room.hasWhiteboard();
}
//check if room meets criteria
bool Room::meetsCriteria(int capacity, int computers, bool whiteboard) {
  //if meets criteria, return true
  if(this->capacity >= capacity && this->computers >= computers && (this->whiteboard == whiteboard || (this->whiteboard == true && whiteboard == false))){
    return true;
  }else{
    return false;
  }
}

//if a room is less than another room alphanumeric
bool Room::lessThan(Room& r){
  //call the compare function and check wheather its less
  bool returnValue = this->name.compare(r.name);
  if(returnValue < 0){
    return true;
  }else{
    return false;
  }

}

//print fucntion (members)
void Room::print(){
std::cout << "Name: " << name << " Capacity: " << capacity << "#Computers: " << computers << " Has whiteboard: " << whiteboard << std::endl;
}
