#include "./calculator/calculator.h"
#include "./employee/employee.h"
#include "./company/company.h"

int main() {
    Calculator calculator_1 = Calculator("blue");
    Calculator calculator_2 = Calculator("red");

    calculator_1.setMemory(100);
    calculator_2.setMemory(77);

    Employee employee_1 = Employee("jorge", "rua do jorge 123", calculator_1);
    Employee employee_2 = Employee("ed sheeran", "rua das laranjas 787", calculator_2);

    Company company = Company("empresa do laranjo", employee_1, employee_2);

    cout << "Calculations of employee_1"
         << "2 + 2 = " << employee_1.sum(2, 2) << endl
         << "5 - 4 = " << employee_1.subtract(5, 4) << endl
         << "2 * 3 = " << employee_1.multiply(2, 3) << endl << endl;

    cout << "Calculations of employee_2"
         << "6 / 3 = " << employee_2.divide(6, 3) << endl
         << "7 + 2 = " << employee_2.sum(7, 2) << endl
         << "8 * 3 = " << employee_2.multiply(8, 3) << endl << endl;

    company.print_info();
 
    return 0;
}
