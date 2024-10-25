#include <iostream>
#include <vector>

void swapVar(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void quickSort(std::vector<int>& list, int l, int h) {
    // if (l == -1) {
    //     l = 0;
    // } 
    // if (h == -1) {
    //     h = list.size()-1;
    // }

    int pivot = list[l];
    int i = l+1, j = h;

    if (l>=h) {
        return;
    }

    while (i <= j) { // i <= j
        while (list[i] <= pivot && i <= h) {
            i++;
        }
        while (list[j] > pivot && j > l) {
            j--;
        }
        if (i <= j) { //This is still necessary because it's possible that i > j in this point.
            swapVar(list[i],list[j]);
        }
    }
    // Swap the pivot with j

    swapVar(list[l], list[j]);

    quickSort(list,l,j-1);
    quickSort(list,j+1,h);
    

}

int main() {
    std::vector<int> list = {10,7,6,4,6,5,3,5,6,12,345,5,6,3,2,5}; //{9,3,7,6,4,8,2};
    quickSort(list,0,list.size()-1);

    for (int i = 0; i<list.size(); i++) {
        std::cout << list[i] << ", ";
    }
    std::cout << '\n';


    return 0;
}