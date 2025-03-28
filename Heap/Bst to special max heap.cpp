#include <iostream>
#include <vector>

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

// Function to store inorder traversal of BST
void traverse(Node* root, vector<int>& i) {
    if (root == nullptr) {
        return;
    }
    traverse(root->left, i);
    i.push_back(root->data);
    traverse(root->right, i);
}

// Function to modify BST into Special Max Heap using postorder traversal
void postorder(Node* root, vector<int>& i, int &index) {
    if (root == nullptr) {
        return;
    }
    postorder(root->left, i, index);
    postorder(root->right, i, index);
    root->data = i[index++];
}

// Function to convert BST into Special Max Heap
void convertToMaxHeapUtil(Node* root) {
    vector<int> i;
    traverse(root, i);
    int ind = 0;
    postorder(root, i, ind);
}

// Function to print postorder traversal of tree
void printPostorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMaxHeapUtil(root);

    cout << "Postorder Traversal of Converted Max Heap: ";
    printPostorder(root);
    cout << endl;

    return 0;
}
