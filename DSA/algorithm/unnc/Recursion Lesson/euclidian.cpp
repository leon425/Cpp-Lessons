#include <iostream>

int helper(int n, int m) {
    if (n%m == 0) {
        return m;
    }
    helper(m,n%m);
}

int euclidian(int n, int m) {
    // swap if n < m
    if (n < m) {
        return helper(m,n);
    }
    return helper(n,m);
}


int main() {
    std::cout << euclidian(2022,123450) << '\n';

    return 0;
}