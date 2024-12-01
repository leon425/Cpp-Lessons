#include <iostream>
#include <utility>

// Recursion Method
std::string helper(std::string str, int index, int first = -1, int last = -1, bool condition = false, std::string result = " ") { 
    // Note:
    // Bool condition false = odd check
    // Bool condition true = even check

    // Guarantee : length > 1 & index < length()-1
    
    // First initialization of first & last. the condition of initialization if always false because we first are doing the odd check
    if (first == -1 && index > 0) {
        first = index-1;
    } 
    if (last == -1) {
        last = index+1;
    }
    
    // Odd Check
    if (condition == false && str[first] == str[last] && index > 0) {
        result = str.substr(first,last-first+1);
        if (first-1 >= 0 && last+1 < str.length()) {
            return helper(str,index,first-1,last+1, false,result);
        }
    } 

    // First initialization in even check
    if (condition == false) {
        last = index+1;
        first = index;
    }

    // Even Check
    if (str[first] == str[last]) {
        result = str.substr(first,last-first+1);
        if (first-1 >= 0 && last+1 < str.length()) {
            return helper(str,index,first-1,last+1,true, result);
        }
        if (last-index+1 > result.length()) {
            result = str.substr(index,last);
        }
    }

    return result;
}

std::string longest(std::string str) {
    std::string result = " ";
    std::string temp;
    if (str.length() == 1) {
        return str;
    } else if (str.length() == 0) {
        return "";
    }
    for (int i=0;i<str.length()-1;i++){
        temp = helper(str,i);
        if (result.length() < temp.length()) {
            result = temp;
        }

    }

    if (result == " ") {
        result = str[0];
    }
    return result;
}

// Iterative Method (Two Pointer)
std::string longest2(std::string str) {
    std::string result = "";
    int resultLength = 0;

    for (int i=0;i<str.length();i++) {
        // odd check
        int l = i;
        int r = i;
        while (l >= 0 && r < str.length()) {
            if (str[l] == str[r] && r-l+1 > resultLength) {
                result = str.substr(l,r-l+1);
                resultLength = r-l+1;
            }
            l--;
            r++;
        }

        // even check
        l = i;
        r = i+1;
        while (l >= 0 && r < str.length()) {
            if (str[l] == str[r] && r-l+1 > resultLength) {
                result = str.substr(l,r-l+1);
                resultLength = r-l+1;
            }
            l--;
            r++;
        }
    }
    return result;
}

int main() {
    std::cout << longest2("babad") << '\n';
    //std::cout << helper("cdbbcd",1) << '\n';
    return 0;
}