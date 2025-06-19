/*
    Reverse a Doubly Linked List
    Problem Statement: Given a doubly linked list of size ‘N’ consisting of positive integers, your task is to reverse it and return the head of the modified doubly linked list.

    Examples

    Example 1:

    Input Format:
    DLL: 1 <-> 2 <-> 3 <-> 4
    Result: DLL: 4 <-> 3 <-> 2 <-> 1
    Explanation: The doubly linked list is reversed and its last node is returned at the new head pointer.

    Example 2:
    Input Format:
    DLL: 10 <-> 20 <-> 30
    Result: DLL: 30 <-> 20 <-> 10
    Explanation: In this case, the doubly linked list is reversed and its former tail is returned as its new head.
*/


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    // Data stored in the node
    int data;   
    // Pointer to the next node in the list 
    //(forward direction)
    Node* next;     
    // Pointer to the previous node in the list
    //(backward direction)
    Node* back;     

    // Constructor for a Node with both data,
    //a reference to the next node,
    //and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data,
    //and no references to the next and
    //previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array
// to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with
    //the first element of the array
    
    Node* head = new Node(arr[0]);
    
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the
        //array and set its 'back' pointer to
        //the previous node
        
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the
        //previous node to point to
        //the new node
        prev->next = temp; 
         // Move 'prev' to the newly created
         //node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

// Function to print the elements
//of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

// Stack Brute Force Approach
// Node* reverseDLL(Node* head){
//     if(head==NULL || head->next == NULL){
//         return head;
//     }
//     stack<int> st;
//     Node* temp = head;
//     while(temp!=NULL){
//         st.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp!=NULL){
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return head;
// }

Node* reverseDLL(Node* head) {    
    if (head == NULL || head->next == NULL) {
        return head; 
    }    
    Node* prev = NULL;      
    Node* current = head;   
    // Traverse the linked list
    while (current != NULL) {
        prev = current->back;         
        current->back = current->next;         
        current->next = prev;                  
        current = current->back; 
    }    
    return prev->back;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);
}


