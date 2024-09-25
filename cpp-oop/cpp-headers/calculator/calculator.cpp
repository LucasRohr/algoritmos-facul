
#include <iomanip>
#include <cmath>
#include "calculator.h"

Calculator::Calculator() {
    memory = 0;
    color = "";
}

Calculator::Calculator(string def_color) {
    memory = 0;
    color = def_color;
}

void Calculator::setMemory(int new_memory) {
    memory = new_memory;
}

int Calculator::getMemory() {
    return memory;
}

void Calculator::setColor(string new_color) {
    color = new_color;
}

string Calculator::getColor() {
    return color;
}

float Calculator::sum(float value_1, float value_2) {
    return value_1 + value_2;
}

float Calculator::subtract(float value_1, float value_2) {
    return value_1 - value_2;
}

float Calculator::multiply(float value_1, float value_2) {
    return value_1 * value_2;
}

float Calculator::divide(float value_1, float value_2) {
    if (value_2 == 0) {
        return -1;
    }

    return value_1 / value_2;
}

int Calculator::square(int value) {
    return pow(value, 2);
}

int Calculator::cube(int value) {
    return pow(value, 3);
}

void Calculator::print_info() {
    cout << "Calculator info: " << endl
        << std::setw(8) << "Memory: " << memory << endl
        << std::setw(7) << "Color: " << color << endl << endl;
}
