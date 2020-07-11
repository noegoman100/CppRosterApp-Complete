#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "Student.h"

class SecurityStudent : public Student {
  using Student::Student;
    public:
        SecurityStudent(); //Constructor

        ~SecurityStudent(); //Destructor   
        
        Degree getDegreeProgram();
        void setDegreeProgram(string degreeType);
        void print();

    private:
        Degree degreeType;
};

#endif /* SECURITYSTUDENT_H */

