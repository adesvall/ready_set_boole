#include "../main.hpp"

vector<int> eval_set(string &formula, vector<vector<int>>& sets);

void test(string formula, vector<vector<int>>& sets)
{
    char name = 'A';
    for (auto s : sets)
    {
        cout << name << " = {";
        for (int a : s)
            cout << a << ", ";
        cout << "},    ";
        name++;
    }
    cout << endl;
    vector<int> result = eval_set(formula, sets);
    cout << formula << " = {";
    for (int a : result)
        cout << a << ", ";
    cout << "}" << endl << endl;
}

int main()
{
    vector<vector<int>> sets;
    sets.push_back({0, 1, 2, 3, 4});
    sets.push_back({0, 1, 2, 5, 6});
    sets.push_back({0, 1, 7, 8});

    test("C", sets);
    test("AC&B|", sets);
    // [0, 1, 2, 5, 6]

    sets = {
        {0, 1, 2},
        {0, 3, 4},
    };
    test("AB&", sets);
    // [0]

    sets = {
        {0, 1, 2},
        {3, 4, 5},
    };
    test("AB|", sets);
    // [0, 1, 2, 3, 4, 5]

    sets = {
        {0, 1, 2},
    };
    test("A!", sets);
    // []
    test("B!", sets);
    // [0, 1, 2]


}
