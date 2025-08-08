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
    Node* head = new Node(arr[0]); 
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node* Insertatend(Node* head, int val){
    if(head == nullptr) return new Node(val,head);
    Node * temp = head;
    while(temp->next){
        temp = temp -> next;
    }
    temp->next = new Node(val);
    return head;
}

int main()
{
    vector<int> arr = {};
    Node* head = Array2LL(arr);
    int val = 90;
    head = Insertatend(head, val);

    //check by traversal
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}