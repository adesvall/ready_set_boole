#include <iostream>

using namespace std;

unsigned adder(unsigned a, unsigned b) {
    while (b != 0) {
        unsigned temp = b;
        b = (a & temp) << 1;
        a ^= temp;
    }
    return a;
}

unsigned multiplier(unsigned a, unsigned b) {
    cout << "expected  " << a*b << "   -> ";

    unsigned result = 0;
    while (b != 0) {
        if (b & 1)
            result = adder(result, a);
        a <<= 1;
        b >>= 1;
    }
    return result;
}

int main() {
    cout << multiplier(0, 1) << endl;
    cout << multiplier(1, 0) << endl;
    cout << multiplier(1, 123561) << endl;
    cout << multiplier(517, 12561) << endl;
    cout << multiplier(5513, 1261) << endl;
    cout << multiplier(7800, 3161) << endl;
    return 0;
}