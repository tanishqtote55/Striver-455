/*
    Problem Statement: Given the head of a linked list and an integer value, find out whether the integer is present in the linked list or not. Return true if it is present, or else return false.
*/

#include <iostream>
#include <vector>

using namespace std;

class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    // constructor
    Node (int data1, Node* next1){
        data=data1;  // Initialize data with the provided value
        next=next1;  // Initialize next with the provided
    }
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};

Node* convertArrToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp; // mover = mover -> next;
    }
    return head;
}

int lengthOfLL(Node* head){
    int cnt = 0;
    // Traversal in Linked List
    Node* temp = head;
    while(temp){
        // cout << temp -> data << " ";
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp -> data == val) return 1;
        temp = temp -> next;
    }
    return 0;
}

void print(Node* head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

// Insertion at head
Node* insertHead(Node* head, int value){
    Node* temp = new Node(value, head);
    return temp;
}

// Insertion at tail
Node* insertTail(Node* head, int value){
    if(head == NULL){
        return new Node(value);
    }
    Node* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    Node* newNode = new Node(value);
    temp -> next = newNode;
    return head;
}

// Insertion at Kth Element 
Node* insertKthElement(Node* head, int k, int value){
    if(head == NULL) {
        if(k == 1) return new Node(value);        
        else return NULL;
    }
    if(k == 1) return new Node(value, head);

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == (k - 1)){
            Node* newNode = new Node(value, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// Insertion the element before the value x
Node* insertValue(Node* head, int x, int value){
    if(head == NULL) {
        return NULL;
    }
    if(head -> data == x){
        return new Node(value, head);
    } 

    Node* temp = head;
    while(temp != NULL){
        if(temp -> next -> data == x){
            Node* newNode = new Node(value, temp -> next);
            temp -> next = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrToLL(arr);
    // head = insertHead(head, 12);    
    // head = insertTail(head, 12);    
    // head = insertKthElement(head, 4, 12);    
    head = insertValue(head, 2, 12);    
    print(head);
    return 0;
}

// Time Complexity: O(1) for inserting the new head of the linked list and O(N) for inserting at the tail.
// Space Complexity: O(1), as we have not used any extra space.