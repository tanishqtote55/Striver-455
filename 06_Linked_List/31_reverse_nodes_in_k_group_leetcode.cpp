/*
    25. Reverse Nodes in k-Group
    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.

    Example 1:

    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
    Example 2:

    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]    

    Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000
    
    Follow-up: Can you solve the problem in O(1) extra memory space?
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* tail) {
        if (head == tail) return tail;
        ListNode* newHead = reverse(head->next, tail);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* tail = head;
        
        for (int i = 1; i < k; i++) {
            tail = tail->next;
            if (!tail) return head; // Less than k nodes left; don't reverse
        }

        ListNode* nextGroup = tail->next;
        ListNode* newHead = reverse(head, tail);

        head->next = reverseKGroup(nextGroup, k);

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
    vector<int> arr = {1, 2, 3, 4, 5};  // Example input
    int k = 2;  // Example k-group size

    // Convert array to linked list
    ListNode* head = convertArrToLL(arr);

    cout << "Original list: ";
    print(head);

    // Reverse in k-group using the solution
    Solution sol;
    ListNode* newHead = sol.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    print(newHead);

    return 0;
}
