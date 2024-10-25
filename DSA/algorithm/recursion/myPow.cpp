#include <iostream>
#include <cmath>

class Solution {
public:
    double unoptimizedMyPow(double x, int n) {
        // If n is 0
        if (n == 0) {
            return 1;
        }

        // If n is negative
        if (n < 0) {
            if (n == -1) {
                return 1/x;
            }
            return 1/x * unoptimizedMyPow(x,n+1);
        }  

        // If n is positive
        if (n == 1) {
            return x;
        }
        return x * unoptimizedMyPow(x,n-1);
    }

    // Binary Exponentiation => x^n = x^(n/2) * x^(n/2) // Runtime is exceeded the limit
    // double myPow(double x, int n) {
    //     bool isOdd;
    //     // If n is 0
    //     if (n == 0) {
    //         return 1;
    //     }

    //     // If n is negative
    //     if (n < 0) {
    //         if (n == -1) {
    //             return 1/x;
    //         }

    //         if (n%2 != 0) { // if n is odd, add with n with 1, then multiply with x with x
    //             n += 1;
    //             return 1/x * myPow(x,n/2) * myPow(x,n/2);
    //         } 

    //         return myPow(x,n/2) * myPow(x,n/2);
    //     }  

    //     // If n is positive
    //     if (n == 1) {
    //         return x;
    //     }
    //     if (n%2 != 0) { // if n is odd, subsract with n with 1, then multiply with x with x
    //         n -= 1;
    //         return x * myPow(x,n/2) * myPow(x,n/2);
    //     } 
    //     return myPow(x,n/2) * myPow(x,n/2);
    // }

    double myPow(double x, int n) {

        if (x == 0) {
            return 0;
        }

        // If n is negative
        if (n < 0) {
            x = 1/x;
            n = abs(n); //negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself (solution.cpp)
        }
        return powHelper(x,n);
    }

    // Use helper function to prevent unnecessary code calls
    double powHelper(double x, int n) {
        if (n == 1) {
            return x;
        }

        if (n == 0) {
            return 1;
        }

        double half = powHelper(x,n/2); // Store the myPow(x,n/2) to prevent unnecessary call. 

        if (n%2 != 0) { // if n is odd, subsract with n with 1, then multiply with x with x
            n -= 1;
            return x * half * half;
        } 
        return half * half;   
    }


};

int main() {
    Solution solution1;
    Solution solution2;
    //std::cout << solution1.unoptimizedMyPow(0.00001,2147483647) << '\n';
    std::cout << solution2.myPow(2,-9) << '\n';

    return 0;
}