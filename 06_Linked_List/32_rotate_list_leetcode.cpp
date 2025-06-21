/*
    61. Rotate List

    Given the head of a linked list, rotate the list to the right by k places.

    Example 1:

    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]
    Example 2:

    Input: head = [0,1,2], k = 4
    Output: [2,0,1]

    Constraints:

    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* secondLastNode(ListNode* head) {
        if (!head || !head->next) return nullptr;  // edge case: list has < 2 nodes
        while (head->next && head->next->next) {
            head = head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        k = k % length;
        while (k--) {
            ListNode* temp = head;
            ListNode* secondLast = secondLastNode(head);
            if (!secondLast) return head;  // list has only 1 node
            ListNode* tail = secondLast->next;
            tail->next = temp;
            secondLast->next = nullptr;
            head = tail;
        }
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Compute effective rotation
        k = k % length;
        int stepsToNewHead = length - k;

        // Step 4: Find new head and break the circle
        ListNode* newTail = head;
        while (--stepsToNewHead) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
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
        head = head -> next;
    }
    cout << endl;
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    ListNode* head1 = convertArrToLL(arr1);

    cout << "Original List 1: ";
    print(head1);

    Solution sol;
    ListNode* rotated1 = sol.rotateRight(head1, k1);

    cout << "Rotated List 1 (k = " << k1 << "): ";
    print(rotated1);
    cout << endl;

    // Test case 2
    vector<int> arr2 = {0, 1, 2};
    int k2 = 4;
    ListNode* head2 = convertArrToLL(arr2);

    cout << "Original List 2: ";
    print(head2);

    ListNode* rotated2 = sol.rotateRight(head2, k2);

    cout << "Rotated List 2 (k = " << k2 << "): ";
    print(rotated2);
    cout << endl;

    return 0;
}
