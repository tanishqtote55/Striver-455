/*
    Remove duplicated from sorted DLL
    Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

    Return the head of the modified linked list.

    Examples:
    Input: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
    Output: head -> 1 <-> 3 <-> 4 <-> 5
    Explanation: head -> 1 <-> 1 <-> 3 <-> 3 <-> 4 <-> 5
    The underlined nodes were deleted to get the desired result.

    Input: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2
    Output: head -> 1 <-> 2
    Explanation: head -> 1 <-> 1 <-> 1 <-> 1 <-> 1 <-> 2
    The underlined nodes were deleted to get the desired result.
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
    ListNode * removeDuplicates(ListNode *head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* current = head;
        ListNode* next = current -> next;
        while(next){
            if(next -> val == current -> val){
                ListNode* deleteNode = next;
                next = next -> next;
                current -> next = next;
                if(next) next -> prev = current;
                delete deleteNode;
            } else{
                next = next -> next;
                current = current -> next;
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
    vector<int> arr = {1, 1, 3, 3, 4, 5};  // You can change this to test other cases
    ListNode* head = convertArrToLL(arr);

    // Fix `prev` pointers since your convert function only sets `next`
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp) {
        temp->prev = prev;
        prev = temp;
        temp = temp->next;
    }

    cout << "Original DLL: ";
    print(head);

    Solution sol;
    head = sol.removeDuplicates(head);

    cout << "Modified DLL: ";
    print(head);

    return 0;
}
