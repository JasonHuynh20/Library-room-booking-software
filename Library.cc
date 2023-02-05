#include <iostream>
#include "Library.h"

//constructor
Library::Library(){
  // array counters
  stuNum = 0;
  resNum = 0;
  roomNum = 0;

  //arrays
  students = new Student*[MAX_ARRAY];
  Room* rooms[MAX_ARRAY];
  reservations = new Reservation*[MAX_ARRAY];
}

//destructor
Library::~Library(){
  //delete all students
  for(int i = 0; i <= stuNum; i++){
    delete students[i];
  }
  //delete all reservations
  for(int i = 0; i <= resNum; i++){
    delete reservations[i];
  }

  //delete arrays
  delete [] students;
  delete [] reservations;

}

//add students
bool Library::addStudent(const std::string& name, const std::string& number){
  //check if too many
  if(stuNum >= MAX_ARRAY){
    return false;
  }
  //add and increment counter
  students[stuNum] = new Student(name, number);
  stuNum++;
  return true;
}

//add a room
bool Library::addRoom(const std::string& name, int capacity, int computers, bool whiteboard){
  // check if too many
  if(roomNum >= MAX_ARRAY){
    return false;
  }
  //add then increment counter
  rooms[roomNum] = new Room(name, capacity, computers, whiteboard);
  roomNum++;
  return true;
}

//get student
bool Library::getStudent(const std::string& name, Student** student){
  //search for matching name
  for(int i = 0; i < stuNum; i++){
    if(students[i]->getName() == name){
      //set pointer to target student
      *student = student[i];
      return true;
    }
  }
  return false;
}

//get room
bool Library::getRoom(const std::string& roomName, Room** room){
  //search for room with matching name
  for(int i = 0; i < roomNum; i++){
    if(rooms[i]->getName() == roomName){
      //set pointer to target room
      *room = rooms[i];
      return true;
    }
  }
  return false;
}

//check if room is free
bool Library::isFree(const std::string& room, Date& d){
  //loop through all reservations for target room
  for(int j = 0; j < resNum; j++){
    //check if it overlaps
      if(reservations[j]->overlaps(room, d)){
        return false;
      }
  }

  return true;
}

bool Library::makeReservation(const std::string& student, const std::string& room, Date& d){
  //declare variables
  Student* stu;
  Room* roo;

  bool checkStu = getStudent(student, &stu);
  bool checkRoom = getRoom(room, &roo);

  //check if student or room does not exists
  if (checkStu == false or checkRoom == false) {
      return false;
  }

  //check if room is free

  bool roomFree = isFree(room, d);
  //create reservations and increment counter
  if(roomFree and resNum < MAX_ARRAY){
    reservations[resNum] = new Reservation(stu, roo, d);
    resNum++;
    return true;
  }

  return false;

}




















//end
