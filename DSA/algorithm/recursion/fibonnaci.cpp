#include <iostream>

int fib(int n) {
    if (n == 1 || n == 0) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}

int fibSum(int n) {
    if (n == 0 || n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fib(n) + fibSum(n-1);
    }
}

int main() {
    std::cout << fib(7) << '\n';
    std::cout << fibSum(7) << '\n';
    return 0;
}