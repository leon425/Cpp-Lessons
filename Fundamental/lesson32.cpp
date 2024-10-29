#include <iostream>
#include <string>
#include <sstream>

int main() {
    int num = 10;
    double result = static_cast<double>(num) / 3;

    // Convert int to string
    std::string s = std::to_string(42);

    // Convert string into int (without compile time error if failure). // must #include <string>
    std::string str = "abc";
    try {
       int num = std::stoi(str); 
       std::cout << "Converted " << num << '\n';// if the 
    } catch (const std::invalid_argument&) {
        std::cout << "Failed" << '\n';
    }

    // Convert string to a double // #include <string>
    std::string word = "3.14159";
    double nummy = std::stod(word);

    // Convert double to string . Can use to_string, however will generate too many digit.
    // Recommended to use std::ostringstream
    // #include <sstream>    
    double number = 3.1459;
    std:: ostringstream oss;
    oss.precision(2); // set precision to 2 decimal places
    oss << std::fixed << number;
    std::string final = oss.str();
    std::cout << final << '\n';


    return 0;
}