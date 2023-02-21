#include <iostream>
#include <string>
#include <list>

using namespace std;

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
            cout << "\nError: unexpected '" << c << "'" << endl;
            return false;
        }
    }
    if (result >> 1)
        cout << "\nError: expression terminated but still several bits in stack" << endl;
    return result & 1;
}

string replace_var(string formula, char *variables, int values)
{
    cout << "|";
    while (*variables)
    {
        char c = (values & 1) ? '1' : '0';
        cout << " " << c << " |";
        int i;
        while ((i = formula.find(*variables)) != string::npos)
            formula[i] = c;
        variables++;
        values >>= 1;
    }
    return formula;
}

void print_truth_table(string formula)
{
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

    // premiere ligne
    cout << "|";
    for (int i = 0; i < count; i++)
        cout << " " << variables[i] << " |";
    cout << " = |" << endl;
    // separation
    cout << "|";
    for (int i = 0; i < count; i++)
        cout << "---|";
    cout << "---|" << endl;

    for (unsigned i = 0; i < (1 << count); i++) {
        string to_eval = replace_var(formula, variables, i);
        bool res = eval_formula(to_eval);
        cout << " " << res << " |" << "  -> " << to_eval << endl;
    }
}

int main()
{
    cout << eval_formula("10&") << endl;
    cout << eval_formula("01&") << endl;
    cout << eval_formula("11&") << endl;
    cout << eval_formula("001||") << endl;
    cout << eval_formula("00|1&") << endl;
    cout << eval_formula("0!1&!") << endl;
    cout << eval_formula("0!1!>!") << endl;
    cout << eval_formula("11&11&=") << endl;

    print_truth_table("AB&!C^");
    print_truth_table("AB&CD&=");
}
