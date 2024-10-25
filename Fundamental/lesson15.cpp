#include <iostream>

//Function

// Function signature is function name and its parameter
// So, the function can have the same name, but must have a different parameter

void happyBirthday() {
    std::cout << "Happy Birthday" << '\n';
}

//Declare a function but don't assign it first so that we can use the function even if it's outside and after the main function
void calculator(std::string name);
void seeNumber();

//The function datatype is the value returned to the function
double square(double length) {
    return length*length;
}

// Global variable that can be accessed by every function (every scope). It's better to avoid global variable so it doesn't ruin the namespace
int myNum = 3;

//main function
int main() {

    std::string name = "Bro";

    happyBirthday();
    calculator(name); 
    std::cout << square(5) << '\n';
    
    return 0;
}

void calculator(std::string name) {
    std::cout << 1+2 << name << '\n';
    std::cout << myNum << '\n'; //myNum is a global variable. So, any function (any scope) can access that variable
}

void seeNumber() {
    int myNum = 5;
    std::cout << myNum << '\n'; //Use the local scope myNum
    std::cout << ::myNum << '\n'; //Scope resolution operator. Use the global scope myNum
}

