#include <iostream>
//#include "maincode.h"
#include <vector>
#include <utility>

// To run the file:
// cd "c:\Users\bleon\OneDrive\Programming\c++\unnc\" ; if ($?) { g++ insertionSort.cpp maincode.cpp -o insertionSort } ; if ($?) { .\insertionSort }  

// Alternative Way
// g++ insertionSort.cpp maincode.cpp -o insertionSort
// Random knowledge on running an exe: program.exe. ./program.exe


// Note : Index start at 1 and not 0
std::vector<int> cons(int x, std::vector<int> list) {
    list.insert(list.begin(),x);
    return list;
}

bool isEmpty(std::vector<int> list) {
    if (list.size() == 0) {
        return true;
    } 
    return false;
}

int value(std::vector<int> list) {
    if (!isEmpty(list)) {
        return list[0];
    }
    throw std::runtime_error("List is Empty");
}

std::vector<int> tail(std::vector<int> list) {
    if (!isEmpty(list)) {
        list.erase(list.begin());
        return list;
    }
    throw std::runtime_error("List is Empty");
}


// Modified Function
int length(std::vector<int> list) {
    if (isEmpty(list)) {
        return 0;
    }
    return 1 + length(tail(list));
}

int getNth(int n, std::vector<int> list) {
    if (n == 1) {
        return value(list);
    } else {
        return getNth(n-1,tail(list));
    }
}

std::vector<int> delNth(int n, std::vector<int> list) {
    if (n == 1) {
        return tail(list);
    } else {
        return cons(value(list),delNth(n-1,tail(list)));
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}


// Delete a list from i to j (Reverse slice)
std::vector<int> cut(std::vector<int> list, int i, int j) {
    if (i == j) {
        return delNth(i,list);
    } else {
        return cut(delNth(i,list),i,j-1);
    }
}

// Power 
int power(int num, int exponent) {
    if (exponent == 1) {
        return num;
    } else {
        return num * power(num, exponent-1);
    }
}

// Binary Search
bool binSearch(int x, std::vector<int> list) {
    // mid = n/2 + 1 
    int n = length(list);
    if (getNth(n/2+1,list) == x) {
        return true;
    } 
    if (n == 1) {
        return false;
    }
    if (getNth(n/2+1, list) < x) { // move to the right
        return binSearch(x, cut(list,1,n/2+1));
    } else { // move to the left
        return binSearch(x, cut(list, n/2+1, n));
    }
    
}

// TBC -> I was Lazy. Just look at the lecture slide week 5 - introduction to algorithm. You get the point.

// std::vector<int> insert(std::vector<int> list, int x) {
//     if (isEmpty(list)) {
//         return cons(x,list);
//     } else if (value(list))
// }

// Merge Sort
std::pair<std::vector<int>, std::vector<int>> split(std::vector<int> list) {
    std::vector<int> emptyList = {};
    // The base case will return pair with the type of list (vector). It needs to be list because in the end, we will create a list
    if (isEmpty(list)) {
        std::pair<std::vector<int>, std::vector<int>> pair(emptyList,emptyList);
        return pair;
    }
    if (isEmpty(tail(list))) {
        std::pair<std::vector<int>, std::vector<int>> pair(list,emptyList);
        return pair;
    }
    int x = value(list);
    int y = value(tail(list));

    std::vector<int> l1 = split(tail(tail(list))).first;
    std::vector<int> l2 = split(tail(tail(list))).second;
    std::pair<std::vector<int>, std::vector<int>> pair(cons(x,l1),cons(y,l2));
    
    return pair;
}

std::vector<int> merge(std::vector<int> l1, std::vector<int> l2) {
    // Base Case
    if (isEmpty(l1)) {
        return l2;
    }
    if (isEmpty(l2)) {
        return l1;
    }

    if (value(l1) <= value(l2)) {
        return cons(value(l1),merge(tail(l1),l2));
    } else {
        return cons(value(l2),merge(l1,tail(l2)));
    }
}

std::vector<int> mergeSort(std::vector<int> list) {
    // Base Case
    if (isEmpty(list) || isEmpty(tail(list))) { // if list is already sorted
        return list;
    }
    std::vector<int> l1 = split(list).first;
    std::vector<int> l2 = split(list).second;
    return merge(mergeSort(l1),mergeSort(l2)); // the recursive steps is in the splitting, then merging
}

// Least Common Multiple (LCM)
int lcmHelper(int x, int y, int n) {
    if (x*n % y == 0) {
        return x*n;
    } else {
        return lcmHelper(x,y,n+1);
    }
}

int lcm(int x, int y) {
    return lcmHelper(x,y,1);
}

// Power of 10
int powerten(int n) { // only works for above 0 value of n
    if (n == 0) { // The correct basecase is n == 0 because if it's n == 1, then it won't cover the n == 0 and hence, goes to infinite loop
        return 1;
    } else {
        return 10*powerten(n-1);
    }
}

// List2Num
int list2numHelper(std::vector<int> list, int count) {
    if (isEmpty(tail(list))) {
        return value(list);
    } else {
        return value(list)*powerten(count) + list2numHelper(tail(list), count-1);
    }
}

int list2num(std::vector<int> list) {
    return list2numHelper(list,length(list)-1);
}

// maxList
int maxListHelper(std::vector<int> list, int maxNum) {
    if (isEmpty(list)) {
        return maxNum;
    }
    if (value(list) > maxNum) {
        maxNum = value(list);
    }
    return maxListHelper(tail(list),maxNum);
}

int maxList(std::vector<int> list) {
    return maxListHelper(tail(list),value(list));
}

// concat 
std::vector<int> concat(std::vector<int> l1, std::vector<int> l2) {
    if (isEmpty(tail(l1))) {
        return cons(value(l1),l2);
    } else {
        return cons(value(l1),concat(tail(l1),l2));
    } 
}

// Insert Num
std::vector<int> insertNum(int num, int index, std::vector<int> list) {
    if (index == 1) {
        return cons(num,list);
    } else {
        return cons(value(list),insertNum(num,index-1,tail(list)));
    }
}

// Subset
bool subsetHelper(std::vector<int> l1, std::vector<int> l2, std::vector<int> fixedl2) {
    if (isEmpty(l2)) {
        return false;
    }
    if (isEmpty(l1)) {
        return true;
    } else {
        if (value(l1) == value(l2)) {
            // go to tail(l1) and l2
            return subsetHelper(tail(l1),fixedl2,fixedl2);
        } else {
            return subsetHelper(l1,tail(l2),fixedl2);
        }
    }
}

bool subset(std::vector<int> l1, std::vector<int> l2) {
    return subsetHelper(l1,l2,l2);
}

// Fake Log - need helper function for counter & sub-algorithm 'power(n)'
int fakeLogHelper(int x, int y, int counter, int fixedX) {
    if (x > y) {
        return counter-1; // take one step back to the previous recursion
    } else { // if (x =< y)
        return fakeLogHelper(power(fixedX,counter+1),y,counter+1,fixedX);
    }
}

int fakeLog(int x, int y) {
    if (x > y) {
        return 0;
    }
    return fakeLogHelper(x,y,1,x);
}

// Slice (inclusive) // start from index 1
std::vector<int> slice(std::vector<int> list, int start, int end) {
    if (start == 1 && end == 1) {
        return cons(value(list),{});
    } else if (start == 1 && end > 1) {
        return cons(value(list),slice(tail(list),start,end-1));
    } else {
        return slice(tail(list),start-1,end-1);
    }
}

// MergeSort 2nd version
std::vector<int> mergeSort2(std::vector<int> list) {
    if (isEmpty(tail(list)) || isEmpty(list)) {
        return list;
    } else {
        int mid = length(list)/2+1;
        std::vector<int> list1 = slice(list,1,mid-1);
        std::vector<int> list2 = slice(list,mid,length(list));
        return merge(mergeSort2(list1),mergeSort2(list2));
    
    }
}

int main() {
    std::vector<int> list = {4,5,2,3,1};
    std::vector<int> list2 = {2,9,8,5,7,4,3};
    std::vector<int> sortedList = {1,2,5,7,9,12,35,39};
    std::vector<int> sortedList2 = {3,6,7,8,9,12,17,23,27};
    // std::cout << length(list) << '\n';
    std::vector<int> result = cut(list2,3,6);

    // for (int i = 0;i<result.size();i++) {
    //     std::cout << result[i] << '\n';
    // }

    std::cout << binSearch(2,sortedList) << '\n';

    // Split sub-algorithm
    // First
    std::cout << "First Splitted List : ";
    for (int i=0; i<split(list2).first.size(); i++) {
        std::cout << split(list2).first[i] << " ";
    }
    std::cout << '\n';

    // Second
    std::cout << "Second Splitted List : ";
    for (int i=0; i<split(list2).second.size(); i++) {
        std::cout << split(list2).second[i] << " ";
    }
    std::cout << '\n';

    // Merge sub-algorithm
    std::vector<int> mergeResult = merge(sortedList, sortedList2);
    for (int i=0; i<mergeResult.size(); i++) {
        std::cout << mergeResult[i] << " ";
    }
    std::cout << '\n';

    // MergeSort algorithm
    std::vector<int> mergeSortResult = mergeSort(list2);
    for (int i=0; i<mergeSortResult.size(); i++) {
        std::cout << mergeSortResult[i] << " ";
    }
    std::cout << '\n';

    // LCM algorithm
    std::cout << lcm(5,10) << '\n';

    // powerten algorithm
    std::cout << powerten(0) << '\n';

    // list2num algorithm
    std::cout << list2num({3,4,2,1}) << '\n';

    // maxList algorithm
    std::cout << maxList({6,5,7,81,1,12,13}) << '\n';

    // concat algorithm
    std::vector<int> result3 = concat({2,3,4},{5,6,7});
    for (int i=0; i<result3.size(); i++) {
        std::cout << result3[i] << " ";
    }
    std::cout << '\n';

    // insertNum algorithm
    std::vector<int> result4 = insertNum(10,4,{1,2,3,4,5,6,7,8,9});
    for (int i=0; i<result4.size(); i++) {
        std::cout << result4[i] << " ";
    }
    std::cout << '\n';

    // Power
    std::cout << power(2,4) << '\n';

    // fakeLog Algorithm
    std::cout << fakeLog(4,4) << '\n';

    // subset Algorithm
    std::cout << subset({8,5,4},{5,4,2,8,1}) << '\n';

    // slice (inclusive) (from index 1) Algorithm
    std::vector<int> result5 = slice({7,9,3,2,5,1,4,7,8},1,4);
    for (int i=0; i<result5.size(); i++) {
        std::cout << result5[i] << " ";
    }
    std::cout << '\n';

    // MergeSort2 Algorithm
    std::vector<int> result6 = mergeSort2({7,9,3,2,5,1,4,7,8});
    for (int i=0; i<result6.size(); i++) {
        std::cout << result6[i] << " ";
    }
    std::cout << '\n';

    std::cout << "Hellohh" <<'\n';


    return 0;
}