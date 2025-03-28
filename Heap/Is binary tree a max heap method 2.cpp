#include <iostream>
#include <queue>
using namespace std;

// Definition of a Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to count the number of nodes in the tree
int countNodes(Node* root) {
    if (root == nullptr)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to check if a binary tree is a Complete Binary Tree (CBT)
bool isCBT(Node* root, int index, int totalNodes) {
    if (root == nullptr)
        return true;
    
    if (index >= totalNodes)
        return false;
    
    bool left = isCBT(root->left, 2 * index + 1, totalNodes);
    bool right = isCBT(root->right, 2 * index + 2, totalNodes);

    return (left && right);
}

// Function to check if a binary tree follows Max Heap order property
bool isMaxOrder(Node* root) {
    if (root->left == nullptr && root->right == nullptr)
        return true;
    
    if (root->right == nullptr)
        return (root->data > root->left->data);

    bool left = isMaxOrder(root->left);
    bool right = isMaxOrder(root->right);

    return (left && right && root->data > root->left->data && root->data > root->right->data);
}

// Function to check if a binary tree is a Max Heap
bool isHeap(Node* root) {
    int totalNodes = countNodes(root);
    return isCBT(root, 0, totalNodes) && isMaxOrder(root);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);

    if (isHeap(root))
        cout << "The tree is a valid Max Heap" << endl;
    else
        cout << "The tree is not a valid Max Heap" << endl;

    return 0;
}
