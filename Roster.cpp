#include "Roster.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
//#include <vector>
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "Degree.h"

using namespace std;
//const int SIZE = 5; // Size of the Roster Array. Moved to Roster.h for Global Scope. 

Roster::Roster() {      //Roster Constructor
    //cout << "Roster Constructor Called." << endl;
    
}


Roster::~Roster() {
    //cout << "Roster Destructor Called." << endl;    
    
}

const string studentData[SIZE] =
  {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Edward,Sawyer,esawy12@wgu.edu,36,14,21,17,SOFTWARE"
  };

int main() {
    int i = 0;
    string tempString = "";

    // Set F.2.
    Roster classRoster; //Make a single roster object. 

    //Don't use Vectors.
    //vector<Roster> classRosterArray;
    //Roster *rostPtr;

  
    for (i = 0; i < SIZE; i++) { //set to SIZE (5) the studentData array is 120 in size?? why 120?
        string lineString = studentData[i]; // Input string
        string unparsedInput = studentData[i];  

        //****** Add The Student! 
        classRoster.add(unparsedInput);      
    } 

    // Step F.1.
    cout << "************************************************************************************************************************************************************************" << endl;
    cout << "************************************* C867 Scripting and Programming Applications - C++ - ID#000896041 - Edward Sawyer *************************************************" << endl;
    cout << "************************************************************************************************************************************************************************" << endl << endl;
    
    classRoster.printAll();    
    classRoster.printInvalidEmail();    
    for(int i = 0; i < SIZE; i++) {
        tempString = "A" + to_string(i+1);
        classRoster.printAverageDaysInCourse(tempString);     
    }
    classRoster.printByDegreeProgram(SOFTWARE);    
    classRoster.remove("A3");
    classRoster.remove("A3");
    //classRoster.printAll(); //WORKS!
    //classRoster.printByDegreeProgram(SOFTWARE); //WORKS!
    //classRoster.printInvalidEmail(); //WORKS!
    return 0;
}



void Roster::add(string unparsedInput) {
    Student* student;
    istringstream inStream;
    string parsedString[DATASIZE];
  
    inStream.clear();
    inStream.str(unparsedInput);
    getline(inStream, parsedString[0], ','); //StudentID
    getline(inStream, parsedString[1], ','); //First Name
    getline(inStream, parsedString[2], ','); //Last Name
    getline(inStream, parsedString[3], ','); //Email
    getline(inStream, parsedString[4], ','); //Age
     
    getline(inStream, parsedString[5], ','); //timeInClassOne
    getline(inStream, parsedString[6], ','); //timeInClassTwo
    getline(inStream, parsedString[7], ','); //timeInClassThree

    getline(inStream, parsedString[8], ','); //Student Major  
    
    int parsedInt[3] = { stoi(parsedString[5]), stoi(parsedString[6]), stoi(parsedString[7]) };
    if (parsedString[8] == "SOFTWARE") {
        student = new SoftwareStudent(parsedString[0], parsedString[1], parsedString[2], parsedString[3], stoi(parsedString[4]), parsedInt);  //Pass in arguments via constructor. 
        student->setDegreeProgram("SOFTWARE");
        //cout << "Added Software Student " << endl;
    }
    else if (parsedString[8] == "NETWORK") {
        student = new NetworkStudent(parsedString[0], parsedString[1], parsedString[2], parsedString[3], stoi(parsedString[4]), parsedInt);
        student->setDegreeProgram("NETWORK");
        //cout << "Added Network Student " << endl;      
    }
    else if (parsedString[8] == "SECURITY") {
        student = new SecurityStudent(parsedString[0], parsedString[1], parsedString[2], parsedString[3], stoi(parsedString[4]), parsedInt);
        student->setDegreeProgram("SECURITY");
        //cout << "Added Security Student " << endl;      
    }
    else {
        //cout << "Problem with student Course " << endl;
    }    
    
    //A course instructor suggested I pass all the parsed data over to be set inside of the construct, instead of using the mutators here.
    //student->setStudentID(parsedString[0]);
    //student->setFirstName(parsedString[1]);
    //student->setLastName(parsedString[2]);
    //student->setEmailAddress(parsedString[3]);
    //student->setAge(stoi(parsedString[4]));
        //int parsedInt[3] = { stoi(parsedString[5]), stoi(parsedString[6]), stoi(parsedString[7]) };
    //student->setDaysInCourse(parsedInt);
    
    
    
    
    for (int i = 0; i < SIZE; i++) {
      if (classRosterArray[i] == nullptr) {
        classRosterArray[i] = student;
        break;   //Is there a better way?
      }
    }
    return;
}



void Roster::printAll() {
    //cout << "Entered printAll function" << endl; //Testing
    cout << "**************************************************************** printAll() ********************************************************************************************" << endl <<endl;
    for (int i = 0; i < SIZE; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    // Don't User Vectors! 
    //vector<Roster>::iterator iter;
    //cout << "VECTOR PrintAll Roster Size: " << classRosterArray.size() << endl;
    //for (iter = classRosterArray.begin(); iter != classRosterArray.end(); iter++) {
    //for (int i = 0; i < SIZE; i++)
    //    iter->print();
    //}
    
    cout << endl;
}

void Roster::printByDegreeProgram(Degree degreeProgram) {
    
    const char *DisplayEnum[] = {"SECURITY", "NETWORK", "SOFTWARE"};
    cout << "**************************************************************** printProgramByDegree() ********************************************************************************" << endl <<endl;
    cout << DisplayEnum[degreeProgram] << " students: " << endl; 
    for (int i = 0; i < SIZE; i++) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getDegreeProgram() == degreeProgram)  ) {
          classRosterArray[i]->print();
        }
    }
  
    cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
    int sum = 0;
    float avg;
    cout << "**************************************************************** printAverageDaysInCourse() ****************************************************************************" << endl <<endl;
    for (int i = 0; i < SIZE; i++) {
      if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {
          sum = *(classRosterArray[i]->getDaysInCourse()) + *(classRosterArray[i]->getDaysInCourse()+1) + *(classRosterArray[i]->getDaysInCourse()+2);
          avg = sum / 3.0;
          cout << "For Student " << studentID << ", Average Days Spent Per Class: " << fixed << std::setprecision(1) << avg << endl;
      }
    }
  
  
}

void Roster::printInvalidEmail() {  
    string emailCheck;
    cout << "**************************************************************** printInvalidEmail() ***********************************************************************************" << endl <<endl;
    for (int i = 0; (classRosterArray[i] != nullptr) && (i < SIZE); i++) {

      emailCheck = classRosterArray[i]->getEmailAddress();

      if (emailCheck.find("@") == string::npos){
          cout << "Invalid Email Address: " << emailCheck << "  - Missing @. " <<endl;
      }
      else if (emailCheck.find(".") == string::npos) {
          cout << "Invalid Email Address: " << emailCheck << "  - Missing a Period. " <<endl;
      }
      else if (emailCheck.find(" ") != string::npos) {
          cout << "Invalid Email Address: " << emailCheck << "  - No spaces allowed. " <<endl;
      }


    }

    cout << endl;
}

void Roster::remove(string studentID) {
    int numErased = 0;  //See how many records were erased.
    cout << "**************************************************************** Remove a Student **************************************************************************************" << endl <<endl;
    for (int i = 0; i < SIZE; i++) {
        if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {
            classRosterArray[i] = nullptr;
            numErased++;
            cout << "Student " << studentID << " removed." << endl;
        }
    }
    if (numErased == 0) {
        cout << "Student " << studentID << " not found." << endl;      
    }
    
}

