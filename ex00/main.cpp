#include <iostream>

using namespace std;

unsigned adder(unsigned a, unsigned b);
void test(unsigned a, unsigned b)
{
    cout << "expected  " << a+b << "   -> ";
    cout << adder(a, b) << endl;
    if (a+b != adder(a, b))
        cout << "ERROR: wrong result" << endl;
}


int main() {
    test(0, 0);
    test(0, 1);
    test(1, 0);
    test(1, 123561);
    test(5176513, 12561);
    test(5513, 12561);
    test(7800, 312561);
    test(4294967295, 0);
    test(4294967295, 1);
    return 0;
}