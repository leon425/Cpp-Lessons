#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> q;
    q.push(5);
    q.push(100);
    std::cout << q.top() << '\n';
    // q.pop();

    // Printing the whole queue
    while (!q.empty()) {
        std::cout << q.top() << '\n';
        q.pop();
    }

    return 0;
}