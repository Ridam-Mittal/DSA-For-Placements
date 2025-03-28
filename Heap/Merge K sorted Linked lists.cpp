/*
Merge K Sorted Linked Lists - Comparison of Approaches:

1️⃣ Merge Sort (Divide & Conquer):
   - Time Complexity: O(N log K)
   - Space Complexity: O(log K) (recursion stack)
   - Recursively merges lists in pairs, similar to Merge Sort.
   - Uses less extra space than the Min Heap approach but has recursion overhead.

2️⃣ Min Heap (Priority Queue) [This Code]:
   - Time Complexity: O(N log K)
   - Space Complexity: O(K) (heap storage)
   - Always extracts the smallest node efficiently using a Min Heap.
   - More space-efficient than Merge Sort for large K values since it avoids deep recursion.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
    
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) {
            q.push({ lists[i]->val, lists[i] });
        }
    }

    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    
    while (!q.empty()) {
        int top = q.top().first;
        ListNode* node = q.top().second;
        q.pop();
        
        temp->next = node;
        temp = node;

        if (node->next) {
            node = node->next;
            q.push({ node->val, node });
        } 
    }
    
    return dummy->next;
}

/* Utility function to print linked list */
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

/* Example Usage */
int main() {
    ListNode* a = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* b = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* c = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {a, b, c};
    
    ListNode* mergedHead = mergeKLists(lists);
    printList(mergedHead);

    return 0;
}
