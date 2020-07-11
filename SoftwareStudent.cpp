#include "SoftwareStudent.h"

SoftwareStudent::SoftwareStudent() {  // Constructor

    degreeType = SOFTWARE;
    
}

//Student Class Destructor   
SoftwareStudent::~SoftwareStudent() {
    //cout << "Student Destructor Called" << endl;

}

Degree SoftwareStudent::getDegreeProgram() {
    //cout << "Polymorphism!! - Software" << endl;
    return degreeType;
}

void SoftwareStudent::setDegreeProgram(string degreeType) {
    //Student::degreeType = degreeType;
    //cout << "Polymorph setDegreeProgram Entered." << endl;
    if (degreeType == "SOFTWARE") {
        SoftwareStudent::degreeType = SOFTWARE;
    }
    else if (degreeType == "NETWORK") {
        SoftwareStudent::degreeType = NETWORK;
    }
    else if (degreeType == "SECURITY") {
        SoftwareStudent::degreeType = SECURITY;
    }
}

void SoftwareStudent::print() {
    
    //cout << "Polymorph Print from Inside Software Student" << endl;
    const char *DisplayEnum[] = {"SECURITY", "NETWORK", "SOFTWARE"};  
    cout << getStudentID() << "\t"; 
    cout << "Student First Name: " << getFirstName() << "\t";
    cout << "Student Last Name: " << getLastName() << "\t";
    cout << "Student Age: " << getAge() << "\t\t";
    cout << "Student Days in Course: " << *(getDaysInCourse()) << "," << *(getDaysInCourse()+1) << "," << *(getDaysInCourse()+2) << "\t";
    cout << "Student Degree Program: " << DisplayEnum[getDegreeProgram()];
    cout << endl;     
    
}