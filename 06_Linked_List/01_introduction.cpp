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

int main(){
    int x = 2;
    int* t = &x; // y reference x
    cout << t << '\n';

    vector<int> arr = {2,5,8,7};

    // Create a Node 'x' with the first element of the vector and a null next reference
    // Node x = Node(arr[0], nullptr);
    // cout << x.data << " " << x.next << '\n';
    // // Create a pointer 'y' pointing to the Node 'x'
    // Node* y = &x;
    
    Node* y = new Node(arr[0]);
    
    cout << y << '\n'; // returns the memory value
    cout << y -> data << '\n'; // returns the data stored at that memory point
}

// In java there is no pointers like Node* 
// In java there is null instead of nullptr 
// In java there is y.data instead y -> data 