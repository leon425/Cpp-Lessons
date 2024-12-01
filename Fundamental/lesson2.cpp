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

    long a = 9223283293829323; // default is signed.
    signed long b = -132932893232;
    unsigned long c = 1238429382932;
    long long d = 1298293829382938293;

    std::cout << "Hello " << name << ". My price is " << price;

// Const 
    // = The variable's value is constant. Tells the compiler to prevent anything from modifying it (read only)
    // More secure & conveys intent. useful for reference and pointer

    const double PI = 3.14159; // Naming convention to be an uppercase letters.
    
    return 0;
}