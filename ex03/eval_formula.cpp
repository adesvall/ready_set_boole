#include "../main.hpp"

int eval_formula(string formula)
{
    long long result = 0;
    unsigned stacklen = 0;

    for (char c : formula)
    {
        if (c == '0' || c == '1' || (c >= 'A' && c <= 'Z'))
        {
            result <<= 1;
            result |= (c == '1');
            stacklen++;
            continue;
        }
        if (c == '!')   {
            result ^= 1;
            continue;
        }
        if (stacklen < 2)
        {
            cout << "Error: unexpected '" << c << "', stack size must be at least 2." << endl;
            return -1;
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
        else if (c == '<')  {
            bool res = !tmp || (result & 1);
            result >>= 1;
            result <<= 1;
            result |= res;
        }
        else if (c == '=')
            result ^= !tmp;
        else {
            cout << "Error: unexpected '" << c << "'" << endl;
            return -1;
        }
        stacklen--;
    }
    if (stacklen != 1)    {
        cout << "Error: expression terminated but still several bits in stack, expression might be invalid" << endl;
        return -1;
    }
    return result & 1;
}

