#include <iostream>

int main() {
// For Loop

    bool isTomGay = false;

    for (int i = 1; i <= 15; i++) {
        std::cout << "Happy New Year!" << '\n';
        if (isTomGay) {
            break;
        }
        if (i == 13 ) {
            continue;
        }
    }

    return 0;
}