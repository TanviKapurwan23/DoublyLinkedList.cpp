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

Node *insertAtEnd(Node *head, int data){
    Node *temp  = new Node(data);     // Creating a new node
    if(head == NULL){                 // If the list is empty
       return temp;
    }
    Node *curr = head;                // Creating a pointer to traverse the list
    while(curr->next !=NULL){         // Traversing to the last node
        curr = curr->next;            // Moving to the next node
    }
    curr->next = temp;               // Pointing the next of last node to the new node
    temp->prev = curr;               // Pointing the previous of new node to the last node
    return head;
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

    head = insertAtEnd(head, 40);
    cout<<"After Insertion: "<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next->data<<endl;


    


    return 0;
}


