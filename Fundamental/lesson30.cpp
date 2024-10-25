#include <iostream>
#include <vector>

// Vector Function = Dynamic Array that can grow and shrink during compile time

// Vector Slicing Function (Exclusive)
std::vector<int> sliceVector(const std::vector<int>& vec, int start, int end) {
    // Use the range constructor of std::vector to create a slice
    std::vector<int> result(vec.begin() + start, vec.begin() + end);
    return result;
}

int main() {
    std::vector<std::string> foods = {"grapes","lemons"};
    foods.push_back("Tortilla"); //push a new element and grow the size

    std::cout << foods.size() << '\n';

    std::vector<int> ages;
    ages = {17,15,4};

    // Calculate the length
    std::size_t length = ages.size();

    // Delete / Erase
    ages.erase(ages.begin()); // delete index 0
    ages.erase(ages.begin() + 2);// delete index 2

    // Slice a vector (Using the function above)
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> slicedVector = sliceVector(vec, 2, 6);

    
    // Print the sliced vector
    for (int i : slicedVector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;


    return 0;
}

// Notes: Use size()
// sizeof() wont work on std::vector because ....
