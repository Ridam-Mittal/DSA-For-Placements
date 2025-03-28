#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove duplicate elements
ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;

    while (curr) {
        bool duplicate = false;
        while (curr->next && curr->val == curr->next->val) {
            duplicate = true;
            curr = curr->next;
        }
        if (duplicate) {
            prev->next = curr->next;  // Skip all duplicates
        } else {
            prev = prev->next;  // Move prev only if no duplicates
        }

        curr = curr->next;
    }

    return dummy->next;
}

// Utility function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < size; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Main function
int main() {
    int arr[] = {1, 2, 3, 3, 4, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);
    cout << "Original List: ";
    printList(head);

    head = deleteDuplicates(head);
    cout << "Modified List: ";
    printList(head);

    return 0;
}
