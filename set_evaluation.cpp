#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include "main.hpp"

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

int main()
{
    vector<vector<int>> sets;
    sets.push_back({0, 1, 2, 3, 4});
    sets.push_back({0, 1, 2, 5, 6});
    sets.push_back({0, 1, 7, 8});
    string formula = "CA>";

    vector<int> result = eval_set(formula, sets);

    cout << "{\t";
    for (int a : result)
        cout << a << ", ";
    cout << "\t}," << endl;

}