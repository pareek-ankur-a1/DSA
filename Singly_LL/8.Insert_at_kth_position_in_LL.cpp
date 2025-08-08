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

Node* InsertatK(Node* head, int val, int k){
    if(head == nullptr){
        if(k == 1) return new Node(val);
        else return head;
    }
    if(k == 1){
        return new Node(val,head);
    }
    int cnt = 1;
    Node* temp = head;
    while(temp){
        if(cnt == k-1){
            Node* x = new Node(val,temp->next);
            temp->next = x;
            break;
        }
        cnt++;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    Node* head = Array2LL(arr);
    int val = 10;
    head = InsertatK(head, val, 7);

    //check by traversal
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}