#include <iostream>
#include <utility>

using namespace std;

// double map(unsigned short x, unsigned short y)
// {
//     double result = 0;

//     result += x / (double) (1 << 16);
//     result += y / (double) ((unsigned long)1 << 32);
//     return result;
// }

double map(unsigned short x, unsigned short y)
{
    double result = 0;
    double pas = 1. / 2;

    for (int i = 0; i < 16; i++)
    {
        if (y >> 15 != 0)
            result += pas;
        pas /= 2;
        y <<= 1;

        if (x >> 15 != 0)
            result += pas;
        pas /= 2;
        x <<= 1;
        // cout << pas << endl;
    }
    return result;
}

pair<unsigned short, unsigned short> reverse_map(double maped)
{

    if (maped < 0 || maped >= 1)
    {
        cout << "ERROR: arg out of range" << endl;
    }

    unsigned short x = 0;
    unsigned short y = 0;
    double pas = 1. / 2;

    for (int i = 0; i < 16; i++)
    {
        y <<= 1;
        if (maped >= pas)
        {
            maped -= pas;
            y += 1;
        }
        pas /= 2;

        x <<= 1;
        if (maped >= pas)
        {
            maped -= pas;
            x += 1;
        }
        pas /= 2;
    }
    return make_pair(x, y);
}


// pair<unsigned short, unsigned short> reverse_map(double maped)
// {
//     pair<unsigned short, unsigned short> result;

//     if (maped < 0 || maped > 1)
//     {
//         cout << "ERROR: arg out of range" << endl;
//     }
    
//     unsigned long maped2 = maped * (1 << 16) * (1 << 16);
//     result.first = maped2 >> 16;
//     result.second = maped2 & 0xFFFF;
//     return result;
// }

