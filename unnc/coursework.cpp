#include <iostream>
#include <vector>

// Haven't learn about import
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
    return list[0];
}

std::vector<int> tail(std::vector<int> list) {
    list.erase(list.begin());
    return list;
}

int min(int a, int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}

int findSmallest(std::vector<int> list) {
    if (isEmpty(tail(list))) {
        return value(list);
    } else {
        return min(value(list),findSmallest(tail(list)));
    }
}

std::vector<int> removeSmallestHelper(std::vector<int> list, int x) {
    if (value(list) == x) {
        return tail(list);
    } else {
        return cons(value(list), removeSmallestHelper(tail(list),x));
    }
}

std::vector<int> removeSmallest(std::vector<int> list) {
    std::vector<int> result = {};
    if (isEmpty(list)) {
        return result;
    } else {
        return removeSmallestHelper(list, findSmallest(list));
    }
}

int sqrtHelper(int x, int multiplicand) {
    if (multiplicand*multiplicand > x || x < 0) {
        return -1;
    } else if (multiplicand * multiplicand == x) {
        return multiplicand;
    } else {
        return sqrtHelper(x,multiplicand+1);
    }
}

int sqrt(int x) {
    return sqrtHelper(x,0);
}

int findNextSquare(int x) {
    int num = sqrt(x);
    if (num == -1) {
        return -1;
    } else {
        return (num+1)*(num+1);
    }
}

int findSumHelper(int x, int n) {
    if (x <= 1 || n >= x) {
        return 0;
    } else {
        return n + findSumHelper(x, findNextSquare(n));
    }
}

int findSum(int x) {
    return findSumHelper(x,1);
}

std::vector<int> noSquareListHelper(int n, int counter) {
    if (n <= 2 || counter == n) {
        return {};
    } else {
        if (sqrt(counter) != -1) {
            return noSquareListHelper(n,counter+1);
        } else {
            return cons(counter,noSquareListHelper(n,counter+1));
        }
    }
}

std::vector<int> noSquareList (int n) {
    return noSquareListHelper(n,2);
}

int length(std::vector<int> list) {
    if (isEmpty(list)) {
        return 0;
    }
    return 1 + length(tail(list));
}

std::vector<int> sliceListHelper(std::vector<int> list, int start, int end, int length) {
    if (start > end || start <= 0 || end <= 1 || end > length+1) {
        return {};
    }
    if (end == 2) {
        return cons(value(list),{});
    }
    if (start == 1) {
        return cons(value(list),sliceListHelper(tail(list),start,end-1,length));
    } else {
        return sliceListHelper(tail(list),start-1,end-1,length);
    }
}

// index starts at 1 and not 0
std::vector<int> sliceList(std::vector<int> list, int start, int end) {
    return sliceListHelper(list,start,end,length(list));
}

int main() {
    // std::vector<int> result = removeSmallest({90,43,1,2,3,43});
    // for (int i=0; i<result.size();i++) {
    //     std::cout << result[i] << " ";
    // }
    // std::cout << '\n';

    // std::cout << findNextSquare(-1) << '\n';
    // std::cout << sqrt(-1) << '\n';
    std::cout << findSum(20) << '\n';

    // std::vector<int> result2 = noSquareList(0);
    // for (int i=0; i<result2.size();i++) {
    //     std::cout << result2[i] << " ";
    // }
    // std::cout << '\n';
   
    std::vector<int> vec = {1,2,3,4,5,6,7};
    std::vector<int> slicedVector = sliceList(vec,3,7);
    for (int i=0; i<slicedVector.size();i++) {
        std::cout << slicedVector[i] << " ";
    }
    std::cout << '\n';

    return 0;
}