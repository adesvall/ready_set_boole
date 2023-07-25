#include "../main.hpp"

vector<vector<int>> powerset(const vector<int>& set);

void print_powerset(vector<vector<int>>& pwset)
{
    cout << "{" << endl;
    for (vector<int> &set : pwset)
    {
        cout << "\t{\t";
        for (int a : set)
            cout << a << ", ";
        cout << "\t\t\t}," << endl;
    }
    cout << "}" << endl;
}

int main()
{
    vector<vector<int>> pwset = powerset({0, 1, 2, 3, 4, 5});
    print_powerset(pwset);
    cout << pwset.size() << endl;
}

