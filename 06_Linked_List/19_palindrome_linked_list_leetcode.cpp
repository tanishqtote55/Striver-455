/*
    234. Palindrome Linked List

    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.    

    Example 1:

    Input: head = [1,2,2,1]
    Output: true
    Example 2:

    Input: head = [1,2]
    Output: false
    
    Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

    Follow up: Could you do it in O(n) time and O(1) space?
*/


#include <iostream>
#include <vector>
#include <unordered_map>
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
    // bool isPalindrome(ListNode* head) {
    //     if(head == NULL || head -> next == NULL) return true;
    //     stack<int> st;
    //     ListNode* temp = head;
    //     while(temp){
    //         st.push(temp -> val);
    //         temp = temp -> next;
    //     }
    //     temp = head;
    //     while(temp){
    //         if(temp -> val != st.top()) return false;
    //         st.pop();
    //         temp = temp -> next;
    //     }
    //     return true;
    // }

    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* newHead = reverseList(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare -> next != NULL && hare -> next -> next != NULL){
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
        }
        ListNode* newHead = reverseList(tortoise -> next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second){
            if(first -> val != second -> val){
                reverseList(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverseList(newHead);
        return true;
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
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(5);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next = new ListNode(1);
    cout << "Original Linked List: ";
    print(head);
    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}