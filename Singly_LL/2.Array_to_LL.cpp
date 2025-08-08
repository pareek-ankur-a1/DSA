#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* Array2LL(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node* head = new Node(arr[0]); // never tamper the head
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next; // or mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {14,5,7};
    Node* head = Array2LL(arr);

    // traversal in a linked list given its head
    Node*temp = head;
    while(temp){ // temp != nullptr
        cout << temp->data << " ";
        temp = temp->next;
    }
}