#include <iostream>
#include <vector>

// Time completed : 18 minutes 23 seconds

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* helper(ListNode* head, ListNode* prevNode, int val) {

            if (head->val == val) {
                prevNode->next = head->next;
            } 
            if (head->next != nullptr) {
                head->val == val ? helper(head->next,prevNode,val) : helper(head->next,prevNode->next,val);
            }
            return prevNode->next;fdfdfd
        }

        ListNode* removeElements(ListNode* head,int val) {

            if (head == nullptr) {
                return nullptr;
            }

            ListNode node0(1,head);
            ListNode* prevNode = &node0;
            return helper(head,prevNode,val);
        };

        // GPT Solution: (Iterative -> Less Space complexity)
        ListNode* removeElementsGPT(ListNode* head, int val) {
            ListNode dummy(0, head);  // Dummy node to handle head removal
            ListNode* prev = &dummy;
            ListNode* current = head;

            while (current != nullptr) {
                if (current->val == val) {
                    prev->next = current->next;  // Remove the current node
                } else {
                    prev = current;  // Move prev forward
                }
                current = current->next;  // Move current forward
            }

            return dummy.next;
        }

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
    ListNode* final = solution1.removeElements(&node8,6);


    while (final != nullptr) {
        std::cout << final->val << " -> ";
        final = final->next;
    }

    return 0;
}