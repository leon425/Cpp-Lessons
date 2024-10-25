#include <iostream>


int main() {
// String method
// See more at cplusplus.com

    std::string name = "Bro Code";

    std::cout << name.length();
    std::cout << name.empty(); // true or false
    //name.clear(); //delete / clear the value
    name.append("@gmail.com"); // add a new value
    std::cout << name.at(0); //display the first index
    name.insert(0,"@"); //@Bro Code;
    std::cout << name.find(' '); // Find the index of the specific argument
    std::cout << name.erase(0,3); // Inclusive erase

    return 0;
}