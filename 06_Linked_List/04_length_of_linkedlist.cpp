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

int main(){
    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArrToLL(arr);
    cout << "Length of the LL is: " << lengthOfLL(head) << "\n";
    
    return 0;
}

// Time Complexity: 
// Since we are iterating over the entire list,  time complexity is O(N).
// Space Complexity:
// We are not using any extra space, thus space complexity is O(1) or constant.