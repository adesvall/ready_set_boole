#include <iostream>
#include <vector>

using namespace std;

void backtrack(const vector<int> &set, vector<vector<int>> &result, vector<int> &current, size_t index) {
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

