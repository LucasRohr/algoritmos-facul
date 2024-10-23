#include <iostream>

using namespace std;
 
template <typename T>
T multiply(T value_1, T value_2) {
    return value_1 * value_2;
}

int main() {
    cout << multiply<int>(2, 3) << endl;
    cout << multiply<double>(4.5, 2.2) << endl;

    return 0;
}
