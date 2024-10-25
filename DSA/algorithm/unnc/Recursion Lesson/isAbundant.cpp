#include <iostream>

// Return the sum of all factors
int helper (int num, int divisor ,int sum) {
    if (divisor == 0) {
        return sum;
    } 

    if (num%divisor != 0) {
        helper(num,divisor-1,sum);
    } else {
        helper(num,divisor-1,sum+divisor);
    }
}

int helper2 (int num, int index = 1) {
    if (num < index) {
        return 0;
    } 

    if (num % index == 0) {
        return index + helper2(num,index+1);
    } else {
        return helper2(num,index+1); // move to the next index 
    }
}

bool isAbundant (int num){
    //return helper(num,num,0) > num;
    return helper2(num) > num;
}

int main() {
    std::cout << helper(12,12,0) << '\n';
    std::cout << helper2(12) << '\n';
    std::cout << isAbundant(12) << '\n';
    return 0;
}