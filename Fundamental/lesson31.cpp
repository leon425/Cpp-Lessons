#include <iostream>
#include <vector>
#include <algorithm>

class Ratio {
    public:
    int index;
    int ratio;

    Ratio() {
        index = 0;
        ratio = 0;
    }

    Ratio(int index, int ratio) {
        this->index = index;
        this->ratio = ratio;
    }
};

int main() {
    // First Example
    std::vector<Ratio> objects = {
        Ratio(0,4),
        Ratio(1,6),
        Ratio(2,1),
        Ratio(3,3)
    };

    std::sort(objects.begin(), objects.end(), [](const Ratio& a, const Ratio& b) { 
        // Passing constant reference of 'Ratio' type as comparison (it's a comparator function). It's a good practice to use 'const' because you
        // are not modifying the variable. You're just comparing it. Use '&' because you want to pass by reference, instead of copying it. It's
        // a good practice since it would be inefficient for large object.
        return a.ratio > b.ratio; // Descending Order. a is first, b is last. a is greater than b
    });

    for (int i=0;i<objects.size();i++) {
        std::cout << "Index: " << objects[i].index << "  Ratio: " << objects[i].ratio << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';


    // Second Example
    std::vector<int> num = {4,3,6,2,5,15,6};
    num.resize(num.size());

    // std::sort(num.begin(),num.end()); // Default is ascending Order
    std::sort(num.begin(),num.end(), [](int a, int b) { // Ascending order by passing custom function
        return a < b;
    });

    for (int i=0;i<num.size();i++) {
        std::cout << num[i] << ", ";
    }
    std::cout << '\n';

    return 0;
}