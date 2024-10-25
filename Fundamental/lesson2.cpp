#include <iostream>

// Variable & Data Type
int main() {

    int x; // Declaration
    x = 0; // Assignment
    int y = 5;
    int z = 7.5;

    std::cout << z << '/n'; //7 //Because the decimal value will be truncated

    double price = 11.99;
    char grade = 'A'; //use single quote
    bool hasGraduated = true;
    std::string name = "Bro";

    std::cout << "Hello " << name << ". My price is " << price;

// Const 
    // = The variable's value is constant. Tells the compiler to prevent anything from modifying it (read only)
    // More secure & conveys intent. useful for reference and pointer

    const double PI = 3.14159; // Naming convention to be an uppercase letters.
    
    return 0;
}