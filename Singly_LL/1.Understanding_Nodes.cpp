#include<bits/stdc++.h>
using namespace std;

struct Node{ // we can also use class if we want to use OOPS
    public: // access modifier
    int data; // to store data at the node
    Node* next; // pointer to the next node

    public:
    //constructor1
    Node(int data1, Node* next1){
        data = data1; // Initialize data with the provided value
        next = next1; // Initialize next pointer with provided address
    }
    //constructor2
    Node(int data1){
        data = data1; // initialize data
        next = nullptr; // Initialize next as null since it's the end of the list
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr = {1,5,7,9};
 
    // Method 1
    Node x = Node(arr[3],nullptr); //object created on stack
    // or Node x(arr[3],nullptr);
    Node *y = &x;
    cout << x.data << " " << y->data << endl;

    // Method 2 
    Node *z = new Node(arr[2],y); //object created on heap
    
    cout << z << endl;
    cout << z->data << endl; //*(a).next == a->next
    cout << z->next->data;
}

// the new keyword in C++ is used to dynamically allocate memory on the heap, rather than the stack.
//  new returns a pointer to that newly created object, which is then stored in z.
//  Without new, the object would be created on the stack, and it would be destroyed automatically when the current scope (like a function) ends. Using heap memeory ensures the object stays in memory until you explicitly delete it using free or delete.

// read about stack and heap memeories