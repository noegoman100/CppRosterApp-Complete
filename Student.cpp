#include "Student.h"
#include "Roster.h"


Student::Student() {  // Empty Constructor

    //studentIDmem = "TESTING";
    //firstNameMem = "";
    //lastNameMem = "";
    //emailAddressMem = "";
    //degreeType = SECURITY; //Exists in the Sub-Classes. 
    //ageMem = 0;
    //daysInCourseMem[3] = {0};
    
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int *daysInCourse) {  // Full Constructor
    studentIDmem = studentID;
    firstNameMem = firstName;
    lastNameMem = lastName;
    emailAddressMem = emailAddress;
    ageMem = age;
    //daysInCourseMem = daysInCourse;
    daysInCourseMem[0] = daysInCourse[0];
    daysInCourseMem[1] = daysInCourse[1];
    daysInCourseMem[2] = daysInCourse[2];
}

//Student Class Destructor   
Student::~Student() {
    //cout << "Student Destructor Called" << endl;

}


void Student::print() {
  
    //MOVE TO DERIVED CLASSES
    cout << "THIS SHOULD NOT PRINT!!!" << endl;
    const char *DisplayEnum[] = {"SECURITY", "NETWORK", "SOFTWARE"};  
    cout << getStudentID() << "\t"; 
    cout << "Student First Name: " << getFirstName() << "\t";
    cout << "Student Last Name: " << getLastName() << "\t";
    cout << "Student Age: " << getAge() << "\t\t";
    cout << "Student Days in Course: " << *(getDaysInCourse()) << "," << *(getDaysInCourse()+1) << "," << *(getDaysInCourse()+2) << "\t";
    cout << "Student Degree Program: " << DisplayEnum[getDegreeProgram()];
    cout << endl;
}

string &Student::getStudentID() {
  return studentIDmem;
}

void Student::setStudentID(string &studentID) {
  Student::studentIDmem = studentID;
  //cout << "Entered Student ID " << endl;
  
}

string &Student::getFirstName() {
  return firstNameMem;
}

void Student::setFirstName(string &firstName) {
  Student::firstNameMem = firstName;
  //cout << "Entered Student First Name " << endl;
}

string &Student::getLastName() {
  return lastNameMem;
}

void Student::setLastName(string &lastName) {
  Student::lastNameMem = lastName;
  //cout << "Entered Student Last Name " << endl;
}

string &Student::getEmailAddress() {
  return emailAddressMem;
}

void Student::setEmailAddress(string &emailAddress) {
  Student::emailAddressMem = emailAddress;
  //cout << "Entered Student Email " << endl;
}

int Student::getAge() {
  return ageMem;
}

void Student::setAge(int age) {
  Student::ageMem = age;
  //cout << "Entered Student Age " << endl;
}

Degree Student::getDegreeProgram()  {     //'virtual' is only needed in header file. 
    //This function needs to remain empty. Only the subClass version should be called
    //to show Polymorphism. 
    return SECURITY;
}

void Student::setDegreeProgram(string degreeType) {  //'virtual' set in the header file. 
    //Student::degreeType = degreeType;
    //Should only be used from the Sub-Classes!!
    /************
    if (degreeType == "SOFTWARE") {
        Student::degreeType = SOFTWARE;
    }
    else if (degreeType == "NETWORK") {
        Student::degreeType = NETWORK;
    }
    else if (degreeType == "SECURITY") {
        Student::degreeType = SECURITY;
    }
    *************/
}

void Student::setDaysInCourse(int *daysInCourseVar) {
  for (int i = 0; i < 3; i++) {
        Student::daysInCourseMem[i] = daysInCourseVar[i];
  }
  
}

int *Student::getDaysInCourse()  {
  return daysInCourseMem;
}
