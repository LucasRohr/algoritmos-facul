#include <iostream>

using namespace std;

class Calculator {
    private:
        int memory;
        string color;

    public:
        Calculator();

        Calculator(
            string def_color
        );

        void setMemory(int new_memory);
        int getMemory();

        void setColor(string new_color);
        string getColor();

        float sum(float value_1, float value_2);
        float subtract(float value_1, float value_2);
        float multiply(float value_1, float value_2);
        float divide(float value_1, float value_2);

        int square(int value);
        int cube(int value);

        void print_info();
};