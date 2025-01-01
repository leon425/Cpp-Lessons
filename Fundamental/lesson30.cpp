#include <iostream>
#include <vector>

// Vector Function = Dynamic Array that can grow and shrink during compile time

// Vector Slicing Function (Exclusive)
std::vector<int> sliceVector(const std::vector<int>& vec, int start, int end) {
    // Use the range constructor of std::vector to create a slice
    return std::vector<int> (vec.begin() + start, vec.begin() + end); 
}

int main() {
    std::vector<std::string> foods = {"grapes","lemons"};
    foods.push_back("Tortilla"); //push a new element and grow the size

    // Insert at specific element
    foods.insert(foods.begin(),"Chips"); // insert in the first element of the vector
    foods.insert(foods.begin()+3,"Pineapple"); // insert at index 3

    // vec.begin() returns an iterator to te first element in the vector.

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

    // Resizing a 2D vector can be achieved by resizing the row first, then loop each row to resize the column. However, there is an alternative
    // to do it in 1 step. 
    std::vector<std::vector<int>> list1;
    list1.resize(5,std::vector<int>(2,0)); //list1.resize(row,std::vector<int>(column,0));   // Note: 0 is the initial value.
    // or
    std::vector<std::vector<int>> list2(5,std::vector<int>(2,0));  //std::vector<std::vector<int>> list2(row,std::vector<int>(column,0));


    return 0;
}

// Notes: Use size()
// sizeof() wont work on std::vector because ....

// Notes: erasing the first element in the vector requires O(n) times because all the elements left in the vector must be shifted left. erasing the
// last element of the vector does indeed takes O(1)
