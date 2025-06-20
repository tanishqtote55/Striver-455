/*
    141. Linked List Cycle
    Given head, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

    Return true if there is a cycle in the linked list. Otherwise, return false.

    Example 1:

    Input: head = [3,2,0,-4], pos = 1
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
    Example 2:

    Input: head = [1,2], pos = 0
    Output: true
    Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
    Example 3:

    Input: head = [1], pos = -1
    Output: false
    Explanation: There is no cycle in the linked list.   

    Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

    Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

#include <iostream>
#include <vector>
#include <unordered_map>
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> nodeMap;
        while(temp){
            if(nodeMap.count(temp) != 0){
                return temp;
            }
            nodeMap[temp] = 1;
            temp = temp -> next;
        }
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        // Initialize a slow and fast pointers to the head of the list
        ListNode* slow = head;  
        ListNode* fast = head;  

        // Phase 1: Detect the loop
        while (fast != NULL && fast->next != NULL) {
            // Move slow one step
            slow = slow->next;        
            // Move fast two steps
            fast = fast->next->next;  
            // If slow and fast meet, a loop is detected
            if (slow == fast) {
                // Reset the slow pointer to the head of the list
                slow = head; 
                // Phase 2: Find the first node of the loop
                while (slow != fast) {
                    // Move slow and fast one step at a time
                    slow = slow->next;  
                    fast = fast->next;  
                    // When slow and fast meet again, it's the first node of the loop
                }
                // Return the first node of the loop
                return slow;  
            }
        }
        // If no loop is found, return NULL
        return NULL; 
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
    // Creating nodes manually
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // Creates a cycle starting at node 3

    Solution sol;
    ListNode* startNode = sol.detectCycle(head);

    if(startNode) {
        cout << "Cycle detected at node with value: " << startNode->val << endl;
    } else {
        cout << "No cycle in the linked list.\n";
    }

    return 0;
}
