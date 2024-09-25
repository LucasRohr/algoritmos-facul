#include <iomanip>
#include "company.h"

Company::Company(
            string def_name,
            Employee def_employee_1,
            Employee def_employee_2) {
    name = def_name;
    employee_1 = def_employee_1;
    employee_2 = def_employee_2;
}

void Company::setName(string new_name) {
    name = new_name;
}

string Company::getName() {
    return name;
}

void Company::setEmployee1(Employee new_employee_1) {
    employee_1 = new_employee_1;
}

Employee Company::getEmployee1() {
    return employee_1;
}

void Company::setEmployee2(Employee new_employee_2) {
    employee_2 = new_employee_2;
}

Employee Company::getEmployee2() {
    return employee_2;
}

void Company::print_info() {
    cout << "Company info: " << endl
        << std::setw(6) << "Name: " << name << endl;

    employee_1.print_info();
    employee_2.print_info();
}
