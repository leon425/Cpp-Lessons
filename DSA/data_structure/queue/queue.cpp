#include <iostream>

class Node {
    public:
        int data;
        Node* back;

        Node(int data, Node*back): data(data), back(back) {}
        Node(int data): data(data), back(nullptr) {}

};

class Queue {
    public:
        Node* first;
        Node* last;
        int length;

        Queue(Node* first) : first(first), length(0) {}
        Queue() : first(nullptr), length(0) {}

        int front() {
            if (first != nullptr) {
                return first->data;
            } else {
                std::cout << "Queue is Empty..." << '\n'; 
                return -1;
            }
            
        }

        void push(int data) {
            Node* newNode = new Node(data,nullptr);
            if (first == nullptr) { // if isEmpty(). can also use the condition last == nullptr
                first = last = newNode;
            } else {
                last->back = newNode;
                last = newNode;
            }
            length++;
        }

        void pop() {
            if (first != nullptr) {
                Node* temp = first;
                first = first->back;
                delete temp;
                length--;
                if (first == nullptr) {
                    last = nullptr;
                }
            }
            
            else {
                std::cout << "Queue is Empty..." << '\n';
            }
        }

        bool isEmpty() {
            return first == nullptr;
        }

        void printQueue() {
            while (first != nullptr) {
                std::cout << first->data << " ";
                pop();
            }
            std::cout << '\n';
        }
};

int main() {
    Queue queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.pop();
    std::cout << queue.front() << '\n';
    queue.printQueue();
    

    return 0;
}