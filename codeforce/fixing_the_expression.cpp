#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fixing(int length, std::vector<std::string> &list) {
    int num1;
    int num2;
    char expression;
    for (int i=0;i<list.size();i++) {
        num1 = list[i][0] - '0';
        num2 = list[i][2] - '0';
        expression = list[i][1];

        if (expression == '=') {
            if (num1 == num2) {
                continue;
            } else {
                list[i] = std::to_string(num1)+'='+std::to_string(num1);
            }
        } else if (expression == '<') {
            if (num1 < num2) {
                continue;
            } else if (num1 > num2) {
                list[i] = std::to_string(num1)+'>'+std::to_string(num2);
            } else {
                 list[i] = std::to_string(num1)+'='+std::to_string(num2);
            }
        } else if (expression == '>') {
            if (num1 > num2) {
                continue;
            } else if (num1 < num2) {
                list[i] = std::to_string(num1)+'<'+std::to_string(num2);
            } else {
                 list[i] = std::to_string(num1)+'='+std::to_string(num2);
            }
        }
    }
    return list;
}

int main() {
    std::vector<std::string> list = {};
    int length;

    std::cin >> length;

    list.resize(length);

    for (int i=0; i<length; i++) {
        std::cin >> list[i];
       
    }

    std::vector<std::string> updatedList = fixing(length,list);

    for (int i=0; i<length; i++) {
        std::cout << updatedList[i] << '\n';
    }


    return 0;
}