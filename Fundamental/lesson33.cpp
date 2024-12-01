#include <iostream>
#include <vector>
#include <utility>

int main() {

    // Initialize a pair - 1st method
    std::pair<int, std::string> myPair(10,"Hello");

    // Initialize a pair - 2nd method
    auto anotherPair = std::make_pair(5,"World");

    // Access a pair
    std::cout << "First: " << myPair.first << '\n';
    std::cout << "Second: " << myPair.second << '\n';

    // Create a vector or pairs
    std::vector<std::pair<int,int>> powerup = {{1,2},{3,4},{3,6},{4,7},{5,5}};

    return 0;
}