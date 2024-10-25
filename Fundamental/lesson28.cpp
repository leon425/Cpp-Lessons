#include <iostream>

// If we don't explicitly assign an integer value, the value will set automatically assigned as I mention below. (Starting with 0, then 1, 2, etc on each value)
enum Day {sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thursday = 4};

int main() {
// enum = a user-defined data type that consists of paired named-integer constants
        // Great if you have a set of potential option
        // We can't use string for switches

    Day today = sunday;

    switch(today) {
        case sunday: std::cout << "It is Sunday";
                    break;
    }

    // Now, you can use a string in a switch if we pair it with an integer and declare it with enum

    return 0;
}