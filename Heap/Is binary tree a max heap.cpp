#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/*
    Key Rule for Checking Completeness:
    - Once a NULL (missing child) is encountered, no further non-null nodes should appear.
    - If a non-null node appears after a null child, the tree is incomplete.
*/

bool isHeap(Node* root) {
    if (root == nullptr) return true;

    queue<Node*> q;
    q.push(root);
    
    bool lvlbreak = false;

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left) {
            if (lvlbreak) return false;
            if (temp->data < temp->left->data) return false;
            q.push(temp->left);
        } else {
            lvlbreak = true;
        }

        if (temp->right) {
            if (lvlbreak) return false;
            if (temp->data < temp->right->data) return false;
            q.push(temp->right);
        } else {
            lvlbreak = true;
        }
    }

    return true;
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
