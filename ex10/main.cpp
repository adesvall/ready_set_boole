#include <iostream>
#include <utility>
#include <cstdlib>

using namespace std;

double map(unsigned short x, unsigned short y);
pair<unsigned short, unsigned short> reverse_map(double maped);

void test(unsigned short x, unsigned short y)
{
    double maped = map(x, y);
    pair<unsigned short, unsigned short> unmaped = reverse_map(maped);
    cout << x << " " << y << "  \tmaped: " << maped << "  \tunmaped: " << unmaped.first << ", " << unmaped.second << endl;
    if (x != unmaped.first || y != unmaped.second)
    {
        cout << "ERROR: functions are not bijective" << endl;
        exit(1);
    }
}

int main()
{
    srand(time(NULL));
    for (int i = 0; i < 1000; i++)
    {
        unsigned short x = rand() % (1 << 16);
        unsigned short y = rand() % (1 << 16);
        test(x, y);
    }

    test(0, 0);
    test(0, 1);
    test(1, 0);
    test(0, (1<<16) - 1);
    test((1<<16) - 1, 0);
    test((1<<16) - 1, (1<<16) - 2);
    test((1<<16) - 1, (1<<16) - 1);
}
