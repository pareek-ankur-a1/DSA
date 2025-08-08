// reassign the elements by storing in a stack. TC- O(2N)
// reverse the links. visualize yourself. TC- O(N)

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

Node* reverseDLL(Node* head){
    Node* prev = NULL;
    Node* current = head;
    while(current){
        prev = current-> back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    return prev->back;
}

Node* reverseDLL_stack(Node* head){
    Node* mover = head;
    stack<int> st;
    while(mover){
        st.push(mover->data);
        mover = mover->next;
    }
    mover = head;
    while(mover){
        mover->data = st.top();
        st.pop();
        mover = mover->next;
    }
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
    vector<int> arr = {2, 4, 53, 42, 1};
    Node *head = Arr2DLL(arr);
    print(head);
    head = reverseDLL(head);
    print(head);
    head = reverseDLL_stack(head);
    print(head);
}