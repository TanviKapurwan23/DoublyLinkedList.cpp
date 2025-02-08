#include<iostream>
using namespace std;

struct Node{  // Node Structure
    int data;       // Data
    Node* next;     // Pointer to next node
    Node* prev;     // Pointer to previous node

    Node(int d){     // Constructor
        data = d;
        prev = NULL;
        next = NULL;
    }
};

Node *reverseDLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node *prev = NULL;    // Previous pointer
    Node *curr = head;    // Current pointer
    while(curr != NULL){    // Swapping the pointers
        prev = curr->prev;    
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;      // Returning the new head
}

int main(){
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp1;     
    temp1->prev = head;     
    temp1->next = temp2;    
    temp2->prev = temp1;    
  
    cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<endl;
    head = reverseDLL(head);
    cout<<"After Reverse: "<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<endl;

    return 0;
}


