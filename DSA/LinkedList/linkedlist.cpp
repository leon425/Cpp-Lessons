#include <iostream>
#include <cmath> 

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int val) : data(val), next(nullptr), prev(nullptr) {}

};

class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length; //Always maintain the length of the LinkedList
    
    public:
        LinkedList() : head(nullptr), tail(nullptr), length(0) {}

        void appendList(int data) {
           Node* newNode = new Node(data);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }

        void pullList() {
            if (tail) {
                Node* nodeToDelete = tail;
                if (head == tail) { //only 1 object remaining
                    head = nullptr;
                    tail = nullptr;
                } else {
                    tail = tail->prev;
                    tail->next = nullptr;
                }

                delete nodeToDelete;
                length--;

            } else {
                std::cout << "This LinkedList is empty\n";
            }
        }

        void insertList(int data, int index) {
            if ((index >= 0 && index <= length) || (index < 0 && abs(index) <= length)) {
                Node* newNode = new Node(data);
                Node* nextCurrentNode = nullptr;
                Node* currentNode = nullptr;

                if (length == 0) {
                    appendList(data);
                    return;
                }

                // Change the head
                if (index == 0 || (index < 0 && abs(index) == length)) { 
                    head->prev = newNode;
                    newNode->next = head;
                    head = newNode;
                    length++;
                    return;
                } 
                // Change the tail
                else if (index == length || index == -1) { //or index = -1
                    appendList(data);
                    return;
                }
                // Normal Insertion
                else if (index > 0) {
                    currentNode = head;
                    for (int i=0; i<index-1; ++i) { //use ++i because of IDK
                        currentNode = currentNode->next;
                    }
                 } 
                // Normal Negative Index Insertion
                else if (index < -1 && abs(index) < length){
                    currentNode = tail;
                    for (int i = 0; i<abs(index)-1; ++i) { //use ++i because of IDK
                        currentNode = currentNode->prev;
                    }
                }
                nextCurrentNode = currentNode->next;

                currentNode->next = newNode;
                nextCurrentNode->prev = newNode;

                newNode->prev = currentNode;
                newNode->next = nextCurrentNode;

                length++;
            } else {
                std::cout << "Error: Index Out Of Reach\n";
            }
        }

        void replaceList(int data, int index) {
            if ((index >= 0 && index < length) || (index < 0 && abs(index) <= length)) {
                Node* newNode = new Node(data);
                Node* prevCurrentNode = nullptr;
                Node* nextCurrentNode = nullptr;
                Node* currentNode = nullptr;

                if (index >= 0) {
                    currentNode = head;
                    for (int i=0; i<index; ++i) { //use ++i because of IDK
                        currentNode = currentNode->next;
                    }
                } else {
                    currentNode = tail;
                    for (int i = 0; i<abs(index)-1; ++i) { //use ++i because of IDK
                        currentNode = currentNode->prev;
                    }
                }

                prevCurrentNode = currentNode->prev;
                nextCurrentNode = currentNode->next;

                // Update previous node's next if not at the head
                if (prevCurrentNode) {
                    prevCurrentNode->next = newNode;
                } else {
                    head = newNode; // Update head if replacing at the head
                }

                // Update next node's prev if not at the tail
                if (nextCurrentNode) {
                    nextCurrentNode->prev = newNode;
                } else {
                    tail = newNode; // Update tail if replacing at the tail
                }

                // Link the new node
                newNode->next = nextCurrentNode;
                newNode->prev = prevCurrentNode;

                // Idk why we shouldn't use this code for linking the new node
                // newNode->next = currentNode->next;
                // newNode->prev = currentNode->prev;

                delete currentNode;
        
            } else {
                std::cout << "Error: Index Out Of Reach\n";
            }
            
        }

        void printList() const {

            Node* currentNode = head;
            while (currentNode) {
                std::cout << currentNode->data << " -> ";
                currentNode = currentNode->next;
            }
            std::cout << "nullptr" << '\n';
            std::cout << "Length : " << length << '\n';

        }

        void printHeadAndTail() const {
            if (head) { //avoid retreiving a value of nullptr pointer. can lead to undefined behaviour
                std::cout << "head : " << head->data << '\n';
            } else {
                std::cout << "The head of this LinkedList doesn't exist\n";
            }
            
            if (tail) {
                std::cout << "tail : " << tail->data << '\n';
            } else {
                std::cout << "The tail of this LinkedList doesn't exist\n";
            }   
        }

        ~LinkedList() {
            Node* current = head;
            Node* next = nullptr;
            while(current) {
                next = current->next;
                delete current;
                current = next;
            }
        }

};

int main() {
    LinkedList list;
    list.appendList(1);
    list.appendList(4);
    list.appendList(3);
    list.appendList(5);
    list.appendList(7);
    list.appendList(8);
    list.appendList(9);

    list.insertList(6,5);
   
    list.printList();
    list.printHeadAndTail();


    return 0;
}