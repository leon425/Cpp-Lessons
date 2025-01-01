#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            int index = 1; // Index starting from 1
            ListNode* currentNode = head;
            ListNode* prevNode = head;
            ListNode* nextNode = nullptr;
            ListNode* currentHead = head;

            // Boundary for empty parameter
            if (head == nullptr) {
                return nullptr;
            }

            // The last loop goes to the second last node in the list. 
            // So, there won't be other boundary necessary if there's no currentNode->next
            while (currentNode->next != nullptr) { 
                // if the index is odd, swap
                if (index%2 != 0) {

                    nextNode = currentNode->next;
                    std::cout << "Swap " << currentNode->val << " With " << nextNode->val;
                    std::cout << "    PrevNode: " << prevNode->val << '\n';

                    // Swap the 'next' address
                    currentNode->next = nextNode->next;
                    nextNode->next = currentNode;

                    // Swap the prevNode->next
                    if (index > 2) {
                        prevNode->next = nextNode;
                        prevNode = currentNode;
                    }

                    // Save the current head
                    if (index == 1) {
                        currentHead = nextNode;
                    }
                    
                } else {
                    // If the index is odd, you don't have to iterate the currentNode. Because it's being swapped
                    currentNode = currentNode->next;
                }
                index++;
            }
            return currentHead; 
        };
};

int main() {

    ListNode node1(2);
    ListNode node2(4,&node1);
    ListNode node3(3,&node2); 
    ListNode node4(6,&node3);
    ListNode node5(4,&node4);
    ListNode node6(2,&node5);
    ListNode node7(7,&node6);
    ListNode node8(6,&node7); // Head

    Solution solution1;
    ListNode* final = solution1.swapPairs(&node8);


    while (final != nullptr) {
        std::cout << final->val << " -> ";
        final = final->next;
    }

    return 0;
}