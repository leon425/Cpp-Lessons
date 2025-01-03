#include <iostream>
#include <vector>
#include <time.h>

void swapVar(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

// For first element pivoting
void quickSortHelper(std::vector<int>& list, int l, int h) {
    int pivot = list[l]; // Currently, the pivot is the first element
    int i = l+1; // i point to the second element
    int j = h; // j point to the last element

    // Base Case
    if (l>=h) return;

    while (i <= j) { // i <= j
        while (list[i] <= pivot && i <= h) {
            i++;
        }
        while (list[j] > pivot && j > l) {
            j--;
        }
        if (i < j) { //This is still necessary because it's possible that i > j in this point. if (i <= j) is invalid because there's no point of
                    //  swaping if they point to the same element
            swapVar(list[i],list[j]);
        }
    }

    // Swap the pivot with j
    swapVar(list[l], list[j]);

    quickSortHelper(list,l,j-1);
    quickSortHelper(list,j+1,h);
}

// For random element pivoting
void quickSortHelper2(std::vector<int>& list, int l, int h) {
    // Base Case
    if (l>=h) return;


    int pivotIndex = l + rand() % (h-l+1); // random pivot between l & h
    int pivot = list[pivotIndex]; // Currently, the pivot is the first element
    int i = l; // i point to the second element
    int j = h; // j point to the last element

    // Move the pivot to the first element
    swapVar(list[pivotIndex],list[l]);
    pivotIndex = l;

    while (i <= j) { // i <= j
        while (list[i] <= pivot && i <= h) {
            i++;
        }
        while (list[j] > pivot && j > l) { //while (list[j] > pivot && j > l) {
            j--;
        }
        if (i < j) {  // if (i <= j) is invalid because there's no point of swapping the same element
            swapVar(list[i],list[j]);
        }
    }

    // Swap the pivot with j
    swapVar(list[pivotIndex], list[j]);

    quickSortHelper2(list,l,j-1);
    quickSortHelper2(list,j+1,h);
}

// For random element pivoting - ChatGPT version (different two pointer method)
void quickSortHelper3(std::vector<int>& list, int l, int h) { 
    // Base case
    if (l >= h) return;

    // Random pivot selection
    int pivotIndex = l + rand() % (h-l+1); // random pivot between l & h
    int pivot = list[pivotIndex];

    // Move pivot to the end for easier partitioning
    swapVar(list[pivotIndex], list[h]);
    pivotIndex = h;

    // Partitioning
    int i = l;
    for (int j = l; j < h; j++) {
        if (list[j] <= pivot) {
            swapVar(list[i], list[j]);
            i++;
        }
    }

    // Place pivot in its correct position
    swapVar(list[i], list[pivotIndex]);

    // Recursively sort subarrays
    quickSortHelper3(list, l, i - 1);
    quickSortHelper3(list, i + 1, h);
}

std::vector<int> quickSort(std::vector<int> list) {
    srand(time(NULL));
    std::vector<int> result = list;
    // quickSortHelper(result,0,result.size()-1); // first element pivot
    quickSortHelper2(result,0,result.size()-1);
    return result;
}

int main() {
    std::vector<int> list = {10,7,6,4,6,5,3,5,6,12,345,5,6,3,2,5}; //{9,3,7,6,4,8,2};
    std::vector<int> result = quickSort(list);

    for (int i = 0; i<result.size(); i++) {
        std::cout << result[i] << ", ";
    }
    std::cout << '\n';


    return 0;
}

// Random Pivot
// Simplicity: Selecting a random element is straightforward and easy to implement.
// Efficiency: It avoids the specific worst-case scenarios (like sorted or reverse-sorted input) by introducing randomness.
// Average-Case Optimality: Although not as robust as the median of three, random pivoting performs well in most practical scenarios.
// it’s easy to code and ensures O(nlogn) average performance for any input distribution.

// Deterministic Pivot
// susceptible to worst-case performance for certain data distributions 