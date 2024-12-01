#include <iostream>
#include <vector>

int fib(int n) {
    std::vector<int> fib = {0,1};
    fib.resize(n);
    for (int i=2;i<=n;i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main() {
    std::cout << fib(6) << '\n';
    return 0;
}