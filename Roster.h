#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include <sstream>
//#include <vector>
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"

using namespace std;
const int SIZE = 5; //moved from roster.cpp to increase scope.
const int DATASIZE = 9; //number of elements in input string. 

class Roster {
public:
    
    void add(string unparsedInput);
    void printAll();
    void printByDegreeProgram(Degree degreeProgram);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmail();
    void remove(string studentID);
    Roster();
    ~Roster();
    
    private:          
    Student *classRosterArray[SIZE] = { nullptr }; //Fixed. Don't use Vectors! Only initializing the first element, in case the size changes. First element initialized to ensure relevant loops work.
    
      
};


#endif /* ROSTER_H */

