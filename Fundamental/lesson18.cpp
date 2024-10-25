#include <iostream>

double getTotal(double prices[], int pricesLength);

int main() {
// foreach loop => Loop that eases the traversal 
    // over an iterable dataset (e.g array)
    // less syntax than for loop, but less flexible (can't go backward or skip an iteration)

    std::string foods[] = {"Burger", "Pizza", "BaoZi", "XiaoLongBao"};

    for(std::string food : foods) {
        std::cout << food << '\n';
    }

// Pass array to a function

    // When we pass an array into a function, it decays into a pointer. So, we're not working in the array anymore
    // We are working with the pointer (which is the address where the array begins). So, the function don't have any idea how long the array is.
    // The solution is to find out the size of the array outside the function

    double prices[] = {49,50,100};
    int pricesLength = sizeof(prices)/sizeof(double);

    getTotal(prices, pricesLength);


    return 0;
}

double getTotal(double prices[], int pricesLength) {
    double total = 0;

    for(int i; i < pricesLength ; i++) { //sizeof(prices)/sizeof(double) wont work because this is not an array anymore, but a pointer
        total += prices[i];
    }
    return total;
}