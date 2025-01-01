#include <iostream>
#include <list>

int main() {
    // Create a linked list of integers
    std::list<int> linkedList;

    // Insert elements into the list
    linkedList.push_back(10); // Add at the end
    linkedList.push_front(5); // Add at the beginning

    // Traverse and print the list
    std::cout << "Linked list elements: ";
    for (int value : linkedList) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Remove an element
    linkedList.pop_front(); // Remove from the beginning
    linkedList.pop_back();

    // Insert at a specific position
    auto it = linkedList.begin();
    std::advance(it, 1); // Move iterator to the second position
    linkedList.insert(it, 15); // Insert 15 before the second element



    return 0;
}
