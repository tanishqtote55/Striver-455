/*
    328. Odd Even Linked List
    Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

    The first node is considered odd, and the second node is even, and so on.

    Note that the relative order inside both the even and odd groups should remain as it was in the input.

    You must solve the problem in O(1) extra space complexity and O(n) time complexity.  

    Example 1:

    Input: head = [1,2,3,4,5]
    Output: [1,3,5,2,4]
    Example 2:

    Input: head = [2,1,3,5,6,4,7]
    Output: [2,3,6,7,1,5,4]
    
    Constraints:

    The number of nodes in the linked list is in the range [0, 104].
    -106 <= Node.val <= 106
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* evenhead = even;
        while (even && even->next) {
            odd->next = even->next;           // Link current odd to the next odd node
            odd = odd->next;                  // Move odd forward

            even->next = odd->next;           // Link current even to the next even node
            even = even->next;                // Move even forward
        }
        odd->next = evenhead;                 // Connect the end of odd list to the head of even list
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
    head -> next = new ListNode(5);
    head -> next -> next = new ListNode(2);
    head -> next -> next -> next = new ListNode(5);
    head -> next -> next -> next -> next = new ListNode(1);
    cout << "Original Linked List: ";
    print(head);
    Solution sol;
    ListNode *newHead = sol.oddEvenList(head);
    cout << "LinkedList After Segregration " << endl;
    print(newHead);
    return 0;
}