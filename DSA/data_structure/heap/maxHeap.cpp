#include <iostream> 
#include <vector>
#include <cmath> 
#include <algorithm>

int parentHeap(int index) {
    return (index-1)/2;
}

int lChildHeap(int index) {
    return 2 * index + 1;
}

int rChildHeap(int index) {
    return 2 * index + 2;
}

void switchVar(int& num1, int& num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;

}

void insertHeap(std::vector<int>& heap, int num) {
    heap.push_back(num); // = heap[heap.size()-1]
    int numIndex = heap.size()-1;

    if (heap.size() > 1) {
        std::cout << "Parent Heap: " << heap[parentHeap(numIndex)] << '\n';
        std::cout << "Heap: " << num << '\n';

        // Heap Adjustment using iteration method
       while (num > heap[parentHeap(numIndex)]) { //while the element is greater than its parent & the parent still have another parent, switch it

            switchVar(heap[parentHeap(numIndex)],heap[numIndex]); 
            //switchVar(heap[parentHeap(numIndex)],num); is wrong because you don't switch the heap element. You switch the num element.

            // Change the index of the inserted num into the parent's index after we switch the num with the parent.
            numIndex = parentHeap(numIndex); 
            
       }    
    }
}

void deleteHeap(std::vector<int>& heap) {
    
    if (heap.empty()) return;

    // Move the front element to the last. Then, delete it.
    //switchVar(heap[heap.size()-1],heap[0]);
    heap[0] = heap[heap.size()-1];
    //heap.erase(heap.begin() + heap.size()-1); 
    heap.pop_back();

    // Start Adjusting it
    int numIndex = 0;
    while (lChildHeap(numIndex) < heap.size() && rChildHeap(numIndex) < heap.size()) {
    int largest = numIndex;

        // if the left child is bigger than the right child
        if (heap[largest] < heap[lChildHeap(numIndex)]) { 
            largest = lChildHeap(numIndex);
        } 

        // If the right child is bigger than the left child
        if (heap[largest] < heap[rChildHeap(numIndex)]) { 
            largest = rChildHeap(numIndex);

        } 

        if (largest == numIndex) {
            break;
        } 
        switchVar(heap[largest],heap[numIndex]);
        numIndex = largest; // Move down to the next child

    }
    
}

void heapify(std::vector<int>& heap, int index = -1) {

    if (index == -1) {
        index = heap.size()/2 -1;
    }

    int largest = index;
    int rChild = rChildHeap(index);
    int lChild = lChildHeap(index);

    
    // if lChild exist & greater than the largest (index)
    if (lChild <= heap.size()-1 && heap[lChild] > heap[rChild] && heap[lChild] > heap[largest]) {
        largest = lChild;
    } 

    // if rChild exist & greater than the largest (index or lChild)
    else if (rChild <= heap.size()-1 && heap[rChild] > heap[lChild] && heap[rChild] > heap[largest]) {
        largest = rChild;
    } 

    if (largest != index) {
        switchVar(heap[largest],heap[index]);
        heapify(heap,largest); //Check the child element
    }

    if (index > 0) {
        heapify(heap,index-1);
    }

}

void deleteHeap2(std::vector<int>& heap) {
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    heapify(heap,0);
}

std::vector<int> heapSort(std::vector<int> heap) {
    std::vector<int> heapSorted = {};
    for (int i = heap.size()-1; i >= 0 ; i--) {
        heapSorted.push_back(heap[0]);
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        heapify(heap,i);
    }
    return heapSorted;
}

int main() {
    std::vector<int> heap = {10,20,15,12,40,25,18}; //{70,30,60,15,20}

    // insertHeap(heap,20);
    // insertHeap(heap,30);
    // insertHeap(heap,60);
    // insertHeap(heap,15);
    // insertHeap(heap,70);
    // insertHeap(heap,100);

    // deleteHeap(heap);
    // deleteHeap(heap);
    // deleteHeap2(heap);


    //heapSort(heap);
    heapify(heap);
    heapSort(heap);
    
    

    // Print The Heap
    for (int i=0; i<heap.size();i++) {
        std::cout << heap[i] << ", ";
    }
    std::cout << '\n';
    std::cout << "Heap size: " << heap.size() << '\n';
    
    // Heap Sort
    std::cout << "Sorted heap: ";
    for (int i=0; i<heapSort(heap).size();i++) {
        std::cout << heapSort(heap)[i] << ", ";
    }
    std::cout << "\n";


    return 0;
}