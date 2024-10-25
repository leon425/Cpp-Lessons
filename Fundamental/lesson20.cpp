#include <iostream>

int main() {
// fill() = fills a range of elements with a specified value
            // fill(begin,end,value)

    const int size = 10;
    std::string foods[size];
    
    // Fill the foods to 5 pizza and 5 burger. the size must be the less or the same as the max size of the array. Otherwise, it won't work
    fill(foods, foods + size/2, "pizza"); //exclusive ending
    fill(foods + size/2 , foods+size, "burger");

     for(std::string food : foods) {
        std::cout << food << ", ";
     }

    return 0;
}