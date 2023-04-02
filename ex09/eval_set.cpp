#include <map>
#include <algorithm>
#include "../main.hpp"

using namespace std;

vector<int> eval_set(string &formula, vector<vector<int>> &sets)
{
    vector<int> result;
    map<int, bool> indicator;
    char alpha[27] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    char *variables = alpha + 26 - sets.size();

    for (vector<int> set : sets)
    {
        for (int a : set)
        {
            if (!indicator.count(a))
                indicator[a] = false;
        }
    }

    for (auto pair : indicator)
    {
        int values = 0;
        for (vector<int> set : sets)
        {
            values <<= 1;
            values |= (find(set.begin(), set.end(), pair.first) != set.end());
        }
        string f = replace_var(formula, variables, values);
        pair.second = eval_formula(f);
        if (pair.second)
            result.push_back(pair.first);
        // cout << pair.first << "  " << values << " " << f << "  " << pair.second << endl;
    }
    return result;
}
