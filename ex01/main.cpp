#include <iostream>

using namespace std;

unsigned multiplier(unsigned a, unsigned b);

void test(unsigned a, unsigned b)
{
    cout << "expected  " << a*b << "   -> ";
    cout << multiplier(a, b) << endl;
    if (a*b != multiplier(a, b))
        cout << "ERROR: wrong result" << endl;
}

int main() {
    test(0, 1);
    test(1, 0);
    test(1, 123561);
    test(0, 123561);
    test(123561 ,0);
    test(123561 ,1);
    test(517, 12561);
    test(5513, 1261);
    test(7800, 3161);
    test(3000, 316132198);
}