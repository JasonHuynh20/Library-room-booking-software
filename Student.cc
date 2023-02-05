#include "Student.h"
#include <iostream>




//getters
std::string Student::getName(){
  return this->name;
}

std::string Student::getNumber(){
  return this->number;
}

//constructors
//default
Student::Student(){
  this->name = "John Doe";
  this->number = "1010010100101";
}

//constructor with parameters
Student::Student(const std::string& name, const std::string& number){
  this->name = name;
  this->number = number;
}

//copy constructors
Student::Student(Student &student){
  name = student.getName();
  name = student.getNumber();
}

//see if a students name is less than another alphanumeric
bool Student::lessThan(Student& s){
  //call compare function
  bool returnValue = name.compare(s.name);
  if(returnValue < 0){
    return true;
  }else{
    return false;
  }
}

//print function (print members)
void Student::print(){
  std::cout << "Name: " << name << " Number: " << number << std::endl;
}
