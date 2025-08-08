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

Node* deleteHead(Node* head){
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head, Node* tail){
    Node* prev = tail->back;
    prev->next = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node* head, int k){
    if(head == nullptr) return nullptr;
    int cnt = 0;
    Node* temp = head;
    while(cnt < k){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* next = temp->next;
    if(prev == NULL && next == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(next == NULL){
        return deleteTail(head,temp);
    }
    else{
        prev->next = next;
        next->back = prev;
        delete temp;
        return head;
    }
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
    head = deleteKth(head, 3);
    print(head);
}