#include <iostream>

int main() {
//sizeof() => Return the size in bytes of a variable, dataype, class, objects,etc

    double gpa = 2.5;
    std::string name = "Hey";

    std::cout << sizeof(gpa) << " bytes\n";//8 //max size of double variable
    std::cout << sizeof(name) << " bytes\n";//32 // A string just hold a address where the string of text is located. it's 32 bytes

    // char = 1 byte
    // bool = 1 byte

    // see the array length through sizeof()
    std::string foods[] = {"Burger", "Pizza", "BaoZi", "XiaoLongBao"};
    std::cout << sizeof(foods)/sizeof(std::string) << " elements\n";



    return 0;
}