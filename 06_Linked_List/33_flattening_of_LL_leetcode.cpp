/*
    Flattening of LL
    Given a special linked list containing n head nodes where every node in the linked list contains two pointers:

    ‘Next’ points to the next node in the list
    ‘Child’ pointer to a linked list where the current node is the head
    Each of these child linked lists is in sorted order and connected by a 'child' pointer.

    Flatten this linked list such that all nodes appear in a single sorted layer connected by the 'child' pointer and return the head of the modified list.

    Examples:
    Input:
    Output: head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 12
    Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

    Input:
    Output: head -> 2 -> 4 -> 5 -> 10 -> 12 -> 13 -> 16 -> 17 -> 20
    Explanation: All the linked lists are joined together and sorted in a single level through the child pointer.

    Constraints:
    n == Number of head nodes
    1 <= n <= 100
    1 <= Number of nodes in each child linked list <= 100
    0 <= ListNode.val <= 1000
    All child linked lists are sorted in non-decreasing order
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

// Definition of special linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;

    ListNode() {
        val = 0;
        next = nullptr;
        child = nullptr;
    }

    ListNode(int data1) {
        val = data1;
        next = nullptr;
        child = nullptr;
    }

    ListNode(int data1, ListNode *next1, ListNode* child1) {
        val = data1;
        next = next1;
        child = child1;
    }
};

class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // min-heap
        }
    };

    ListNode* flattenLinkedList(ListNode* &head) {
        if (!head) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // Step 1: Push all head nodes of child lists into the heap
        ListNode* curr = head;
        while (curr) {
            if (curr) minHeap.push(curr);  // each curr is head of a sorted child list
            curr = curr->next;
        }

        // Step 2: Use a dummy node to build result
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->child = smallest;
            tail = smallest;

            if (smallest->child) {
                minHeap.push(smallest->child);
            }

            // Break next pointer to avoid ambiguity
            tail->next = nullptr;
        }

        return dummy->child;
    }

    // Helper to convert sorted vector to child-based linked list
    ListNode* convertArrToLinkedList(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* curr = head;

        for (int i = 1; i < arr.size(); i++) {
            curr->child = new ListNode(arr[i]);
            curr = curr->child;
        }

        return head;
    }

    // Main function to flatten the special linked list
    ListNode* flattenLinkedList(ListNode* &head) {
        vector<int> arr;
        ListNode* curr = head;

        // Traverse through the list and collect all values
        while (curr != nullptr) {
            ListNode* t2 = curr;
            while (t2 != nullptr) {
                arr.push_back(t2->val);
                t2 = t2->child;
            }
            curr = curr->next;
        }

        // Sort all values
        sort(arr.begin(), arr.end());

        // Convert back to a single-level linked list using child pointer
        return convertArrToLinkedList(arr);
    }

    // Merge two sorted child-linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                res->child = list1;
                list1 = list1->child;
            } else {
                res->child = list2;
                list2 = list2->child;
            }
            res = res->child;
            res->next = nullptr;  // disconnect next pointer
        }

        if (list1) {
            res->child = list1;
        } else {
            res->child = list2;
        }

        return dummyNode->child;
    }
    // Recursively flatten the special linked list
    ListNode* flattenLinkedList(ListNode* &head) {
        // Base case: no more heads to flatten
        if (!head || !head->next) return head;

        // Flatten the rest of the list
        ListNode* rest = flattenLinkedList(head->next);

        // Merge current child list with flattened rest
        head = merge(head, rest);

        return head;
    }
};


ListNode* convertArrToLL(vector<int>& arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1; i < arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        mover -> next = temp;
        mover = temp; // mover = mover -> next;
    }
    return head;
}

void print(ListNode* head){
    while(head != NULL){
        cout << head -> val << " ";
        head = head -> child;  // ✅ Use child to follow flattened list
    }
    cout << endl;
}

int main() {
    /*
        Construct a sample special linked list:
        head1 -> head2 -> head3
         |        |        |
         3        2->10     1->7->11->12
    */

    ListNode* n1 = new ListNode(3);

    ListNode* n2 = new ListNode(2);
    n2->child = new ListNode(10);

    ListNode* n3 = new ListNode(1);
    n3->child = new ListNode(7);
    n3->child->child = new ListNode(11);
    n3->child->child->child = new ListNode(12);

    ListNode* n4 = new ListNode(4);
    n4->child = new ListNode(9);

    ListNode* n5 = new ListNode(5);
    n5->child = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    Solution sol;
    ListNode* flat = sol.flattenLinkedList(n1);

    print(flat);
}
