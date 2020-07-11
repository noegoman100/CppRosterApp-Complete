#include "NetworkStudent.h"

NetworkStudent::NetworkStudent() {  // Constructor

    degreeType = SOFTWARE;
    
}

//Student Class Destructor   
NetworkStudent::~NetworkStudent() {
    //cout << "Student Destructor Called" << endl;

}

Degree NetworkStudent::getDegreeProgram() {
    //cout << "Polymorphism!! - Network" << endl;
    return degreeType;
}

void NetworkStudent::setDegreeProgram(string degreeType) {
    //Student::degreeType = degreeType;
    //cout << "Polymorph setDegreeProgram Entered." << endl;
    if (degreeType == "SOFTWARE") {
        NetworkStudent::degreeType = SOFTWARE;
    }
    else if (degreeType == "NETWORK") {
        NetworkStudent::degreeType = NETWORK;
    }
    else if (degreeType == "SECURITY") {
        NetworkStudent::degreeType = SECURITY;
    }
}

void NetworkStudent::print() {
    
    //cout << "Polymorph Print from Inside Network Student" << endl;
    const char *DisplayEnum[] = {"SECURITY", "NETWORK", "SOFTWARE"};  
    cout << getStudentID() << "\t"; 
    cout << "Student First Name: " << getFirstName() << "\t";
    cout << "Student Last Name: " << getLastName() << "\t";
    cout << "Student Age: " << getAge() << "\t\t";
    cout << "Student Days in Course: " << *(getDaysInCourse()) << "," << *(getDaysInCourse()+1) << "," << *(getDaysInCourse()+2) << "\t";
    cout << "Student Degree Program: " << DisplayEnum[getDegreeProgram()];
    cout << endl;     
    
}