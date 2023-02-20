#include <iostream>

using namespace std;

unsigned gray_code(unsigned n) {
    return n ^ (n >> 1);
}

int main() {
    for (unsigned i = 0; i < 16; ++i)
        cout << i << " -> " << gray_code(i) << endl;
    return 0;
}