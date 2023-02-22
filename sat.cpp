#include "main.hpp"

using namespace std;

bool sat(string formula) {
    unsigned alrdy_seen = 0;
    char variables[27];
    int count = 0;

    for (char c : formula)
    {
        if (c >= 'A' && c <= 'Z' && !((alrdy_seen >> (c - 'A')) & 1))
        {
            variables[count++] = c;
            alrdy_seen |= 1 << (c - 'A');
        }
    }
    variables[count] = 0;

    for (int values = 0; values < (1 << count); values++) {
        string to_eval = replace_var(formula, variables, values);
        if (eval_formula(to_eval))
            return true;
    }
    return false;
}