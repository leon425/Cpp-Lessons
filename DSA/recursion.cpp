#include <iostream>

int fib(int num);

int main() {

    std::cout << fib(8) << '\n';
    return 0;
}

// Fibonnaci Recursion
int fib(int num) {
    if (num <= 2 && num > 0) {
        return 1;
    } else if (num < 0) {
        std::cout << "No Negative Index Allowed\n"; 
    } else {
        return fib(num-1) + fib(num-2);
    }
}