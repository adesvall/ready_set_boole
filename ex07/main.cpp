#include "../main.hpp"

bool sat(string expr);

void test(string expr)
{
    cout << expr << "\t=> " << sat(expr) << endl;
}

int main(int ac, char** argv)
{
    if (ac > 1)     {
        test(argv[1]);
        return 0;
    }
    else
    {
        test("AB|");
        // true
        test("AB&");
        // true
        test("AA!&");
        // false
        test("AA^");
        // false
        test("AB&AB|!&");
        // false
    }
}
