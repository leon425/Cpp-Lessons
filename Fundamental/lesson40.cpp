#include <iostream>
#include <unordered_set>
#include <set>

/*
std::unordered_set - Based on hash function
Insert, find, erase : O(1) 

std::set - Based on a balanced binary search tree (e.g Red-Black Tree)
Insert, find, erase : O(log n)
*/

// Custom hash function in std::unordered_set
struct pair_hash {
    
};

int main() {
    std::unordered_set<int> mySet;
    mySet.insert(5);
    // check if an element exist
    if (mySet.find(10) != mySet.end()) {
        std::cout << "10 is found" << '\n';
    } else {
        std::cout << "10 is not found" << '\n';
    }

    // display set elements (without order)
    for (int x : mySet) {
        std::cout << x << " ";
    }
    std::cout << '\n';

    std::set<int> mySet2; 
    // The rest of the implementation is the same as std::unordered_set



    return 0;
}