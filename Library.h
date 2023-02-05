#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_ARRAY 50

#include <string>
#include "Student.h"
#include "Room.h"
#include "Reservation.h"

class Library{
  //members
  private:
    int stuNum;
    int roomNum;
    int resNum;

    Room* rooms[MAX_ARRAY];
    Student** students;
    Reservation** reservations;


  public:
    //constructor/destructor
    Library();
    ~Library();

    //add functions
    bool addStudent(const std::string& name, const std::string& number);
    bool addRoom(const std::string& name, int capacity, int computers, bool whiteboard);
    //get functions
    bool getStudent(const std::string& name, Student** student);
    bool getRoom(const std::string& roomName, Room** room);
    //other functions
    bool isFree(const std::string& room, Date& d);
    bool makeReservation(const std::string& student, const std::string& room, Date&);
    void printReservations() {}











};

#endif
