#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to remove duplicates using nested loops
Node* removeDuplicates(Node* head) {
    Node* curr1 = head; 

    // Traverse each node in the list
    while (curr1 != nullptr) {
        Node* curr2 = curr1; 

        // Traverse the remaining nodes to find and 
        // remove duplicates
        while (curr2->next != nullptr) {
            
            // Check if the next node has the same 
            // data as the current node
            if (curr2->next->data == curr1->data) {
                
                // Duplicate found, remove it
                Node* duplicate = curr2->next;  
                curr2->next = curr2->next->next;  

                // Free the memory of the duplicate node
                delete duplicate;
            } else {
              
                // If the next node has different data from 
                // the current node, move to the next node
                curr2 = curr2->next;
            }
        }
        
        // Move to the next node in the list
        curr1 = curr1->next;
    }
    return head;
}

void printList(Node* head) {
    Node* curr = head;
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