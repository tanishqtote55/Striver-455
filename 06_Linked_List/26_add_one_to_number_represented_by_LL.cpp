/*
    Add one to a number represented by LL
    Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.\

    The number will contain no leading zeroes except when the value represented is zero itself.

    Examples:
    Input: head -> 1 -> 2 -> 3

    Output: head -> 1 -> 2 -> 4

    Explanation: The number represented by the linked list = 123.

    123 + 1 = 124.

    Input: head -> 9 -> 9

    Output: head -> 1 -> 0 -> 0

    Explanation: The number represented by the linked list = 99.

    99 + 1 = 100.
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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* addOne(ListNode* head) {
        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Add 1 to the number
        ListNode* curr = head;
        int carry = 1;
        while (curr && carry) {
            int sum = curr->val + carry;
            curr->val = sum % 10;
            carry = sum / 10;

            // If we are at the last node and there's still a carry, add a new node
            if (!curr->next && carry) {
                curr->next = new ListNode(0);
            }
            curr = curr->next;
        }

        // Step 3: Reverse back and return
        return reverse(head);
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

    // Test Case 1: 1 -> 2 -> 3
    vector<int> arr1 = {1, 2, 3};
    ListNode* head1 = convertArrToLL(arr1);
    cout << "Input: ";
    print(head1);
    ListNode* result1 = sol.addOne(head1);
    cout << "Output: ";
    print(result1);
    cout << endl;

    // Test Case 2: 9 -> 9
    vector<int> arr2 = {9, 9};
    ListNode* head2 = convertArrToLL(arr2);
    cout << "Input: ";
    print(head2);
    ListNode* result2 = sol.addOne(head2);
    cout << "Output: ";
    print(result2);
    cout << endl;

    return 0;
}
