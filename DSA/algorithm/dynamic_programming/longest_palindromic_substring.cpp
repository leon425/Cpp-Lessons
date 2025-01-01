#include <iostream>
#include <vector>


int main() {
    int size = 3;

    std::vector<std::vector<int>> list = 
    {
        {0,1,2},
        {3,4,5},
        {6,7,8},
    };

    // Checking which holds the true condition starting from the lowest row highest col
    // for (int i=0; i<size; i++) {
    //     for (int j=0; j<i+1; j++) {
    //         std::cout << list[j][size-1-i+j] << " ";
    //     }
    //    std::cout << '\n';
    // }

    std::string str = "aaaabbaa";
    int length = str.length();
    std::vector<std::vector<bool>> dp(length,std::vector<bool>(length,false));

    // Create the main diagonal
    // for (int i=0; i<length; i++) {
    //     dp[i][i] = true;
    // }

    for (int i=0; i<length;i++) {
        int count = 0;
        for (int j=length-1-i; j>=0;j--) {
            // the row to check is [length-1-j] ,  the column to check is [length-1-j+i]

            // First diagonal Initiate
            if (i == 0) { // length-1-j == length-1-j+i
                dp[length-1-j][length-1-j+i] = true;
            } 

            // Second diagonal Initiate
            if (i == 1 || i == 2 || i == 3) { 
                if (str[length-1-j] == str[length-1-j+i]) {
                    dp[length-1-j][length-1-j+i] = true;
                }
               
               
            }

        }
    }

    // Print the DP
    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {
            std::cout << dp[i][j] << " ";
        }
       std::cout << '\n';
    }

    return 0;
}