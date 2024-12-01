#include <iostream>

int main() {
//pointers = variable that stores a memory address of another variable.
// Sometimes, it is easier to work with an address

    // & address-of operator
    // * dereference operator

    std::string name = "Bro";

    std::string* pName = &name; // 'p' is a naming convention // * is the declaration of a pointer. std::string* means a pointer that points to a 
                                // string data type

    std::cout << pName << '\n'; // get the address
    std::cout << *pName << '\n'; // get the value behind that address. Dereference

    // An array is already an address. If you dereference an array, it will display the first index

// Null Pointer = A pointer that point to a null value (not pointing at anything)
// nullptr = keyword represents a null pointer literal
        // usefull when determining if an address was successfuly assigned to a pointer

    int *pointer = nullptr; //if you don't to assign an address to this pointer yet, just assign nullptr

    int x = 123;
    pointer = &x;

    // usually dev checks the validity of the pointer.(highly recommended)
    if (pointer == nullptr) {
        std::cout << "Address was not assigned\n";
    }

    // When you modify the deference of the pointer, the value which the pointer points will also change
    x = 124;
    *pointer = *pointer + 3;
    std::cout << x << '\n'; // 127

// Pointer to pointer
    int x = 5;
    int* px = &x;
    int** q = &px; //int** means it's a pointer that points to a pointer which points to an int
    std::cout << *(*q) << '\n'; //5  // The bracket is unecessary but it's a good practice for coherence.
    std::cout << *q << '\n'; // The address of x. Only dereference q, and not px. Still need to dereference px
    std::cout << q << '\n'; // The address of px

// Array & Pointer
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;  // ptr points to the first element of arr

    // Accessing array elements using a pointer
    for (int i = 0; i < 5; ++i) {
    std::cout << *(ptr + i) << " ";  // Output: 1 2 3 4 5
}


    return 0;
}