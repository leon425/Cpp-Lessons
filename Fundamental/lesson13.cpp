#include <iostream>
#include <vector>

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

std::vector<int> nums = {1, 5, 3};
    auto it = nums.begin();
    ++it; // Increment iterator, now it points to the second element (2).
    std::cout << *it << std::endl; // Output: 2

// i++ vs ++i
// The increment operation itself is being used in an expression within the loop body or elsewhere.
// Performance considerations for complex iterators (e.g., in custom iterator classes, where i++ might involve creating a temporary object).
// The performance difference between i++ and ++i only matters when working with complex iterators or objects, where the post-increment operator (i++) might create a temporary copy.
// For primitive types like int in a for loop, both operations are optimized by modern compilers to be equally efficient.
// Because of this, developers often prioritize readability (i++) over theoretical efficiency (++i).

// Iterator
// Iterators are like pointers to elements in a container.
// When you erase an element from a container, the container removes that element and adjusts its internal structure.
// This adjustment invalidates the iterator pointing to the erased element.
    return 0;
}