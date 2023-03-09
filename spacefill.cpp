#include <iostream>
#include <utility>

using namespace std;

// float map(unsigned short x, unsigned short y)
// {
//     unsigned int ohoh = x;
//     float result = 0;

//     result += x / (float) (1 << 16);
//     result += y / (float) ((unsigned long)1 << 32);
//     return result;
// }

// pair<unsigned short, unsigned short> reverse_map(float maped)
// {
//     pair<unsigned short, unsigned short> result;
    
//     unsigned long maped2 = maped * (1 << 16) * (1 << 16);
//     result.first = maped2 >> 16;
//     result.second = maped2 & 0xFFFF;
//     return result;
// }
// omg this is bullshit precision becomes a problem when approaching 1

float map(unsigned short x, unsigned short y)
{}
pair<unsigned short, unsigned short> reverse_map(float maped)
{}


void pro_testing(unsigned short x, unsigned short y)
{
    float maped = map(x, y);
    pair<unsigned short, unsigned short> unmaped = reverse_map(maped);
    cout << x << " " << y << "  \tmaped: " << maped << "  \tunmaped: " << unmaped.first << ", " << unmaped.second << endl;
}

int main()
{
    pro_testing(0, 0);
    pro_testing(0, 1);
    pro_testing(1, 0);
    pro_testing(0, (1<<16) - 1);
    pro_testing((1<<16) - 1, 0);
    pro_testing((1<<16) - 1, (1<<16) - 2);
    pro_testing((1<<16) - 1, (1<<16) - 1);
}