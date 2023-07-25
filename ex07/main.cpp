#include "../main.hpp"

bool sat(string expr);

int main(int ac, char** argv)
{
    if (ac > 1)     {
        cout << sat(argv[1]) << endl;
        return 0;
    }
    else
    {
        cout << sat("AB|") << endl;
        // true
        cout << sat("AB&") << endl;
        // true
        cout << sat("AA!&") << endl;
        // false
        cout << sat("AA^") << endl;
        // false
        cout << sat("AB&AB|!&") << endl;
        // false
    }
}
