#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "Student.h"

class SoftwareStudent : public Student {     //Chapter 11.4 Polymorphism. 
  using Student::Student;
    public:
        SoftwareStudent(); //Constructor

        ~SoftwareStudent(); //Destructor    

        Degree getDegreeProgram();
        void setDegreeProgram(string degreeType);
        void print();

    private:
        Degree degreeType;
};

#endif /* SOFTWARESTUDENT_H */

