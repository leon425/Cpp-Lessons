#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {

            // Stop The Recursion
            if (l1 == nullptr && l2 == nullptr && carry == 0) {
                return nullptr;
            }

            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next; 
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* currentNode = new ListNode(sum%10);
            currentNode->next = addTwoNumbers(l1,l2,sum/10);

            return currentNode; // The final return is the head

        }

    };

int main() {

    ListNode node1(2);
    ListNode node2(4,&node1);
    ListNode node3(3,&node2); // l1 head

    ListNode node4(6);
    ListNode node5(4,&node4);
    ListNode node6(2,&node5);
    ListNode node7(7,&node6);
    ListNode node8(6,&node7); // l2 head

    Solution solution1;
    ListNode* final = solution1.addTwoNumbers(&node3,&node8);


    while (final != nullptr) {
        std::cout << final->val << " -> ";
        final = final->next;
    }

    return 0;
}