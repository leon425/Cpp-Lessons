#include <iostream>

//QUESTION: const data type in C++?

int main() {
// Dynamic Memory = Memory that is allocated after the program is already compiled & running
                // use the 'new' operator to allocate memory in the heap rather than the stack
                // useful when we don't know how much memory we will need

// C syntax malloc, calloc, realloc, free

    int a; // will go to the stack
    int *p;
    p = (int*)malloc(sizeof(int)); // the second argument is how many block of memory
                                    // should the heap provide (in byte)
    // What malloc do is reserve a block (space of memory) in the heap. and the p variable is the pointer to that block

    // if would assign a new malloc to p, the old malloc won't be deleted automatically. so, we need to clear/free/delete it
    free(p);
    p = (int*)malloc(sizeof(int)); 
    
    // dynamic array using malloc
    int size = 4;
    int* pArray = (int*)malloc(size*sizeof(int));
    for (int i=0;i<size;i++) { // Example of initialization
        p[i] = i; // or *(p+i) = i
    }

    int *pArray2 = (int*)calloc(size,sizeof(int)); // size is the number of element
    int *pArray3 = (int*)realloc(pArray2,(size+1)*sizeof(int)); // realloc is edit the size of memory allocation of a pointer
    // in the case above, it creates 1 more index for the array.

    free(pArray);
    free(pArray2);
    free(pArray3);

    // When using calloc, it initialize a value of zero. When using malloc, it doesn't initialize shit. It's a garbage value 
    // in realloc, it can copy a blocks of original pointer. Or if there's a consecutive memory available in the heap, it just extend the original block


    // if malloc is not able to allocate a new memory in the heap, it will return null

// C++ syntax : new and delete
    int *pNum = nullptr; //It's good practice not to assign the value of a pointer right away

    pNum = new int; // 'new' operator will return an address. Storing an address to pNum

    *pNum = 21; //deference the pointer, then assign a value to it.

    std::cout << "address: " << pNum << '\n';

    // Delete the unused pointer
    delete pNum; //Freeing up the memory. If we don't use this, we can get a memory leak. // delete "the pointer"

    // new and delete syntax in c++ is data type safe
    int* pArray;
    int size = 10;
    pArray = new int[size];
    // Example initialization (must use for loop and assign each index) 
    for (int i=0;i<size;i++) {
        pArray[i] = i;
    }
    delete[] pArray; // free the memory. 

    return 0;
}