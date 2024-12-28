#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, n, k, 1);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, int n, int k, int start) {
        // If the combination is of the desired length, add it to the result
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            combination.push_back(i); 
            backtrack(result, combination, n, k, i + 1); // Recur with the next number
            combination.pop_back(); // Backtrack, remove the number
        }
    }
};

int main() {
    Solution sol;
    int n = 4, k = 2; 
    vector<vector<int>> combinations = sol.combine(n, k);
    
    for (const auto& combo : combinations) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}