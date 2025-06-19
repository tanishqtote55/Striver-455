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

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrToLL(arr);
    cout << checkIfPresent(head, 12) << '\n';
    
    return 0;
}

// Time Complexity: O(N) in the worst case if the element is not found. O(1) in the best case if the element is the first element. 
// Space Complexity: O(1) as we did not use any extra space.