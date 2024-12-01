#include <iostream>

void swap(char x, char y);
void swapByReference(char &x, char &y);
void printInfo(const std::string &name, const int &age);

int main() {
// Memory address = location in memory where data is tored
// Accessed with & (address of operator);

    std::string name = "Bro";
    std::cout << &name << '\n'; //hexadecimal address. The address changes everytime we run. Can be converted into decimal

// Pass By Value & Pass By Reference

    char x = 'x';
    char y = 'y';
    char temp;

    // Pass by Value
    // temp = x;
    // x = y;
    // y = temp;

    // Pass By Value (create a copy of x & y). Hence, we have 4 different memory addresses. x, copy of x, y, and copy of y
    swap(x,y);

    // Pass By Reference. (Passing Memory address) (recommended)
    swapByReference(x,y);

    std::cout << x << '\n';
    std::cout << y << '\n';

    std::string name = "Bro";
    int age = 17;
    printInfo(name, age);


    return 0;
}

// The swap won't work because the variable passed to the function is not the original variable. 
// It's the copy of the variable. What we're doing now is switching the copy of both variables.
// So, we pass by reference. The reference is the memory address
void swap (char x, char y) {
    char temp;
    temp = x;
    x = y;
    y = temp;
}

void swapByReference(char &x, char &y) {
    char temp;
    temp = x;
    x = y;
    y = temp;  
}

// Or use Pointer
void swapByReferencePointer(char* p, char* q) {
    char temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

//const reference parameter (can't change value)
void printInfo(const std::string &name, const int &age) {
    std::cout << name << '\n';
    std::cout << age << '\n';
}


// PASS BY VALUE
    // Pass by value means passing a copy of the variable to the function. 
    // Changes to the parameter within the function do not affect the original variable.

    // Use When:
        // - The function does not need to modify the original variable.
        // - The variable is of a type that is cheap to copy, such as primitive types (int, char, etc.).

// PASS BY REFERENCE
    // Pass by reference means passing the actual variable to the function. 
    // The function parameter becomes an alias to the original variable, and any changes made to the parameter affect the original variable.

    // Use When:
        // - The function needs to modify the original variable.
        // - The variable is of a type that is expensive to copy, such as large structs or classes.
        // - You want to avoid the overhead of copying large objects.

//  PASS BY CONST REFERENCE
    // Pass by const reference means passing the actual variable to the function, but the function cannot modify the variable. 
    // This combines the efficiency of pass by reference with the safety of pass by value.

    // Use When:
        // - The function does not need to modify the variable, but you want to avoid the overhead of copying.
        // - The variable is of a type that is expensive to copy.

// Pass by value: Safe, but can be inefficient for large objects.
// Pass by reference: Efficient, but allows modification of the original variable.
// Pass by const reference: Efficient and safe, ideal for large objects that should not be modified.

// Guidelines
    // Primitive Types (int, char, float, double, etc.):

         // Pass by value if the function does not need to modify the variable.
    // Large Objects (std::string, std::vector, user-defined classes):

    // Pass by const reference if the function does not need to modify the variable.
        // Pass by reference if the function needs to modify the variable.
        // Objects That Should Not Be Modified:

        // Use pass by const reference to prevent modifications and avoid unnecessary copying.
