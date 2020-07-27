#include "Roster.h"

using namespace std;

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
    for (int i = 0; i < SIZE; i++) {
        tempString = "A" + to_string(i + 1);
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