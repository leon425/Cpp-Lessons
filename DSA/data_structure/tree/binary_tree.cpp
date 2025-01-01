#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#include <iomanip> // for setw
#include <string>

// TODO:
// Delete tree node using the 2nd method
// Is there a way to re-balanced a binary tree other than using inorder traversal than building a tree again?
// Is there a way to maximise the deletion of tree node so the result will results in a balanced BST. Or just simply use one of the method
// and balance the tree afterwards

// how to display the binary tree the best? maybe draw it. If so, how? 

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x, Node* left, Node* right) : data(x), left(left), right(right) {}
    Node(int x, Node* left) : data(x), left(left), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

std::vector<int> sliceVector(std::vector<int> vec, int start, int end) {
    return std::vector<int> (vec.begin() + start, vec.begin() + end);
}

Node* conversion(std::vector<int> vec) {
    int length = vec.size();
    int mid = length/2;
    Node* root = nullptr;

    if (length == 1) {
        root = new Node(vec[0],nullptr,nullptr);
    } else if (length == 2) {
        Node* lSubtree = conversion(sliceVector(vec,0,mid));
        root = new Node(vec[mid],lSubtree,nullptr);
    } else {
        Node* lSubtree = conversion(sliceVector(vec,0,mid));
        Node* rSubtree = conversion(sliceVector(vec,mid+1,length));
        root = new Node(vec[mid],lSubtree,rSubtree);
    }
    return root;
}

Node* correctConversion(std::vector<int> vec) {
    std::sort(vec.begin(),vec.end(), [](int a, int b) { // Ascending order by passing custom function
        return a < b;
    });
    return conversion(vec);
}

Node* falseConversion(std::vector<int> vec) {
    int length = vec.size();
    if (length < 2) {
        std::cout << "False Edit can't be done" << '\n';
        return nullptr;
    }
    srand(time(NULL)); // the random number initialization
    int num1 = (rand() % length); //Get the random number of 0 to length-1
    int num2 = num1;
    while (num2 == num1) {
        num2 = (rand() % length);
    }
    int temp;
    temp = vec[num1];
    vec[num1] = vec[num2];
    vec[num2] = temp;
    return conversion(vec);
}

bool isLeafNode(Node* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    } else {
        return false;
    }
}

void printNode(Node* root) {
    std::cout << root->data << "\n";
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

void preorder(Node* root) { // data, left, right
    std::cout << root->data << " "; 
    if (root->left != nullptr) preorder(root->left);
    if (root->right != nullptr) preorder(root->right);
}

void inorder(Node* root) { // left, data, right
    if (root->left != nullptr) inorder(root->left);
    std::cout << root->data << " ";
    if (root->right != nullptr) inorder(root->right);
}

void postorder(Node* root) { // data, left, right
    if (root->left != nullptr) postorder(root->left);
    if (root->right != nullptr) postorder(root->right);
    std::cout << root->data << " ";
}

int treeHeight(Node* root) {
    if (root == nullptr) { // the height of an empty tree is -1, whereas the height of a leaf node is 0
        return -1;
    } 
    return std::max(treeHeight(root->left),treeHeight(root->right)) + 1;
}

Node* search(int value, Node* root) {
    if (root->data == value) return root;
    if (root->left == nullptr && root->right == nullptr) return nullptr;
    if (root->data < value) return search(value,root->left);
    if (root->data > value) return search(value,root->right);
}

// Function to print the tree horizontally
void printBT(const std::string& prefix, const Node* node, bool isLeft) {
    if (node != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "|---" : "+---");

        // Print the value of the node
        std::cout << node->data << '\n';

        // Enter the next tree level - left and right branch
        printBT(prefix + (isLeft ? "|   " : "    "), node->left, true);
        printBT(prefix + (isLeft ? "|   " : "    "), node->right, false);
    }
}

// Wrapper function
void printTree(const Node* node) {
    printBT("", node, false);
}


bool isBSTHelper(Node* root, int max, int min) {
    // int max = the max value of the left subtree
    // int min = the min value of the right subtree
    if (root == nullptr) {
        return true;
    }
    
    if (root->data >= max || root->data <= min) {
        return false;
    } else {
        return isBSTHelper(root->left, root->data, min) && isBSTHelper(root->right, max, root->data);
    }
}

bool isBST(Node* root) {
    return isBSTHelper(root,INT_MIN,INT_MAX);
}

// Return true if all the element in the left subtree is less than the root
bool isLSubTreeLesser(Node* root, int value) {
    if (root == nullptr) {
        return true;
    }
    if (root->data <= value && isLSubTreeLesser(root->left,value) && isLSubTreeLesser(root->right,value)) {
        return true;
    } 
    return false;
}

// Return true if all the element in the right subtree is greater than the root
bool isRSubTreeGreater(Node* root, int value) {
    if (root == nullptr) {
        return true;
    }
    if (root->data > value && isRSubTreeGreater(root->left,value) && isRSubTreeGreater(root->right,value)) {
        return true;
    } 
    return false;
}

// Inefficient
bool isBST2(Node* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    } 

    if (   isLSubTreeLesser(root->left,root->data)
        && isBST2(root->left)
        && isRSubTreeGreater(root->right,root->data)
        && isBST2(root->right)) {

        return true;
    } else {
        return false;
    }
}

// 2 common approaches:
    /*
    Move up the maximum value of the left subtree or move up the minimum value of the right subtree. 
    Maximum value of the left subtree : Slightly preferred for predecessor replacement where left subtree traversal is prioritized
    Minimum value of the right subtree : Slightly more common. because of the same reason above + aligns with inorder traversal, replacing the node
                                         with the next larger value.
    */

// Minimum of right child approach
Node* findParent(Node* root, Node* child) {
    if (child == nullptr || root == nullptr) return nullptr;
    if (root->left != nullptr) {
        if (root->left->data == child->data) return root;
    } 
    if (root->right != nullptr) {
        if (root->right->data == child->data) return root;
    }
    if (root->data < child->data) return findParent(root->left, child);
    if (root->data > child->data) return findParent(root->right, child);
}

// Max value inside a BST
Node* maxBST(Node* root) {
    if (root == nullptr) return nullptr;
    if (root->right == nullptr) {
        return root;
    } else {
        return maxBST(root->right);
    }
}

// Min value inside a BST
Node* minBST(Node* root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr) {
        return root;
    } else {
        return minBST(root->left);
    }
}

void deleteBSTHelper(int value, Node* root, Node* parentRoot) { 
    // if the node to be delete doesnt exist 
    if (parentRoot == nullptr || root == nullptr) {
        return;
    }

    // if node doesn't have children
    if (root->left == nullptr && root->right == nullptr) {
        if (parentRoot->data < root->data) {
            parentRoot->left = nullptr;
        } else {
            parentRoot->right = nullptr;
        }
        delete root;
    }    

    // if node has 1 children (left) -> Find the maximum of left subtree
    if (root->left != nullptr && root->right == nullptr) {
        Node* maxLeftTree = maxBST(root->left); // maxBST doesnt have a right children. minBST doesn't have a left children
        root->data = maxLeftTree->data; 

        // 2 cases. it has a left children or no children
        Node* parentMaxLeftTree = findParent(parentRoot,maxLeftTree);
        parentMaxLeftTree->right = maxLeftTree->left; // it is always parentMaxLeftTree->right. if there's a children, than the parent is pointing
                                                      // to the children. otherwise, pointing to nullptr.
        delete maxLeftTree;
        
    }

    // if node has 1 children (right) OR if node has 2 children (left & right) -> find the minimum of right subtree
    if (root->left == nullptr && root->right != nullptr) {
        Node* minRightTree = minBST(root->right); // maxBST doesnt have a right children. minBST doesn't have a left children
        root->data = minRightTree->data; 

        // 2 cases. it has a right children or no children
        Node* parentMinRightTree = findParent(parentRoot,minRightTree);
        parentMinRightTree->left = minRightTree->right; // it is always parentMaxLeftTree->left. if there's a children, than the parent is pointing
                                                      // to the children. otherwise, pointing to nullptr.
        delete minRightTree;
    }
}

void deleteBST(int value, Node* root) {
    Node* rootToDelete = search(value,root);
    deleteBSTHelper(value, rootToDelete, findParent(root,rootToDelete));
}


int main() {
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9,10,11,12,34,56,76};
    Node* root = correctConversion(vec);
    Node* falseRoot = falseConversion(vec);

    // BFS Traversal
    std::vector<int> BFSList = BFS(falseRoot);
    for (int i=0; i<BFSList.size();i++) {
        std::cout << BFSList[i] << " ";
    }
    std::cout << '\n';

    // preorder(root);
    // inorder(root);
    // postorder(root);

    // Node* node6 = new Node(4);
    // Node* node4 = new Node(8);
    // Node* node3 = new Node(3, nullptr, node6);
    // Node* node2 = new Node(9);
    // Node* node1 = new Node(7, node3, node4);
    // Node* root2 = new Node(8, node1, node2);

    //std::cout << root->data << '\n';
    printTree(root);
    printTree(falseRoot);
    
    return 0;
}