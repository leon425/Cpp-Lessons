#include <iostream>
#include <deque>

int main() {
    std::deque<int> list; // double-ended queue. insert & delete element on both sides
    std::deque<int> list2(5,0); // creates a deque of size 5 with the elements of 0
    std::deque<int> list3 = {10,20,30};
    list.push_back(10); // 
    list.push_front(20); 
    list.pop_back();
    list.pop_front();
    list.front();
    list.back();
    list.empty();
    list.size();
    list.insert(list.begin()+2,25); // insert the value 25 on the second index
    list.erase(list.begin());
    list.clear(); // clear all elements
    list.resize(5,10); //resize to the size of 5 with every element of value 10
    return 0;
}