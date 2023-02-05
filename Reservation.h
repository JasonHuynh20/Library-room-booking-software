#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Room.h"
#include "Student.h"
#include "Date.h"

class Reservation{
  //members
  private:
    Student* student;
    Room* room;
    Date date;


  public:
    //constructor
    Reservation(Student* student, Room* room, Date& date);

    //getters
    Student getStudent();
    Room getRoom();
    Date getDate();

    //other functions
    bool lessThan(Reservation& res);
    bool overlaps(const std:: string& r, Date& d);
    void print();




};
#endif
