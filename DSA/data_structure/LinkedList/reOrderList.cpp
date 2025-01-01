#include <iostream>
#include <vector>
#include <cmath>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* reorderList(ListNode* head) {
            std::vector<ListNode*> nodeVector;
            ListNode* currentNode = nullptr;

            if (head == nullptr) {
            return;
            }
            else if (head->next != nullptr) {
                currentNode = head->next;
            } else {
                return;
            }
            

            while (currentNode != nullptr) {
                nodeVector.push_back(currentNode);
                currentNode = currentNode->next;
            } 

            currentNode = head;
            int index = 0;
        
            while (index < ceil(static_cast<double>(nodeVector.size())/2)) {
                // Add from the right
                currentNode->next = nodeVector[nodeVector.size()-1-index];
                currentNode = currentNode->next;

                // Add from the left
                if (index < nodeVector.size()/2) {
                    currentNode->next = nodeVector[index];
                    currentNode = currentNode->next;
                }

                // Delete the 'next' value of the last index => to prevent the fucking infinite loop
                if (index == ceil(static_cast<double>(nodeVector.size())/2)-1) {
                    currentNode->next = nullptr;
                }
                index++;
                
            }
    
            return head;
        };
};

int main() {

    ListNode node0(9);
    ListNode node1(8,&node0);
    ListNode node2(7,&node1);
    ListNode node3(6,&node2); 
    ListNode node4(5,&node3);
    ListNode node5(4,&node4);
    ListNode node6(3,&node5);
    ListNode node7(2,&node6);
    ListNode node8(1,&node7); // Head

    Solution solution1;
    ListNode* final = solution1.reorderList(&node8);


    while (final != nullptr) {
        std::cout << final->val << " -> ";
        final = final->next;
    }

    return 0;
}