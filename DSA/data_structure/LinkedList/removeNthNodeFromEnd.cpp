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
        ListNode* removeNthFromEnd(ListNode* head,int n) {
        ListNode* currentNode = head; //Create a new ListNode* variable because the head shouldn't be changed. We might use it again the future
        std::vector<ListNode*> addressList;
        int length = 0;
        int index;

        // Copy the address to the vector & get the list length
        while (currentNode != nullptr) { // and not 'while (head->next != nullptr)' because the length will be -1 the correct length
            addressList.push_back(currentNode);
            currentNode = currentNode->next;
            length++;
        }
        index = length-n;

        std::cout << length <<'\n';

        // If the n is outside the linked list
        if (n > length || n <= 0) {
            return head;
        }

        // If the linked list size is empty
        if (length == 0 || (length == 1 && n == 1)) {
            return nullptr;
        }

        // If the head is deleted
        if (index == 0) {
            return addressList[1];
        }

        // If the tail is deleted
        if (index == length-1) { 
            addressList[index-1]->next = nullptr;
        } else {
            addressList[index-1]->next = addressList[index+1];
        }
        
        return addressList[0];
        
    };
};

int main() {

    ListNode node1(2);
    // ListNode node2(4,&node1);
    // ListNode node3(3,&node2); 
    // ListNode node4(6,&node3);
    // ListNode node5(4,&node4);
    // ListNode node6(2,&node5);
    // ListNode node7(7,&node6);
    // ListNode node8(6,&node7); // Head

    Solution solution1;
    ListNode* final = solution1.removeNthFromEnd(&node1,1);


    while (final != nullptr) {
        std::cout << final->val << " -> ";
        final = final->next;
    }

    return 0;
}