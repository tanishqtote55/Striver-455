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

// Deletion of Head
Node* removeHead(Node* head){
    if(head == NULL || head -> next == NULL) return NULL;
    Node* temp = head;
    head = head -> next;
    head -> back = NULL;
    delete temp;
    return head;
}

// Deletion of Tail
Node* removeTail(Node* head){
    if(head == NULL || head -> next == NULL) return NULL;
    Node* tail = head;
    while(tail -> next != NULL){
        tail = tail -> next;
    }
    Node* newTail = tail -> back;
    newTail -> next = nullptr;
    delete tail;
    return head;
}

// Deletion of Kth Element
Node* removesKthElement(Node* head, int k){
    if(head == NULL) return head;
    // if(k == 1){
    //     Node* temp = head;
    //     head = head -> next;
    //     head -> back = nullptr;
    //     delete temp;
    //     return head;
    // }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* front = temp -> next;

    // if(temp -> next == NULL){
    //     temp -> back -> next = nullptr;
    //     delete temp;
    //     return head;
    // }else{
    //     temp -> back -> next = temp -> next;
    //     temp -> next -> back = temp -> back;
    //     delete temp;
    //     return head;
    // }

    if(prev == NULL && front == NULL) {
        return NULL;
    } else if(prev == NULL){
        return removeHead(head);
    } else if(front == NULL){
        return removeTail(head);
    }
    prev -> next = front;
    front -> back = prev;
    delete temp;    
    return head;
}

// Deletion by value
Node* removesValue(Node* head, int value){
    if(head == NULL) return head;
    if(value == head -> data){
        Node* temp = head;
        head = head -> next;
        head -> back = nullptr;
        delete temp;
        return head;
    }
    Node* temp = head;
    while(temp != NULL){
        if(value == temp -> data){
            if (temp->back) temp->back->next = temp->next;
            if (temp->next) temp->next->back = temp->back;
            delete temp;
            break;
        }
        temp = temp -> next;
    }
    return head;
}

// Deletion of Node Except Head Node
void deleteNode(Node* temp){
    Node* prev = temp -> back;
    Node* front = temp -> next;

    if(front == NULL){
        prev -> next = nullptr;
        temp -> back = nullptr;
        free(temp);
        return;
    }
    prev -> next = front;
    front -> back = prev;
    delete temp;
}

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrToDLL(arr);
    // head = removeHead(head);
    // head = removeTail(head);
    // head = removesKthElement(head, 1);
    // head = removesValue(head, 7);
    deleteNode(head -> next -> next);
    print(head);
    return 0;
}