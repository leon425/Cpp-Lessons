#include <iostream>
#include <vector>


std::vector<bool> knapsack(int n, int m, std::vector<int> profit, std::vector<int> weight) {
    std::vector<bool> result(n, false);
    std::vector<std::vector<int>> table(n+1,std::vector<int>(m+1,0)); // n+1 and m+1 because we want to include 0.
    for (int i=0;i<n+1;i++) {
        for (int j=0;j<m+1;j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else {
                if (j-weight[i-1] < 0) {
                    table[i][j] = table[i-1][j];
                } else {
                    table[i][j] = std::max(table[i-1][j], table[i-1][j-weight[i-1]]+profit[i-1]); //check again
                }
                
            }
        }
    }
    int target = table[n][m];
    std::cout << target << '\n';
    for (int i=n-1;i>=0;i--) { // Start the loop in the 2nd last row        
        if (table[i+1][m] != table[i][m]) {
            result[i] = true;
            target -= profit[i];
            m -= weight[i];
        }
    }
    return result;
}

int main() {
    std::vector<int> profit = {1,2,5,6};
    std::vector<int> weight = {2,3,4,5};
    std::vector<bool> result = knapsack(4,8,profit,weight);
    for (int i=0;i<result.size();i++) {
        std::cout << result[i] << " ";
    }
    std::cout << '\n';
    return 0;
}