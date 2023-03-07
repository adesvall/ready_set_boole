#include <iostream>
#include <vector>

using namespace std;

void backtrack(const vector<int> &set, vector<vector<int>> &result, vector<int> &current, int index) {
    if (index == set.size())    {
        result.push_back(current);
        return;
    }
    current.push_back(set[index]);
    backtrack(set, result, current, index + 1);
    current.pop_back();
    backtrack(set, result, current, index + 1);
}

vector<vector<int>> powerset(const vector<int> &set) {
    vector<vector<int>> result;
    vector<int>         current;
    
    backtrack(set, result, current, 0);
    return result;
}

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

