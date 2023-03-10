#include <iostream>
#include <utility>

using namespace std;

double map(unsigned short x, unsigned short y)
{
    unsigned int ohoh = x;
    double result = 0;

    result += x / (double) (1 << 16);
    result += y / (double) ((unsigned long)1 << 32);
    return result;
}

pair<unsigned short, unsigned short> reverse_map(double maped)
{
    pair<unsigned short, unsigned short> result;
    
    unsigned long maped2 = maped * (1 << 16) * (1 << 16);
    result.first = maped2 >> 16;
    result.second = maped2 & 0xFFFF;
    return result;
}
// omg this is bullshit precision becomes a problem when approaching 1

// double map(unsigned short x, unsigned short y)
// {
//     // cout << sizeof(x) << " " << sizeof(double) << endl;
//     unsigned int pre = x;
//     pre = (pre << 16) | y;
//     double result = *((double*)&pre);
//     return result;
// }
// pair<unsigned short, unsigned short> reverse_map(double maped)
// {
//     pair<unsigned short, unsigned short> result;
//     unsigned int pre = *(unsigned short*)&maped;
//     result.first = pre >> 16;
//     result.second = pre & 0xFFFF;
//     return result;
// }


void pro_testing(unsigned short x, unsigned short y)
{
    double maped = map(x, y);
    pair<unsigned short, unsigned short> unmaped = reverse_map(maped);
    cout << x << " " << y << "  \tmaped: " << maped << "  \tunmaped: " << unmaped.first << ", " << unmaped.second << endl;
    if (x != unmaped.first || y != unmaped.second)
    {
        cout << "ERROR" << endl;
        exit(1);
    }
}

int main()
{
    for (unsigned short x = 0; x < (1 << 16) - 1001; x+=1000)
        for (unsigned short y = x; y < (1 << 16) - 1; y++)
            pro_testing(x, y);

    pro_testing(0, 0);
    pro_testing(0, 1);
    pro_testing(1, 0);
    pro_testing(0, (1<<16) - 1);
    pro_testing((1<<16) - 1, 0);
    pro_testing((1<<16) - 1, (1<<16) - 2);
    pro_testing((1<<16) - 1, (1<<16) - 1);
}