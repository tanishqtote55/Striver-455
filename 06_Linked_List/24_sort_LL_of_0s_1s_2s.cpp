/*
    Sort a LL of 0's 1's and 2's
    100
    Hint
    Given the head of a singly linked list consisting of only 0, 1 or 2. Sort the given linked list and return the head of the modified list. Do it in-place by changing the links between the nodes without creating new nodes.

    Examples:
    Input: head -> 1 -> 0 -> 2 -> 0 -> 1

    Output: head -> 0 -> 0 -> 1 -> 1 -> 2

    Explanation: The values after sorting are [0, 0, 1, 1, 2].

    Input: head -> 1 -> 1 -> 1 -> 0

    Output: head -> 0 -> 1 -> 1 -> 1

    Explanation: The values after sorting are [0, 1, 1, 1].
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
    ListNode *sortList(ListNode *head) {
        ListNode* temp = head;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        while(temp){
            if(temp -> val == 0) cnt0++;
            else if(temp -> val == 1) cnt1++;
            else cnt2++;
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            if(cnt0){
                temp -> val = 0;
                cnt0--;
            }else if(cnt1){
                temp -> val = 1;
                cnt1--;
            }else{
                temp -> val = 2;
                cnt2--;
            }
            temp = temp -> next;
        }
        return head;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;

        // Dummy nodes
        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead = new ListNode(-1);
        ListNode* twoHead = new ListNode(-1);

        // Tails for each list
        ListNode* zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;

        // Distribute nodes into 0s, 1s, and 2s
        ListNode* temp = head;
        while (temp) {
            if (temp->val == 0) {
                zero->next = temp;
                zero = temp;
            } else if (temp->val == 1) {
                one->next = temp;
                one = temp;
            } else {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }

        // Connect the three lists
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = NULL;

        ListNode* newHead = zeroHead->next;

        // Free dummy nodes if desired (not mandatory in LeetCode)
        delete zeroHead;
        delete oneHead;
        delete twoHead;

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
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(0);
    head -> next -> next = new ListNode(0);
    head -> next -> next -> next = new ListNode(1);
    head -> next -> next -> next -> next = new ListNode(2);
    cout << "Original Linked List: ";
    print(head);
    Solution sol;
    head = sol.sortList(head);
    print(head);
    return 0;
}