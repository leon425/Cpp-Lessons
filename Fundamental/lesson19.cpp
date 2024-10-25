#include <iostream>

int bubbleSort(int num[], int lengthNum);

int main() {
//Bubble Sort

    int num[] = {14,1,5,17,13,6,12,10,8,16,11,9,3,2,15,7,4};
    int lengthNum = sizeof(num)/sizeof(int);

    bubbleSort(num, lengthNum);

    return 0;
}

int bubbleSort(int num[], int lengthNum) {
    int temp;

    for (int x = 0; x < lengthNum-1; x++) {
        for (int i = 0; i < lengthNum-1-x; i++) {
            std::cout << num[i+x] << '\n';
            if (num[i] > num[i+1]) {
                temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
            }
        }
    };

    for(int i = 0; i < lengthNum; i++) {
        std::cout << num[i] << ", ";
    }

}