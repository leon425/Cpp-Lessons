#include <iostream>

// 10 ms runtime
// Complexity O(N+M)

class ListNode {
    public:
        ListNode* head1 = nullptr;
        ListNode* head2 = nullptr;
        ListNode* tail1 = nullptr;
        ListNode* tail2 = nullptr;
        int val;
        ListNode *next;

        ListNode(int x) : val(x), next(nullptr), head1(nullptr), head2(nullptr), tail1(nullptr), tail2(nullptr) {}

        // ListNode() : val(0), next(nullptr) {};
        // ListNode(int x, ListNode *next) : val(x), next(next) {};

    void printList1 () const {
        ListNode* currentNode = head1;
        while (currentNode) {
            std::cout << currentNode->val << " -> ";
            currentNode = currentNode->next;
        }
        std::cout << '\n';
    }

    void printList2 () const {
        ListNode* currentNode = head2;
        while (currentNode) {
            std::cout << currentNode->val << " -> ";
            currentNode = currentNode->next;
        }
        std::cout << '\n';
    }

    void appendList1 (int val) {
        ListNode* newNode = new ListNode(val);
        if (!head1) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    void appendList2 (int val) {
        ListNode* newNode = new ListNode(val);
        if (!head2) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }


};

class Solution {
public:
    ListNode* tail = nullptr;
    ListNode* head = nullptr;

    void appendList3 (int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList3 () const {
        ListNode* currentNode = head;
        std::cout << "[";
        while (currentNode) {
            std::cout << currentNode->val << (currentNode->next ? "," : "");
            currentNode = currentNode->next;
        }
        std::cout << "]\n";
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        while (list1 && list2) {

            if (list1->val < list2->val) {
                appendList3(list1->val);
                list1 = list1->next;
            } 
            
            else if (list1->val > list2->val) {
                appendList3(list2->val);
                list2 = list2->next;
            } 
            
            else {
                appendList3(list1->val);
                appendList3(list2->val);
                list1 = list1->next;
                list2 = list2->next;
            }
        }

        // If list1 is empty
        if (!list1 && list2) {
            while (list2) {
                appendList3(list2->val);
                list2 = list2->next;
            }
        }

        // If list2 is empty 
        if (!list2 && list1) {
            while (list1) {
                appendList3(list1->val);
                list1 = list1->next;
            }
        }

        // If both lists are empty 
        printList3();
        return head;
            
    }
};

int main() {

    ListNode list(0);
    list.appendList1(1);
    list.appendList1(2);
    list.appendList1(5);

    // list.appendList2(4);
    // list.appendList2(4);
    // list.appendList2(7);

    // list.printList1();
    // list.printList2();

    // std::cout << list.head1->val << '\n';
    // std::cout << list.head2->val << '\n';

    Solution solve;
    solve.printList3();
    solve.mergeTwoLists(list.head1, list.head2);


    return 0;
}