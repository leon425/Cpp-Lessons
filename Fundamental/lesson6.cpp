#include <iostream>
#include <string>

// in vscode, need to configure to run the code in the terminal
// file >> preferences >> settings >> search for "code runner" >> check the 'run in integrated terminal' checkbox
int main() {
// user input
    // cout << (insertion operator)
    // cin >> (extraction operator)

    std::string name;
    int age;

    std::cout << "What's your age?: ";
    std:: cin >> age; // this is integer. So, as always, if the value inputted is not an integer, it will be converted implicitly

    std::cout << "What's your name?: ";
    // std::getline(std::cin, name); // to be able to read the string that has spaces. must #include <string>
    // When you have cin, and then getline(), the input of getline accept the new line character in the previous cin. (Look at the code above.)
    // So the solution is to add 'std::cin >> std::ws'(Look at the code below). This line of code will remove all whitespaces or new line character before running the cin
    std::getline(std::cin >> std::ws, name);
    

    std::cout << "Hello " << name << '\n';
    std::cout << "You're " << age << " Years Old" << '\n';


    return 0;
}