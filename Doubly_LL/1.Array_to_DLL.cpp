#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* Arr2DLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i], prev, nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {2,4,53,42,1};
    Node* head = Arr2DLL(arr);
    while(head->next){
        cout << head->data << " ";
        head = head-> next;
    }
    while(head){
        cout << head->data << " ";
        head = head->back;
    }
    
}