// Also known as Collatz Conjecture
// Relates to chaotic theory. Every integers, given the following operation will eventually reaches 1. However, its pattern and whether all 
// integers can be performed those calculations haven't been solved yet. It's still an open problem.

// Use this to learn recursion
// The count variable is passed as a parameter in the helping function

// Another non-purposeful algorithm is ackerman function - used to test the limit of time & space complexity of recursive function

#include <iostream>

int g(int x, int count) {
    if (x == 1) {
        return count;
    } else {
        if (x%2 == 0) {
            return g(x/2,count+1);
        } else {
            return g(1+x*3,count+1);
        }
    }
}

int f(int x){

    return g(x,0);
}

int main() {
    std::cout << "Operation done " << f(5) << " times";
    return 0;
}