#include <iostream>
#include <utility>

using namespace std;

double map(unsigned short x, unsigned short y)
{
    double result = 0;

    result += x / (double) (1 << 16);
    result += y / (double) ((unsigned long)1 << 32);
    return result;
}

pair<unsigned short, unsigned short> reverse_map(double maped)
{
    pair<unsigned short, unsigned short> result;

    if (maped < 0 || maped >= 1)
    {
        cout << "ERROR: arg out of range" << endl;
    }
    
    unsigned long maped2 = maped * (1 << 16) * (1 << 16);
    result.first = maped2 >> 16;
    result.second = maped2 & 0xFFFF;
    return result;
}

void pro_testing(unsigned short x, unsigned short y)
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
    // for (unsigned short x = 0; x < (1 << 16) - 10001; x+=10000)
    //     for (unsigned short y = x; y < (1 << 16) - 1; y++)
    //         pro_testing(x, y);

    pro_testing(0, 0);
    pro_testing(0, 1);
    pro_testing(1, 0);
    pro_testing(0, (1<<16) - 1);
    pro_testing((1<<16) - 1, 0);
    pro_testing((1<<16) - 1, (1<<16) - 2);
    pro_testing((1<<16) - 1, (1<<16) - 1);
    reverse_map(1);
}