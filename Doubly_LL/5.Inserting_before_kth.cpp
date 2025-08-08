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
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* insertBeforeHead(Node* head, int el){
    Node* newnode = new Node(el,head,nullptr);
    head->back = newnode;
    return newnode;
}
Node* insertBeforeKth(Node* head, int el, int k){
    if(head == NULL) return nullptr;
    if(k == 1){
        return insertBeforeHead(head, el);
    }
    Node* temp = head;
    int cnt = 0;
    while(cnt < k){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newnode = new Node(el,temp,prev);
    prev->next = newnode;
    temp->back = newnode;
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    vector<int> arr = {2,4,53,42,1};
    Node* head = Arr2DLL(arr);
    head = insertBeforeKth(head, 100, 1);
    print(head);
}