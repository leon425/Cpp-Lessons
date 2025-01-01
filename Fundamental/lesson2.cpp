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

// auto    
    // = type specifier that allows the complier to deduce the type of variable based on its initializzer
    // Useful in complex types like iterators, lambdas, or return value from functions.
    auto x = 3.14; // deduce into double

/*
Signed Integer: Hold positive and negative value with 1 bit is used as the sign bit. 
                Therefore, the range is split between negative and positive numbers.
                Range: -2^(n-1) to 2^(n-1) -1

Unsigned Integer: Only hold zero and positive number. Range is entirely positive.
                    Range : 0 to 2^n - 1


uint8_t	    8 bits	    0 to 255	                        Guaranteed 8 bits
uint16_t	16 bits	    0 to 65,535	                        Guaranteed 16 bits
uint32_t	32 bits	    0 to 4,294,967,295	                Guaranteed 32 bits
uint64_t	64 bits	    0 to 18,446,744,073,709,551,615	    Guaranteed 64 bits

int8_t  	-128 to 127	                                                                        Small signed values (e.g., flags)
int16_t		-32,768 to 32,767	                                                                Moderate signed values
int32_t		-2,147,483,648 to 2,147,483,647                                                 	Default for larger signed integers
int64_t		-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807	                            Very large signed values
int	        Varies (commonly -2,147,483,648 to 2,147,483,647 on 32-bit systems)	                General-purpose signed integers

long (depends on 32-bit or 64-bit system)       32-bit: -2,147,483,648 to 2,147,483,647        64-bit: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
long long	                                    64 bits	-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807

unsigned long
unsigned long long

*/

    return 0;
}