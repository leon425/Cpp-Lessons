#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string str = "aaaabbaa";
    int length = str.length();
    
    // DP table to store whether the substring [i, j] is a palindrome
    std::vector<std::vector<bool>> dp(length, std::vector<bool>(length, false));

    // Every single character is a palindrome
    for (int i = 0; i < length; i++) {
        dp[i][i] = true;
    }

    // Check for palindromes of length 2 or more
    for (int len = 2; len <= length; len++) { // len is the length of the substring
        for (int i = 0; i <= length - len; i++) {
            int j = i + len - 1; // j is the ending index of the substring

            if (str[i] == str[j]) {
                if (len == 2) {
                    dp[i][j] = true; // Substrings of length 2 are palindromes if the two characters are equal
                } else {
                    dp[i][j] = dp[i + 1][j - 1]; // For length > 2, it's a palindrome if the inner substring is a palindrome
                }
            }
        }
    }

    // Print the DP table
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            std::cout << dp[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}