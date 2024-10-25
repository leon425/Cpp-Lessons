#include <iostream>

int main() {
// Array

    std::string car[] = {"corvette", "mustang"};

    std::cout << car << '\n'; //0x61fecc //Memory address of the array

    car[1] = "Camry";
    std::cout << car[0] << " " << car[1]  << '\n';

    // Assign the array value later
    std::string bike[3]; // Set the max size of the array because it's a static data structure
    bike[0] = "BMX";
    bike[1] = "Honda Boeing 777";

    for (int i = 0; !bike[i].empty(); i++) {//skip the elements that are empty
        std::cout << bike[i] << ", ";
    }
    std::cout << '\n';


    return 0;
}