// C++ implementation to remove duplicates from
// an unsorted singly linked list using hashing

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node *removeDuplicates(Node *head) {
    unordered_set<int> hashSet;
    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr) {

        // Check if the element is already in the hash table
        if (hashSet.find(curr->data) != hashSet.end()) {

            // Element is present, remove it
            prev->next = curr->next;

            // Delete the curr node
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        else {

            // Element is not present, add it to hash table
            hashSet.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

void printList(Node *head) {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {

    // Create a singly linked list:
    // 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
    Node* head = new Node(12);
    head->next = new Node(11);
    head->next->next = new Node(12);
    head->next->next->next = new Node(21);
    head->next->next->next->next = new Node(41);
    head->next->next->next->next->next = new Node(43);
    head->next->next->next->next->next->next = new Node(21);

    head = removeDuplicates(head);
    printList(head);

    return 0;
}