#include "../main.hpp"

bool isoper(char c)
{
    return string("&|<>=^").find(c) != string::npos;
}

// bool isvalid(string formula)
// {
//     unsigned stacklen = 0;
//     for (char c : formula)
//     {
//         if (c >= 'A' && c <= 'Z')
//         {
//             stacklen++;
//             continue;
//         }
//         if (c == '!')
//             continue;
//         if (stacklen < 2 || !isoper(c))
//             return false;
//         stacklen--;
//     }
//     return stacklen == 1;
// }

string replace_var(string formula, char *variables, int values)
{
    while (*variables)
    {
        char c = (values & 1) ? '1' : '0';
        size_t i;
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

    if (eval_formula(formula) == -1)   {
        return ;
    }

    for (char c : formula)
    {
        if (c >= 'A' && c <= 'Z' && !((alrdy_seen >> (c - 'A')) & 1))
        {
            variables[count++] = c;
            alrdy_seen |= 1 << (c - 'A');
        }
    }
    variables[count] = 0;

    // toit
    cout << "_";
    for (int i = 0; i < count; i++)
        cout << "----";
    cout << "---_" << endl;
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
        cout << "|";
        for (unsigned j = 0; variables[j]; j++)
            cout << " " << ((i >> j) & 1) << " |";
        string to_eval = replace_var(formula, variables, i);
        bool res = eval_formula(to_eval);
        cout << " " << res << " |" << "  -> " << to_eval << endl;
    }
    cout << endl;
}

bool check_equivalence(string formula1, string formula2)
{
    unsigned alrdy_seen = 0;
    char variables[27];
    int count = 0;

    if (eval_formula(formula1) == -1 || eval_formula(formula2) == -1)   {
        return false;
    }

    for (char c : formula1)
    {
        if (c >= 'A' && c <= 'Z' && !((alrdy_seen >> (c - 'A')) & 1))
        {
            variables[count++] = c;
            alrdy_seen |= 1 << (c - 'A');
        }
    }
    for (char c : formula2)
    {
        if (c >= 'A' && c <= 'Z' && !((alrdy_seen >> (c - 'A')) & 1))
        {
            variables[count++] = c;
            alrdy_seen |= 1 << (c - 'A');
        }
    }
    variables[count] = 0;

    for (unsigned i = 0; i < (1 << count); i++) {
        string to_eval1 = replace_var(formula1, variables, i);
        string to_eval2 = replace_var(formula2, variables, i);
        bool res1 = eval_formula(to_eval1);
        bool res2 = eval_formula(to_eval2);
        if (res1 != res2)
            return false;
    }
    return true;
}
