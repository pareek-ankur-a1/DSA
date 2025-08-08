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

Node* InsertBeforeValue(Node* head, int val, int el){
    if(head == nullptr){
        return NULL;
    }
    if(head->data == val){
        return new Node(el,head);
    }
    Node* temp = head;
    while(temp->next){
        if(temp->next->data == val){
            Node* x = new Node(el,temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5};
    Node* head = Array2LL(arr);
    int val = 4;
    head = InsertBeforeValue(head, val, 10);

    //check by traversal
    Node*temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}