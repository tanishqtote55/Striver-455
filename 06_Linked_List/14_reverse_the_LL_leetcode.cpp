/*
    206. Reverse Linked List
    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Example 1:

    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
    Example 2:

    Input: head = [1,2]
    Output: [2,1]
    Example 3:

    Input: head = []
    Output: []
    
    Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000
    
    Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

#include <iostream>
#include <vector>
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(current){
            front = current -> next;
            current -> next = prev;
            prev = current;
            current = front;
        }
        return prev;
    }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        // Recursive step:
        // Reverse the linked list starting 
        // from the second node (head->next).
        ListNode* newHead = reverseList(head->next);
        
        // Save a reference to the node following
        // the current 'head' node.
        ListNode* front = head->next;
        
        // Make the 'front' node point to the current
        // 'head' node in the reversed order.
        front->next = head;
        
        // Break the link from the current 'head' node
        // to the 'front' node to avoid cycles.
        head->next = NULL;
        
        // Return the 'newHead,' which is the new
        // head of the reversed linked list.
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
    vector<int> arr = {1, 2, 3, 4, 5, 6}; // Try with even length too like {1, 2, 3, 4, 5, 6}
    int n = sizeof(arr)/sizeof(arr[0]);

    ListNode* head = convertArrToLL(arr);
    
    Solution sol;
    head = sol.reverseList(head);
    print(head); // prints from middle to end
    return 0;
}