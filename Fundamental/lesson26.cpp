#include <iostream>

template <typename T> // add a template parameter declaration

// If you want to use many datatype for the parameter inside 1 function
// template <typename T, typename U>

// This function will work with many datatype. (But only 1 type of datatype)
T max(T x, T y) { // T is a common naming convention
    return (x > y) ? x : y;
}

/*
T max (T x, U y) { // However, if T is an 'int' and y is a 'double', the function always return an 'int' value. So, if y > x, the decimal value of y will be truncated. So, the solution is to use 'auto' on returning the datatype of the variable. The compiler will figure out which datatype to return
    return (x > y) ? x : y;
}

auto max (T x, U y) {
    return (x > y) ? x : y;
}

*/

int main() {
// Function Template = Describes what a function looks like.
                    // To generate as many overloaded function as needed, each using different data types
                    // Don't need to specify the data type during runtime - can be anything (int, double, char)

                    // Templates are compiled when used (instantiated), not when defined.
    


    return 0;
}