#include <iostream>
#include <vector>

void backtrack(int start, int target, std::vector<int>& current, std::vector<std::vector<int>>& result) {
    
    if (target == 0) {
        result.push_back(current);
        return;
    }
    
    if (target < 0) {
        return;
    }
    
    for (int i = start; i <= 9; ++i) {
        current.push_back(i); 
        backtrack(i, target - i, current, result); // Recur with reduced target
        current.pop_back(); 
    }
}

std::vector<std::vector<int>> generateNumbersWithSum(int sum) {
    std::vector<std::vector<int>> result;
    std::vector<int> current;
    backtrack(1, sum, current, result); 
    return result;
}

int main() {
    int sum;
    std::cout << "Enter the target sum: ";
    std::cin >> sum;

    std::vector<std::vector<int>> combinations = generateNumbersWithSum(sum);

    std::cout << "Combinations that sum to " << sum << ":\n";
    for (const auto& combination : combinations) {
        for (int num : combination) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }

    return 0;
}