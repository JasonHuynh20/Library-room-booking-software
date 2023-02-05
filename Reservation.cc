#include "Reservation.h"
#include <iostream>

//constructor
Reservation::Reservation(Student* student, Room* room, Date& date){
  this->student = student;
  this->room = room;
  this->date = date;
}

//getters
Student Reservation::getStudent(){
  return *student;
}

Room Reservation::getRoom(){
  return *room;
}
Date Reservation::getDate(){
  return date;
}

//less than function
bool Reservation::lessThan(Reservation& res){
  //get date from reservation and check if less than the other
  Date d = res.getDate();
  return date.lessThan(d);
}

//overlaps
bool Reservation::overlaps(const std:: string& r, Date& d){
  //check if the name matches then call overlaps
  if (r == room->getName()) {
      return date.overlaps(d);
  }

  return false;
}

//print the reservation members with a format
void Reservation::print(){
  std::cout << "Reservation for: ";
  student->print();

  std::cout << "Room: ";
  room->print();

  std::cout << "Time slot: ";
  date.print();
}
