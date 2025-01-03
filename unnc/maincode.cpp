#include "maincode.h"
#include <iostream>

#include <vector>

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
