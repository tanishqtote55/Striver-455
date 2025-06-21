/*
    138. Copy List with Random Pointer
    A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

    Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

    For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

    Return the head of the copied linked list.

    The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
    Your code will only be given the head of the original linked list.

    Example 1:

    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Example 2:

    Input: head = [[1,1],[2,1]]
    Output: [[1,1],[2,1]]
    Example 3:

    Input: head = [[3,null],[3,0],[3,null]]
    Output: [[3,null],[3,0],[3,null]]

    Constraints:

    0 <= n <= 1000
    -104 <= Node.val <= 104
    Node.random is null or is pointing to some node in the linked list.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

/* Definition for a Node. */
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    // Node* copyRandomList(Node* head) {
    //     if (head == nullptr) return nullptr;

    //     // Step 1: Create a map to hold original node -> copied node
    //     unordered_map<Node*, Node*> oldToNew;

    //     // Step 2: First pass - create all new nodes and map them
    //     Node* temp = head;
    //     while (temp != nullptr) {
    //         oldToNew[temp] = new Node(temp->val);
    //         temp = temp->next;
    //     }

    //     // Step 3: Second pass - assign next and random pointers
    //     temp = head;
    //     while (temp != nullptr) {
    //         oldToNew[temp]->next = oldToNew[temp->next];
    //         oldToNew[temp]->random = oldToNew[temp->random];
    //         temp = temp->next;
    //     }

    //     // Step 4: Return the head of the copied list
    //     return oldToNew[head];
    // }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Clone each node and insert it right after the original node
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Step 2: Assign random pointers to the cloned nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            } else {
                curr->next->random = nullptr;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the copied list from the original list
        Node* dummyHead = new Node(0);
        Node* copyCurr = dummyHead;
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;       // restore original list
            copyCurr->next = copy;         // build copied list
            copyCurr = copy;
            curr = curr->next;
        }

        return dummyHead->next;
    }
};


// Utility function to print the list (val and random's val or null)
void printList(Node* head) {
    while (head) {
        cout << "[" << head->val << ", ";
        if (head->random)
            cout << head->random->val;
        else
            cout << "null";
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a test case: [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List: ";
    printList(n1);

    Solution sol;
    Node* copiedHead = sol.copyRandomList(n1);

    cout << "Copied List:   ";
    printList(copiedHead);

    return 0;
}