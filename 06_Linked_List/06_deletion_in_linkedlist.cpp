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

// Deletion of head
Node* removesHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

// Deletion of tail
Node* removesTail(Node* head){
    if(head == NULL || head -> next == NULL) return head;
    Node* temp = head;
    while(temp -> next -> next){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = nullptr;
    return head;
}

// Deletion of Kth Element
Node* removesKthElement(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev -> next = temp -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

// Deletion by value
Node* removesValue(Node* head, int value){
    if(head == NULL) return head;
    if(value == head -> data){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(value == temp -> data){
            prev -> next = temp -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrToLL(arr);
    // head = removesHead(head);    
    // head = removesTail(head);    
    // head = removesKthElement(head, 1);    
    head = removesValue(head, 8);    
    print(head);
    return 0;
}

//Time Complexity: O(N) for traversing the linked list and updating the tail.
// Space Complexity: O(1), as we have not used any extra space.