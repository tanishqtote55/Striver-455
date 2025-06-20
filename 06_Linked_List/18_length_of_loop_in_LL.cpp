/*
    Length of loop in LL
    Given the head of a singly linked list, find the length of the loop in the linked list if it exists. Return the length of the loop if it exists; otherwise, return 0.

    A loop exists in a linked list if some node in the list can be reached again by continuously following the next pointer. Internally, pos is used to denote the index (0-based) of the node from where the loop starts.

    Note that pos is not passed as a parameter.

    Examples:

    Input: head -> 1 -> 2 -> 3 -> 4 -> 5, pos = 1

    Output: 4

    Explanation: 2 -> 3 -> 4 -> 5 - >2, length of loop = 4.

    Input: head -> 1 -> 3 -> 7 -> 4, pos = -1

    Output: 0

    Explanation: No loop is present in the linked list.
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list
    Node* next;      
    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to return the length of loop using hashing
int lengthOfLoop(Node* head) {
    unordered_map<Node*, int> visitedNodes;     
    Node* temp = head; 
    
    // Initialize timer to track visited nodes
    int timer = 0; 
    // Traverse the linked list till temp reaches nullptr
    while (temp != NULL) {
        // If revisiting a node return the difference of timer values
        if (visitedNodes.find(temp) != visitedNodes.end()) {
            // Calculate the length of the loop
            int loopLength = timer - visitedNodes[temp];
            // Return the length of the loop
            return loopLength; 
        }
        // Store the current node and its timer value in the hashmap
        visitedNodes[temp] = timer;
        // Move to the next node
        temp = temp->next;
        // Increment the timer
        timer++;
    }
    // If traversal is completed and we reach the end of the list (null) means there is no loop
    return 0;
}

// Function to return the lenght of loop when slow and fast are on the same node
int findLength(Node* slow, Node* fast){ 
    // count to keep track of  nodes encountered in loop
    int cnt = 1;
    // move fast by one step
    fast = fast->next;
    // traverse fast till it  reaches back to slow
    while(slow!=fast){
        // at each node increase count by 1 and move fast forward by one step
        cnt++;
        fast = fast->next;
    }
    // loop terminates when fast reaches slow again and the count is returned
    return cnt;
}
// Function to find the length of the loop in a linked list
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    // Step 1: Traverse the list to detect a loop
    while (fast != nullptr && fast->next != nullptr) {
        // Move slow one step
        slow = slow->next;     
        // Move fast two steps
        fast = fast->next->next;
        // Step 2: If the slow and fast pointers meet, there is a loop
        if (slow == fast) {
            // return the number of nodes in the loop
            return findLength(slow, fast);
        }
    }
    // Step 3: If the fast pointer reaches the end, there is no loop
    return 0; 
}


int main() {
    // Create a sample linked
    // list with a loop
    
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}


