#include "../main.hpp"

bool eval_formula(string formula)
{
    long long result = 0;

    for (char c : formula)
    {
        if (c == '0' || c == '1')
        {
            result <<= 1;
            result |= (c == '1');
            continue;
        }
        if (c == '!')   {
            result ^= 1;
            continue;
        }
        bool tmp = result & 1;
        result >>= 1;
        if (c == '|')
            result |= tmp;
        else if (c == '&')
            result &= 0xffffffff << !tmp;
        else if (c == '^')
            result ^= tmp;
        else if (c == '>')  {
            bool res = !(result & 1) || tmp;
            result >>= 1;
            result <<= 1;
            result |= res;
        }
        else if (c == '=')
            result ^= !tmp;
        else {
            cout << "Error: unexpected '" << c << "'" << endl;
            return false;
        }
    }
    if (result >> 1)
        cout << "Error: expression terminated but still several bits in stack, expression might be invalid" << endl;
    return result & 1;
}

