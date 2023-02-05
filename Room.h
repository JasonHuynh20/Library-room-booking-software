#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room{
  //members
  private:
    std::string name;
    int capacity;
    int computers;
    bool whiteboard;


  public:
    //getters
    std::string getName();
    int getCapacity();
    int getComputers();
    bool hasWhiteboard();

    //constructors
    Room(const std::string& name, int capacity, int computers, bool whiteboard);
    //copy constructor
    Room(Room &room);

    //other functions
    bool meetsCriteria(int capacity = 0, int computers = 0, bool whiteboard = false);
    bool lessThan(Room& r);
    void print();





};
#endif
