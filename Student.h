#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student{
  //members
  private:
    std::string name;
    std::string number;


  public:
    //getters
    std::string getName();
    std::string getNumber();

    //CONSTRUCTORS
    Student();
    Student(const std::string& name, const std::string& number);
    //copy constructor
    Student(Student &student);

    //other functions
    bool lessThan(Student& s);
    void print();




};
#endif
