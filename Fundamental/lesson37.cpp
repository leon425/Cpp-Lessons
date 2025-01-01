#include <iostream>
#include <queue>

int main() {
    std::queue<int> q ;
    q.push(10);
    q.push(20);
    q.pop();
    q.empty();
    q.front();
    q.back();
    q.size();
}