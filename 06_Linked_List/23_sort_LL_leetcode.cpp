/*
    148. Sort List
    Given the head of a linked list, return the list after sorting it in ascending order.

    Example 1:

    Input: head = [4,2,1,3]
    Output: [1,2,3,4]
    Example 2:

    Input: head = [-1,5,3,4,0]
    Output: [-1,0,3,4,5]
    Example 3:

    Input: head = []
    Output: []
    
    Constraints:

    The number of nodes in the list is in the range [0, 5 * 104].
    -105 <= Node.val <= 105
    
    Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        for(int i = 0; i < arr.size(); i++){
            temp -> val = arr[i];  
            temp = temp->next; 
        }
        return head; 
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining part
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    // Main sort function using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the list at the middle
        prev->next = nullptr;

        // Step 2: Sort each half recursively
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // Step 3: Merge the sorted halves
        return merge(l1, l2);
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
    head -> next -> next = new ListNode(5);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(3);
    cout << "Original Linked List: ";
    print(head);
    Solution sol;
    head = sol.sortList(head);
    print(head);
    return 0;
}