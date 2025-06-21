/*
    19. Remove Nth Node From End of List
    Given the head of a linked list, remove the nth node from the end of the list and return its head.

    Example 1:

    Input: head = [1,2,3,4,5], n = 2
    Output: [1,2,3,5]
    Example 2:

    Input: head = [1], n = 1
    Output: []
    Example 3:

    Input: head = [1,2], n = 1
    Output: [1]

    Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
    
    Follow up: Could you do this in one pass?
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp -> next;
        }
        if(len == n) {
            ListNode* newhead = head->next;
            delete (head);
            return newhead;
        }
        len = len - n;
        temp = head;
        while(len > 1){
            len--;
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast n+1 steps ahead to reach node after the target
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if (fast == NULL)
            return head->next;

        // Move fast to the end, maintaining the gap
        while(fast -> next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete delNode;
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
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    cout << "Original Linked List: ";
    print(head);
    Solution sol;
    ListNode *newHead = sol.removeNthFromEnd(head, 2);
    print(newHead);
    return 0;
}