#include <iostream>

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* data) : data(x), next(data) {}
};

struct Node2 {
    int data;
    Node2* next;
    Node2() : data(0), next(nullptr) {}
    Node2(int x) : data(x), next(nullptr) {}
    Node2(int x, Node2* data) : data(x), next(data) {}
};

Node2* reverseLinkedList(Node* &head, Node2* tail = nullptr) {
    Node2* newNode = nullptr;
    Node2* currentNode = nullptr;
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;

        // Assign the value to Node2
        newNode = new Node2(temp->data,currentNode);
        currentNode = newNode;
       
        delete temp;
    }
    return currentNode;
}

int main() {
    int size = 12;
    Node* tail = new Node(1,nullptr);
    Node* head;
    Node* current;
    for (int i=0;i<size-1;i++) {
        if (i == 0) {
            current = new Node(i+2,tail);
        } else if (i == size-2) {
            head = new Node(i+2,current);
        } else {
            Node* newNode = new Node(i+2,current);
            current = newNode;
        }
        
    }

    // Print Node1
    current = head;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << '\n';

    Node2* head2 = reverseLinkedList(head);
    // Print Node2 (Reversed Version of Node1)
    Node2* current2 = head2;
    while (current2 != nullptr) {
        std::cout << current2->data << " -> ";
        current2 = current2->next;
    }
    std::cout << '\n';

    // Free Memory Node1
    current = head;
    while (current != nullptr) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }

    // Free Memory Node2
    current2 = head2;
    while (current2 != nullptr) {
        Node2* temp2 = current2->next;
        delete current2;
        current2 = temp2;
    }

    // This one's wrong
    // current = head;
    // while (current != nullptr) {
    //     Node* temp = current;
    //     delete temp;
    //     current = current->next; //Logically, current is already deleted because temp = current
    // }



    return 0;
}

