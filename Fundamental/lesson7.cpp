#include <iostream>
#include <cmath> 
#include <iomanip>

int main() {
// Math Related Functions (#include <cmath>)
// Go to 'cplusplus.com/reference/cmath/' for reference

    double x = 3.14;
    double y = 4;
    double z;
    double w;

    //z = std::max(x,y); // Which is the greater number? 3 or 4
    // std::cout << z << '\n';

    // w = std::min(x,y);

    //z = pow(2,3); // 2**3. 
    //z = sqrt(9); // square root of 9
    //z = abs(-5); // absolute value
    //z = round(x); // round the number
    //z = ceil(x); // round up -> x = 4
    //z = floor(x); // round down -> x = 3

    double balance = 250;

    // Add two decimal point (must #include <iomanip>) // 250.00
    std::cout << std::setprecision(2) << std::fixed << balance;

    

    return 0;
    
}