#include <iostream>

int main() {
//if statements

    int age = 17;

    if (age <= 21 && age > 0) {
        std::cout << "You are not allowed to drink";
    } else if (age < 0) {
        std::cout << "You haven't been born right?";
    } else {
        std::cout << "You are allowed to drink";
    }

    return 0;
}