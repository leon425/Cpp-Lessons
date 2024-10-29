#include <iostream>
#include <string>
#include <sstream>

int main() {

    // int t;
    // int n = 809;

    // t = n;
    // n = 8;
    // std::cout << t << '\n';
    // t = 10;
    // std::cout << n << '\n';

    for (int i = 1; i<11; i++) {
        if (i == 2) {
            i += 1;
            continue;
        }
        std::cout << i << '\n';
    }
    double num = 2.5;
    std::cout << std::to_string(num) << '\n';

    std::string word = "abcbc";
    std::cout << word.find("c") << '\n';

    double operationResult = -3.1459;
    std::ostringstream oss;
    oss.precision(3); // set precision to 3 decimal places
    oss << std::fixed << operationResult;
    std::string result = oss.str();
    std::cout << result << '\n';

    return 0;
}