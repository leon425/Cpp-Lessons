#include <iostream>
#include <typeinfo>

int main() {
// Type Conversion
// Implicit = automatic
// Explicit = precede value with new data type (int)

//Implicitluy change the data type (from double to int)
int x = 3.14;
std::cout << x << '\n';

char z = 100;
std::cout << z << '\n'; //d (according to the ASCII table)

int w = 42;
double b = w;

//Explicitly
int y = 3.14;
double a = (double)y;
std::cout << typeid(a).name() << '\n';
std::cout << a << '\n'; // still 3 because the value stored in y is 3 because y is an integer

// Why is it important
int correct = 8;
int questions = 10;
double score = correct/questions * 100;
std::cout << score << '\n'; //0
// Because it's an integer operation. integer of 8 divided integer of 10 is 0. Because the decimal portion is truncated 
// (it's supposed to be 0.8, but truncated).

// Solution => One of the integer (correct or question) must be a double data type. Can be both of them as well. 
// Explicitly change the questions' datatype

double score2 = correct/(double)questions * 100;
std::cout << score2 << '\n'; //80

    return 0;

}