#include <iostream>

// 0 = false   1 = true;

bool helper(int n, int m) {
    if (m == 1) {
        return true;
    }
    else if (n%m == 0) {
        return false;
    }
    return helper(n,m-1);
}

bool isPrime(int n) {
    return helper(n,n-1);
}

int main() {
    std::cout << isPrime(18) << '\n';
    return 0;
}