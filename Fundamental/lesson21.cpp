#include <iostream>

int main() {
// 2D Array

    // The size of the column size is necessary in the declaration
    std::string cars[][4] = {
                                {"Shelby", "Mustang"}, 
                                {"Corvette", "Camaro"}
                            };

    std::cout << cars[0][1];

    return 0;
}