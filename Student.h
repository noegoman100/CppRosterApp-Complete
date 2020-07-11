#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
//#include <vector>
#include "Degree.h"

using namespace std;


class Student {
private:
  string studentIDmem;
  string firstNameMem;
  string lastNameMem;
  string emailAddressMem;
  //Degree degreeType; //Should belong in subclass only. 
  int ageMem;
  int daysInCourseMem[3];

public:

  Student(); //Empty Constructor
  Student(string studentID, string firstName, string lastName, string emailAddress, int age, int *daysInCourse);

  ~Student(); //Destructor

  virtual void print();  
  
  
  //Setters:
  void setStudentID(string &studentID);
  void setFirstName(string &firstName);
  void setLastName(string &lastName);
  void setEmailAddress(string &emailAddress);
  void setAge(int age);
  virtual void setDegreeProgram(string degreeType);
  void setDaysInCourse(int *daysInCourse);
  
  //Getters:
  string &getStudentID();  
  string &getFirstName();  
  string &getLastName();  
  string &getEmailAddress();  
  int getAge();  
  virtual Degree getDegreeProgram();  //virtual for polymorphism. Chp 11.4
  int *getDaysInCourse() ;
  
  

};

#endif /* STUDENT_H */

