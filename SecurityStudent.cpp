#include "SecurityStudent.h"

SecurityStudent::SecurityStudent() {  // Constructor

    degreeType = SECURITY;
    
}

//Student Class Destructor   
SecurityStudent::~SecurityStudent() {
    //cout << "Student Destructor Called" << endl;

}

Degree SecurityStudent::getDegreeProgram() {
  //cout << "Polymorphism!! - Security" << endl;
  return degreeType;
}

void SecurityStudent::setDegreeProgram(string degreeType) {
    //Student::degreeType = degreeType;
    //cout << "Polymorph setDegreeProgram Entered." << endl;
    if (degreeType == "SOFTWARE") {
        SecurityStudent::degreeType = SOFTWARE;
    }
    else if (degreeType == "NETWORK") {
        SecurityStudent::degreeType = NETWORK;
    }
    else if (degreeType == "SECURITY") {
        SecurityStudent::degreeType = SECURITY;
    }
}

void SecurityStudent::print() {
    
    //cout << "Polymorph Print from Inside Security Student" << endl;
    const char *DisplayEnum[] = {"SECURITY", "NETWORK", "SOFTWARE"};  
    cout << getStudentID() << "\t"; 
    cout << "Student First Name: " << getFirstName() << "\t";
    cout << "Student Last Name: " << getLastName() << "\t";
    cout << "Student Age: " << getAge() << "\t\t";
    cout << "Student Days in Course: " << *(getDaysInCourse()) << "," << *(getDaysInCourse()+1) << "," << *(getDaysInCourse()+2) << "\t";
    cout << "Student Degree Program: " << DisplayEnum[getDegreeProgram()];
    cout << endl;      
    
    
}