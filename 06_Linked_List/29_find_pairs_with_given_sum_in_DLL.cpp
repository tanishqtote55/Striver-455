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
    // vector<vector<int>> findPairs(ListNode* head, int target){
    //     if (!head || !head->next) return {};
    //     vector<vector<int>> ans;
    //     ListNode* temp1 = head;
    //     while (temp1) {
    //         ListNode* temp2 = temp1->next;
    //         while (temp2 != NULL && temp1->val + temp2->val <= target) {
    //             if (temp1->val + temp2->val == target) {
    //                 ans.push_back({temp1->val, temp2->val});
    //             }
    //             temp2 = temp2->next;
    //         }
    //         temp1 = temp1->next;
    //     }
    //     return ans;
    // }
    
    vector<vector<int>> findPairs(ListNode* head, int target){
        if (!head || !head->next) return {};
        vector<vector<int>> ans;
        ListNode* left = head;
        ListNode* temp = head;
        ListNode* right = NULL;
        while(temp){
            right = temp;
            temp = temp -> next;
        }
        while(left -> val < right -> val){
            if(left -> val + right -> val == target){
                ans.push_back({left -> val, right -> val});
                left = left -> next;
                right = right -> prev;
            } else if(left -> val + right -> val < target){
                left = left -> next;
            } else {
                right = right -> prev;
            }
        }
        return ans;
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
    vector<int> arr = {1, 2, 3, 4, 5, 6}; // Sample list
    int target = 7;
    // Convert array to doubly linked list
    ListNode* head = convertArrToLL(arr);
    // Set the prev pointers manually
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp) {
        temp->prev = prev;
        prev = temp;
        temp = temp->next;
    }
    cout << "Original DLL: ";
    print(head);
    vector<vector<int>> result = sol.findPairs(head, target);
    cout << "Pairs with sum " << target << ": ";
    for (auto &pair : result) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
    return 0;
}
