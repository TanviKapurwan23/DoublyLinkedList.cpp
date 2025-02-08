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

Node* insertBegin(Node* head, int data){
    Node* temp = new Node(data);  // Create a new node
    temp->next = head;            // Point the next of new node to head
    if(head != NULL){             // If head is not NULL
        head->prev = temp;        // Point the previous of head to new node
    }
    return temp;                  // Return the new node as head
}

int main(){
    Node* head = new Node(10);
    Node* temp1 = new Node(20);
    Node* temp2 = new Node(30);

    head->next = temp1;     // 10 -> 20
    temp1->prev = head;     // 10 <- 20
    temp1->next = temp2;    // 20 -> 30
    temp2->prev = temp1;    // 20 <- 30
  
    cout<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<endl;

    head = insertBegin(head, 5);  // 5 -> 10 -> 20 -> 30

    cout<<"After Insertion: "<<head->data<<" "<<head->next->data<<" "<<head->next->next->data<<" "<<head->next->next->next->data<<endl;


    


    return 0;
}


