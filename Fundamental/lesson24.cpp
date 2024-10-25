#include <iostream>

int main() {
// Dynamic Memory = Memory that is allocated after the program is already compiled & running
                // use the 'new' operator to allocate memory in the heap rather than the stack
                // useful when we don't know how much memory we will need
    
    int *pNum = nullptr; //It's good practice not to assign the value of a pointer right away

    pNum = new int; // 'new' operator will return an address. Storing an address to pNum

    *pNum = 21; //deference the pointer, then assign a value to it.

    std::cout << "address: " << pNum << '\n';

    // Delete the unused pointer
    delete pNum; //Freeing up the memory. If we don't use this, we can get a memory leak.

    

    return 0;
}