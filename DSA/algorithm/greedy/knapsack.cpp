#include <iostream>
#include <vector>
#include <algorithm>

class KnapSackObject {
    public:
    int index;
    int profit;
    int weight;

    // Default Constructor
    // Required for dynamic memory allocation. Each element must have default value before any values are assigned.
    KnapSackObject() {
        index = 0;
        profit = 0;
        weight = 0;
    }

    // Parameterized Constructor
    KnapSackObject(int index, int profit, int weight) {
        this->index = index;
        this->profit = profit;
        this->weight = weight;
    }

    void display () {
        std::cout << "Index: " << index << "  Profit: " << profit << "  Weight: " << weight;
    }
};

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


void knapSack(KnapSackObject* objects, int size, int maxWeight) {

    // 1) Calculate the profit/weight ratio

    // If using dynamic array
    // Ratio* ratio = new Ratio[size]; // a pointer to a dynamic array of Ratio objects.\
    // delete[] ratio;

    std::vector<Ratio> ratio;
    ratio.resize(size);

    for (int i=0;i<size;i++) {
        // ratio[i] = objects[i].profit/objects[i].weight;
        ratio[i] = Ratio(i,objects[i].profit/objects[i].weight); // fill the array with Ratio   
    }

    // 2) Sort the ratio class
    std::sort(ratio.begin(), ratio.end(),[](const Ratio& a, const Ratio& b) {
        return a.ratio > b.ratio;
    });

    // 3) Fill the knapsack with the object
    int i = 0;
    double availableWeight = maxWeight;
    double profit = 0;
    double currentWeight;
    while(i < size) { // while maxWeight >= the next object's weight  
        currentWeight = objects[ratio[i].index].weight;
        if (availableWeight >= currentWeight) {
            availableWeight -= currentWeight;
            profit += objects[ratio[i].index].profit;
            i++;
        } else {
            break;
        }
    }

    if (availableWeight <= currentWeight && i < size) {
        profit += objects[ratio[i].index].profit*availableWeight/currentWeight;
        availableWeight = 0;
    }

    std::cout << "Profit: " << profit << " Available Weight: " << availableWeight << '\n';

}

int main() {
    int size = 7;
    int size2 = 5;

    // Dynamically allocating array of objects

    // Test Case 1
    KnapSackObject* objects = new KnapSackObject[size]{
        KnapSackObject(0,10,2),
        KnapSackObject(1,5,3),
        KnapSackObject(2,15,5),
        KnapSackObject(3,7,7),
        KnapSackObject(4,6,1),
        KnapSackObject(5,18,4),
        KnapSackObject(6,3,1)
    };

    // Test Case 2
    KnapSackObject* objects2 = new KnapSackObject[size2]{
        KnapSackObject(0,10,10),
        KnapSackObject(1,5,5),
        KnapSackObject(2,15,7),
        KnapSackObject(3,7,8),
        KnapSackObject(4,6,6),
    };

    // Display Objects
    // for (int i=0;i<size;i++) {
    //     objects[i].display();
    // }

    knapSack(objects,size,15);
    knapSack(objects2,size2,15);
    

    // Free allocated memory
    delete[] objects;
    delete[] objects2;


    return 0;
}