#include <iostream>
#include <vector>

std::vector<int> mergeSort(std::vector<int> list, int l = -1, int h = -1) {
    std::vector<int> arr3;

    if (l == -1) {
        l = 0;
    }
    if (h == -1) {
        h = list.size()-1;
    }

    if (l == h) {
        return {list[l]};
    }

    if (l < h) {
        int mid = (l + h)/2;

        // Start the mergeSort;
        std::vector<int> arr1 = mergeSort(list,l,mid);   //sliceVector(list, l, mid+1); 
        std::vector<int> arr2 = mergeSort(list,mid+1,h); //sliceVector(list,mid+1, h+1);

        // Manually resize the arr3 because at first, it has 0 size. In the future, it will have the size of combined arr1 & arr2
        int i = 0, j = 0;
        arr3.resize(arr1.size() + arr2.size());

        int k = 0;
        while (i <= arr1.size()-1 && j <= arr2.size()-1) {
            if (arr1[i] < arr2[j]) {
                arr3[k++] = arr1[i++];
            } else {
                arr3[k++] = arr2[j++];
            }
        }
        // Append the remaining element from arr1 (if any)
        while (i < arr1.size()) {
            arr3[k++] = arr1[i++];
        }
        // Append the remaining element form arr2 (if any)
        while (j < arr2.size()) {
            arr3[k++] = arr2[j++];
        }
    } 
    return arr3;
}  


int main() {
    std::vector<int> list = {2, 15, 7, 8, 23, 10, 12, 37, 4, 17, 18, 20, 9, 25, 14};

    // Don't do this (Calling the mergeSort twice)
    // for (int i;i<mergeSort(list).size();i++) {
    //     std::cout << mergeSort(list)[i] << ", ";
    // }
    // std::cout << '\n' << "hmmm";

    std::vector<int> sortedList = mergeSort(list);
    for (int i = 0; i<sortedList.size(); i++) {
        std::cout << sortedList[i] << ", ";
    }
    std::cout << '\n';
    

    return 0;
}