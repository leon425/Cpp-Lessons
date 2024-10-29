#include <iostream>
#include <string>
#include <algorithm>

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
    name.push_back('!'); // add a single character

    // Find
    std::cout << name.find(' '); // Find the index of the specific argument
    // If it's not found, then it will return std::string::npos

    std::cout << name.erase(1,3); // Inclusive erase. The last argument means how many do you want to delete.

    // Reverse -> #include <algorithm>
    std::reverse(name.begin(),name.end());

    //count -> #include <algorithm>
    std::count(name.begin(),name.end(),'ab');

    return 0;
}