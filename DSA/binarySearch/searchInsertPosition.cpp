#include <iostream>
#include <vector>

// 4 ms Beats 34.87%
int searchInsert(std::vector<int>& nums, int target) {
    std::size_t numsLength = nums.size(); 
    int mid;
    int hi = numsLength-1;
    int lo = 0;

    while (lo <= hi) {
        mid = lo + (hi-lo)/2;

        if (nums[mid] == target) {
            return mid;
        } else if (mid-1 >= 0 && nums[mid-1] < target && nums[mid] > target) {
            return mid;
        } else if (mid+1 < numsLength && nums[mid+1] > target && nums[mid] < target) {
            return mid+1;
        }

        // left
        if (nums[mid] > target) {
            hi = mid-1;
        }
        //right
        else if (nums[mid] < target) {
            lo = mid+1;
        }

    }

    return lo;
};

// 7 ms beat 22%
int searchInsertOptimized(std::vector<int>& nums, int target) {
    std::size_t numsLength = nums.size(); 
    int lo = 0;
    int hi = numsLength - 1; 
    int mid;

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;  // Move to the right side
        } else {
            hi = mid - 1;  // Move to the left side
        }
    }

    // If not found, `lo` is the correct insertion index
    return lo;
}

// 0ms beat 100% because when the target <= nums[0], it immediately return 0.
int searchInsertHighlyOptimized(std::vector<int>& nums, int target) {
    std::size_t numsLength = nums.size(); 
    int lo = 0;
    int hi = numsLength - 1; 
    int mid;

    if (target <= nums[0]) {
        return 0;
    }

    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            lo = mid + 1;  // Move to the right side
        } else {
            hi = mid - 1;  // Move to the left side
        }
    }

    // If not found, `lo` is the correct insertion index
    return lo;
}

int main() {
    std::vector<int> nums = {2,4,5,6,10,12,15,17,20,24,27,29,30};
    int target = 28;
    std::cout << searchInsert(nums,target) << '\n';
    std::cout << searchInsertOptimized(nums,target) << '\n';
    return 0;
}
