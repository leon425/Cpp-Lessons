#include <iostream>

struct Node {
    char value;
    Node* link;
    Node() : value(' ') {}
    Node(char x) : value(x), link(nullptr) {}
    Node(char x, Node* data) : value(x), link(data) {}
};

void append(char x, Node* &head) {
    if (head == nullptr) {
        Node* newNode = new Node(x,nullptr);
    } else {
        Node* newNode = new Node(x, head);
        head = newNode;
    }
}

void pop(Node* &head) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

bool check(std::string str) {
    Node* head = nullptr;
    Node* currentNode = nullptr;
    for (int i=0;i<str.length();i++) {
        // If it's an opening
        if ( str[i] == '[' || str[i] == '{' || str[i] == '(' ) {
            if (head == nullptr) {
                head = new Node(str[i],nullptr); // can't use append because "append"'s argument need an address of the head. Now, we are 
                                                // initializing the node;
            } else {
                append(str[i],head);
            }
        }

        // If it's a closing
        if ( str[i] == ']' || str[i] == '}' || str[i] == ')' ) {
            // if the stack is empty (no more opening left), but there's still a closing
            if (head == nullptr) { 
                return false;
            }

            // if it's a full bracket
            if (str[i] == ']' && head->value == '[' || str[i] == '}' && head->value == '{' || str[i] == ')' && head->value == '(' ) {
                pop(head);
            } else { //if the opening & closing aren't the same 
                return false;
            }
        }
    }
    
    if (head != nullptr) {
        // deallocate memory (here because we create the stack in this scope and not in int scope)
        while (head != nullptr) {
            Node* temp = head;
            head = head->link;
            delete temp;
        }
        return false;
    }
    return true;
}

int main() {
    std::cout << check("[(ab)+(ab)])") << '\n';
    std::cout << check("{{{2,10},{3,20}}{{1,10},{3,40}}{{2,50}}}") << '\n';



    
   

    return 0;
}