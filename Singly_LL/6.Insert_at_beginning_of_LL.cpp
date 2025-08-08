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
    Node* head = new Node(arr[0]); 
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}


int main()
{
    vector<int> arr = {14,5,8,9,7};
    Node* head = Array2LL(arr);
    
    int val = 100;
    head = new Node(val,head); // one liner

    //check by traversal
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}