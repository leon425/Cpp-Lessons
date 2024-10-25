#include <iostream>

    // O(n/2)
    // int mySqrFailed(int x) {
    //     int mid;
    //     //Find the middle
    //     if (x >= 2) {
    //        mid = x/2;
    //     } else if (x == 1) {
    //         return 1;
    //     } else {
    //         return 0;
    //     }

    //     // Check the middle
    //     if (mid*mid == x) {
    //         return mid;
    //     }

    //     // Go to the left
    //     if (mid*mid > x) {
    //         for (int i=mid; i>1; i--) {
    //             if ((i*i > x && (i-1)*(i-1) < x) || (i-1)*(i-1) == x) {
    //                 return (i-1);
    //             }
    //         }
    //     }

    //     // Go to the Right
    //     if (mid*mid < x) {
    //         for (int i = mid; i < x; i++) {
    //             if ((i*i < x && (i+1)*(i+1) > x) || i*i == x) {
    //                 return i;
    //             }
    //         }
    //     }
    // return mid;
    // };

int check(int x, int mid, int midMinusOne, int midPlusOne) {
    if (mid == x/mid || (mid < x/mid && midPlusOne > x/midPlusOne)) {
        return mid;
    } 
    else if (midMinusOne == x/midMinusOne || (mid > x/mid && midMinusOne < x/midMinusOne)) {
        return midMinusOne;
    }
    return -1;
};

// O(log(n))
int mySqrt(int x) {
    int mid;
    int lo;
    int hi;
    //Declaration
    if (x >= 2) {
        lo = 1;
        hi = x;
    } else {
        return x;
    }

    // Binary Search
    while (lo <= hi) {
        mid = lo + (hi-lo)/2; // to avoid overflow . can't use lo/2 + h/2 because of truncation
        // left
        if (mid > x/mid) {
            hi = mid-1;
        }
        // right
        else if (mid < x/mid) {
            lo = mid+1;
        }
        int result = check(x,mid,mid-1,mid+1);
        if (result != -1) {
            return result;
        }

    }
    return mid;

    };


//optimized version (without check function)
int mySqrtOptimized(int x) {
    // Edge cases
    if (x < 2) return x;

    int lo = 1, hi = x, mid;

    // Binary Search
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;

        // If mid*mid is exactly equal to x, we found the square root
        if (mid == x / mid) {
            return mid;
        }
        // If mid*mid is greater than x, move to the left half
        else if (mid > x / mid) {
            hi = mid - 1;
        }
        // If mid*mid is less than x, move to the right half
        else {
            lo = mid + 1;
        }
    }

    // When loop finishes, hi will be the floor of the square root
    return hi;
}

int main() {
    std::cout << mySqrt(4);
    
    return 0;
}

