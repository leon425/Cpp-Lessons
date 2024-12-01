#include <iostream>
#include <vector>
#include <algorithm>

// Submit the latest answer to leetcode
// Learn two pointer second method

// O(n^2)
std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::vector<int> result;

    if (nums.size() == 0 || nums.size() == 1) {
        return nums;
    }

    for (int i=0;i<nums.size();i++) {
        for (int j=i+0;j<nums.size()-1;j++) {
            if (nums[i] + nums[j+1] == target) {
                result.push_back(i);
                result.push_back(j+1);
                return result;
            }
        }
    }
    return result;
};

// Two Pointer O(n)
// Only works on sorted list. If we were to sort the list first, it's possible by using O(nlogn) sorting techniques
std::vector<int> twoSum2(std::vector<int> nums, int target) {
    std::vector numsCopy = nums;
    
    // Sort it First. 1 Problem: we need to refer to the original index. Make a for loop again
    // std::sort(nums.begin(),nums.end(), [](int a, int b) { // Ascending order by passing custom function
    //     return a < b;
    // });


    if (nums.size() == 0 || nums.size() == 1) {
        return nums;
    }

    std::vector<int> result;
    int front = 0;
    int back = nums.size()-1;
    int sum = 0;

    while (front < back) {
        sum = nums[front] + nums[back];

        if (sum == target) {
            result.push_back(front);
            result.push_back(back);
            break;
        } else if (sum < target) {
            front += 1;
        } else {
            back -= 1;
        }
    }

    // Refer to the original index by the original list

    return result;
};

int main() {
    std::vector<int> nums1 = {3,8,9,2,4,1,8,5,20};
    std::vector<int> nums2 = {2,4,5,7,9,13,17,19,22};
    
    std::vector<int> final = twoSum2(nums2,23);
    for (int i=0; i<final.size(); i++) {
        std::cout << final[i] << ", ";
    }

    return 0;
}