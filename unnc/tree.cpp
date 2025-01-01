#include "maincode.h"
#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
    Node(int x, Node* left) : data(x), left(left), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* leaf() {
    return nullptr;
}

Node* node(Node* left, int data, Node* right ) {
    Node* root = new Node(data,left,right);
    return root;
}

bool isLeaf(Node* root) {
    return root == nullptr;
}

int root(Node* root) {
    return root->data;
}

Node* left(Node* root) {
    return root->left;
}

Node* right(Node* root) {
    return root->right;
}


// Custom Algorithm

int size(Node* root) {
    if (isLeaf(root)) {
        return 0;
    } else {
        return 1 + size(left(root)) + size(right(root));
    }
}

bool searchBT(int x, Node* node) {
    if (isLeaf(node)) {
        return false;
    } else if (root(node) == x) {
        return true;
    } else {
        return searchBT(x, left(node)) || searchBT(x, right(node));
    }
}

bool searchBST(int x, Node* node) {
    if (isLeaf(node)) {
        return false;
    } else if (root(node) == x) {
        return true;
    } else if (x > root(node)) {
        return searchBST(x, right(node));
    } else if (x < root(node)) { // should delete else if to ensure the function always returns a value
        return searchBST(x, left(node));
    } 
}

int height(Node* t) {
    if (isLeaf(t)) {
        return -1;
    } else {
        return 1 + max(height(left(t)),height(right(t)));
    }
}

Node* deleteLeaf(Node* t) {
    if (isLeaf(t)) {
        return leaf();
    } else if (isLeaf(left(t)) && isLeaf(right(t))) { 
        return leaf(); // if leaf node or nullptr node. (In this case, nullptr node already return nullptr/leaf())
    } else {
        return node(deleteLeaf(left(t)),root(t),deleteLeaf(right(t)));
    }
}

bool isBST(Node* t) {
    // If the tree is nullptr, it's a valid BST
    if (isLeaf(t)) {
        return true;
    }
    // If there's no right or left subtree
    if (isLeaf(left(t)) && isLeaf(right(t))) {
        return true;
    }

    // if there's only left subtree
    if (!isLeaf(left(t)) && isLeaf(right(t))) {
        if (isBST(left(t)) && root(left(t)) < root(t)) { // in condition that left and right subtree exist
            return true;
        }
    }

    // if there's only right subtree
    if (!isLeaf(right(t)) && isLeaf(left(t))) {
        if (isBST(right(t)) && root(right(t)) > root(t)) { // in condition that left and right subtree exist
            return true;
        }
    }

    // if there're both left and right subtree
    else {
        if (isBST(left(t)) && root(left(t)) < root(t) && isBST(right(t)) && root(right(t)) > root(t)) { // in condition that left and right subtree exist
            return true;
        }
    }
    return false;
}

bool isBSTRevised(Node* t) {
    // Base case: An empty tree (nullptr) is a valid BST
    if (isLeaf(t)) {
        return true;
    }

    // Check left subtree
    if (!isLeaf(left(t)) && root(left(t)) >= root(t)) {
        return false; // Left child must be less than the root
    }

    // Check right subtree
    if (!isLeaf(right(t)) && root(right(t)) <= root(t)) {
        return false; // Right child must be greater than the root
    }

    // Recursively check left and right subtrees
    return isBSTRevised(left(t)) && isBSTRevised(right(t));
}

std::vector<int> BFS(Node* root) { // O(n)
    std::vector<int> list;
    std::queue<Node*> q;
    if (root != nullptr) {
        q.push(root);
    } else {
        return list;
    }
    while (q.empty() == false) {
        Node* current = q.front();
        q.pop();
        list.push_back(current->data);
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
    return list;
}


int main() {
    std::vector<int> treeList1 = {1,2,3,4,5,6,7,8};
    // BFS Traversal
    // std::vector<int> BFSList = BFS(root);
    // for (int i=0; i<BFSList.size();i++) {
    //     std::cout << BFSList[i] << " ";
    // }
    // std::cout << '\n';



    return 0;
}