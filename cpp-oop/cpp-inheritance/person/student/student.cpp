#include <iomanip>
#include "student.h"

Student::Student(): Person() {
    grade = 0.0;
}

Student::Student(string def_name, int def_age, double def_grade): Person(def_name, def_age) {
    grade = def_grade;
}

void Student::set_grade(double new_grade) {
    grade = new_grade;
}

double Student::get_grade() {
    return grade;
}

void Student::print_data() {
    cout << "Student data: " << endl;
        
    Person::print_data();

    cout << std::setw(7) << "Grade: " << grade << endl;
}
