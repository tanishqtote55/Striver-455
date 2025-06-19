#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1; // Similar to a singly linked list, but now with a 'back' pointer.
        back = back1; // Addition of 'back' pointer for the doubly linked list.
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr; // Similar to a singly linked list.
        back = nullptr; // Addition of 'back' pointer initialization.
    }
};

Node* convertArrToDLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
// Insertion at head
Node* insertHead(Node* head, int value){
    Node* temp = new Node(value, head, nullptr);
    head -> back = temp;
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
    Node* newNode = new Node(value, temp, temp -> back);
    temp -> back -> next = newNode;
    temp -> back = newNode;
    return head;
}

// Insertion at Kth Element 
Node* insertKthElement(Node* head, int k, int value){
    if(k == 1){
        return insertHead(head, value); 
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break; 
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node(value, temp, prev);
    prev -> next = newNode;
    temp -> back = newNode;
    return head;
}

// Insertion the element before the value x
Node* insertValue(Node* head, int x, int value){
    if(head == NULL) {
        return NULL;
    }
    if(head -> data == x){
        Node* newNode = new Node(value);
        newNode->next = head;
        head->back = newNode;
        return newNode;
    } 

    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == x){
            Node* newNode = new Node(value);
            newNode->next = temp;
            newNode->back = temp->back;

            if (temp->back) temp->back->next = newNode;
            temp->back = newNode;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// Insertion of Node Except Head Node
void insertNode(Node* temp, int value){
    Node* prev = temp -> back;
    Node* newNode = new Node(value, temp, prev);
    prev -> next = newNode;
    temp -> back = newNode;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrToDLL(arr);
    // head = insertHead(head, 12);    
    // head = insertTail(head, 12);    
    // head = insertKthElement(head, 4, 12);    
    // head = insertValue(head, 2, 12);    
    insertNode(head -> next -> next, 12);
    print(head);
    return 0;
}