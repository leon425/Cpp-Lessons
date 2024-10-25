#include <iostream>

int main() {
// While Loop

    std::string name = "Bro Code";

    while(name.empty()) {
        std::cout << "Enter Your Name";
    }

// Do While Loop = do the block of code first, then repeat again if the condition is true
// Example usecase : do {play game} while (user.wantToPlayGame())

    do {
        std:: cout << "Hey";
    } while (name.empty());

    return 0;
}