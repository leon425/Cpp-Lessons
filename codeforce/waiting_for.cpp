#include <iostream>
#include <vector>
#include <utility>

std::vector<bool> wait(int length, std::vector<std::pair<char,int>> list) {
    std::vector<bool> result = {};
    int count = 0;

    for (int i=0;i<length;i++) {
        if (list[i].first == 'P') {
            count += list[i].second;
        } else if (list[i].first == 'B') {
            count -= list[i].second;
            if (count <= -1) { // there are space left
                result.push_back(true);
                count = 0;
            } else {
                result.push_back(false);
            }
        } 
    }
    return result;

}

int main() {
    int length;
    std::vector<std::pair<char,int>> list;
    std::cin >> length;
    
    for (int i=0; i<length; i++) {
        char operation;
        int value;
        std::cin >> operation >> value;
        list.push_back({operation,value});
    }

    std::vector<bool> final = wait(length,list);
    for (int i=0; i<final.size(); i++) {
        if (final[i] == true) {
            std::cout << "YES" << '\n';
        } else {
            std::cout << "NO" << '\n';
        }
    }


    return 0;
}