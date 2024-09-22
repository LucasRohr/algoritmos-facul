#include <iostream>

#include "../employee/employee.h"

using namespace std;

class Company {
    private:
        string name;
        Employee employee_1;
        Employee employee_2;

    public:
        Company(
            string def_name,
            Employee def_employee_1,
            Employee def_employee_2
        );

        void setName(string new_name);
        string getName();

        void setEmployee1(Employee new_employee_1);
        Employee getEmployee1();

        void setEmployee2(Employee new_employee_2);
        Employee getEmployee2();

        void print_info();
};
