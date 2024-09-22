#include <iomanip>

#include "employee.h"

Employee::Employee() {
    name = "";
    address = "";
    calculator = Calculator();
}

Employee::Employee(
            string def_name,
            string def_address,
            Calculator def_calculator) {
    name = def_name;
    address = def_address;
    calculator = def_calculator;
}

void Employee::setName(string new_name) {
    name = new_name;
}

string Employee::getName() {
    return name;
}

void Employee::setAddress(string new_address) {
    address = new_address;
}

string Employee::getAddress() {
    return address;
}

void Employee::setCalculator(Calculator new_calculator) {
    calculator = new_calculator;
}

Calculator Employee::getCalculator() {
    return calculator;
}

float Employee::sum(float value_1, float value_2) {
    return calculator.sum(value_1, value_2);
}

float Employee::subtract(float value_1, float value_2) {
    return calculator.subtract(value_1, value_2);
}

float Employee::multiply(float value_1, float value_2) {
    return calculator.multiply(value_1, value_2);
}

float Employee::divide(float value_1, float value_2) {
    return calculator.divide(value_1, value_2);
}

int Employee::square(int value) {
    return calculator.square(value);
}

int Employee::cube(int value) {
    return calculator.cube(value);
}

void Employee::print_info() {
    cout << "Employee info: " << endl
        << std::setw(6) << "Name: " << name << endl
        << std::setw(9) << "Address: " << address << endl
        << calculator.print_info();
}
