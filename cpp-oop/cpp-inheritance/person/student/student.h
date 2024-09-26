#include "../person.h"

#ifndef STUDENT_H
#define STUDENT_H

class Student: public Person {
    private:
        double grade;

    public:
        Student();
        Student(string def_name, int def_age, double def_grade);

        void set_grade(double new_grade);
        double get_grade();

        void print_data();
};

#endif
