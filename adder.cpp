#include <iostream>

using namespace std;

unsigned adder(unsigned a, unsigned b) {
    cout << "expected  " << a+b << "   -> ";
    while (b != 0) {
        unsigned temp = b;
        b = (a & temp) << 1;
        a ^= temp;
    }
    return a;
}

int main() {
    cout << adder(0, 1) << endl;
    cout << adder(1, 0) << endl;
    cout << adder(1, 123561) << endl;
    cout << adder(5176513, 12561) << endl;
    cout << adder(5513, 12561) << endl;
    cout << adder(7800, 312561) << endl;
    return 0;
}