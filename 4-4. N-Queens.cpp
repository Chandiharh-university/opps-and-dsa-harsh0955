#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        
        vector<bool> cols(n, false); 
        vector<bool> diag1(2 * n, false); 
        vector<bool> diag2(2 * n, false);
        
        backtrack(count, 0, n, cols, diag1, diag2);
        return count;
    }

private:
    void backtrack(int& count, int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        
        if (row == n) {
            count++;
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            
            if (!cols[col] && !diag1[row - col + n] && !diag2[row + col]) {
                
                cols[col] = true;
                diag1[row - col + n] = true;
                diag2[row + col] = true;
                
                backtrack(count, row + 1, n, cols, diag1, diag2);
                
                cols[col] = false;
                diag1[row - col + n] = false;
                diag2[row + col] = false;
            }
        }
    }
};

int main() {
    Solution sol;
    int n = 4; 
    int result = sol.totalNQueens(n);
    cout << "Number of distinct solutions for " << n << "-Queens: " << result << endl;
    return 0;
}