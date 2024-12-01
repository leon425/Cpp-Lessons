#include <iostream>

int gcd(int n, int m) {
    if (n == m) {
        return n;
    }
    else if (n > m) {
        n -= m;
    } else {
        m -= n;
    }
    gcd(n,m);
}


int main() {
    std::cout << gcd(21,14) << '\n';

    return 0;
}