/*
    Delete all occurrences of a key in DLL
    Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

    Examples:
    Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

    Output: head -> 2 <-> 3 <-> 4

    Explanation: All nodes with the value 1 were removed.

    Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

    Output: head -> 3 <-> -1 <-> 4

    Explanation: All nodes with the value 2 were removed.

    Note that the value of head is changed.
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
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        while(head && head -> val == target){
            ListNode* curr = head;
            head = head -> next;
            if(head) head -> prev = NULL;
            delete curr;
        }
        ListNode* temp = head;
        while(temp){
            if(temp -> val == target){
                ListNode* curr = temp;
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                temp = temp -> next;
                delete curr;

            } else{
                temp = temp -> next;
            }
        }
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
        head = head -> next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1
    vector<int> arr1 = {1, 2, 3, 1, 4};
    ListNode* head1 = convertArrToLL(arr1);

    // Fix prev pointers for doubly linked list
    ListNode* temp = head1;
    ListNode* prev = NULL;
    while (temp) {
        temp->prev = prev;
        prev = temp;
        temp = temp->next;
    }

    cout << "Original DLL: ";
    print(head1);
    head1 = sol.deleteAllOccurrences(head1, 1);
    cout << "After deleting 1: ";
    print(head1);

    cout << endl;

    // Example 2: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2
    vector<int> arr2 = {2, 3, -1, 4, 2};
    ListNode* head2 = convertArrToLL(arr2);

    // Fix prev pointers
    temp = head2;
    prev = NULL;
    while (temp) {
        temp->prev = prev;
        prev = temp;
        temp = temp->next;
    }

    cout << "Original DLL: ";
    print(head2);
    head2 = sol.deleteAllOccurrences(head2, 2);
    cout << "After deleting 2: ";
    print(head2);

    return 0;
}
