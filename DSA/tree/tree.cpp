#include <iostream>

class Node {
    public:
    int data;
    Node* right;
    Node* left;

    Node(int data) : data(data), right(nullptr), left(nullptr) {}

    
};

class Tree {
    public:
    Node* root;

    Node* createNode(int data) {
        Node* newNode = new Node(data);
        return newNode;
        }

    void preorder(Node* root, Node* root2) {
        if (root == nullptr) return;
        std::cout << root->data << " -> ";
        preorder(root->left,nullptr);
        preorder(root->right,nullptr);
        if (root2 == root) {
            std::cout << "nullptr\n";
        }
    }

    void inorder(Node* root, Node* root2) {
        if (root == nullptr) return;
        inorder(root->left,nullptr);
        std::cout << root->data << " -> ";
        inorder(root->right,nullptr);
        if (root2 == root) {
            std::cout << "nullptr\n";
        }
    }

    void postorder(Node* root,Node* root2) {
        if (root == nullptr) return;
        postorder(root->left,nullptr);
        postorder(root->right,nullptr);
        std::cout << root->data << " -> ";
        if (root2 == root) {
            std::cout << "nullptr\n";
        }
    }

};

int main() {
    Tree tree;
    // Level 1
    Node* root = tree.createNode(1);
    root->left = tree.createNode(2);
    root->right = tree.createNode(3);

    // Level 2 
    root->left->left = tree.createNode(4);
    root->left->right = tree.createNode(5);
    root->right->left = tree.createNode(6);
    root->right->right = tree.createNode(7);

    tree.preorder(root,root);
    tree.inorder(root,root);
    tree.postorder(root,root);








    return 0;
}