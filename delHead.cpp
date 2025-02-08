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

Node* delHead(Node* head){
    if(head == NULL) return NULL; // If head is NULL return NULL

    if(head->next == NULL){
        delete head;
        return NULL;
    } else{
        Node* temp = head; // Store head in temp
        head = head->next; // Move head to next node
        head->prev = NULL; // Make previous of new head NULL
        delete temp;       // Delete old head
        return head;       // Return new head
    }
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
    head = delHead(head);

    if(head){
        cout<<"After Deleting Head:"<<" ";
        Node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
        } cout<<endl;
    }else{
        cout<<"List is empty"<<endl;
    }

    return 0;
}
