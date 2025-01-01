#include <iostream>

struct Node {
    int data;
    Node* link;

    Node() : data(0), link(nullptr) {}
    Node(int x) : data(x), link(nullptr) {}
    Node(Node* link): data(0), link(link) {}
    Node(int x, Node* link) : data(x), link(link) {}
};

void append(int data, Node* &head) { //pass by reference because we are updating the head
    Node* current = new Node(data,head);
    head = current;
}

void pop(Node* &head) {
    Node* current = head;
    head = head->link;
    delete current;
}

int main() {
    // initialization
    Node* node1 = new Node(20,nullptr);
    Node* head = new Node(10,node1); // no longer head btw
    append(30,head);
    append(40,head);
    append(50,head);
    pop(head);

    // Printing the Stack
    Node* current = head; // it's a good practice to use a new pointer instead of iterating with *head;
    while (current!= nullptr) {
        std::cout << current->data << " ";
        current =current->link;
    }

    // Deallocate Memory
    current = head;
    while (current != nullptr) {
        Node* next = current->link;
        delete current;
        current = next;
    }
    
    
    return 0;
}