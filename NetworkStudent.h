#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "Student.h"

class NetworkStudent : public Student {
  using Student::Student;
    public:
        NetworkStudent(); //Constructor

        ~NetworkStudent(); //Destructor  

        Degree getDegreeProgram();
        void setDegreeProgram(string degreeType);
        void print();

    private:
        Degree degreeType;
};

#endif /* NETWORKSTUDENT_H */

