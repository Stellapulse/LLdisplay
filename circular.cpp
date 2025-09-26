#include<iostream>
using namespace std;

struct Node {
    int data;
   struct Node* next;
}*head ;

void create (int A[], int n) {
    int i;
    Node* t, *last;
    head = new Node; // Allocate memory for the first node
    head->data = A[0]; // Set the data for the first node           
    head->next = nullptr; // Initialize the next pointer to nullptr
    last = head; // Set last to point to the first node
    for (i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i]; // Set the data for the new node
        last->next = t; // Link the last node to the new node
        last =t;
        t->next = head;
    }
}

void display(struct Node* h) {
    do {
        cout << h->data << " "; // Print the data of the current node
        h = h->next; // Move to the next node
    } while (h != head);    
}

void Rdisplay(struct Node* h) {
      static int flag = 0;//  Static variable to keep track of the first call 
    if (h != head || flag == 0) {
        flag = 1;   
        cout << h->data << " "; 
        Rdisplay(h->next); 
    }
    flag = 0;
     // Reset flag after the recursive call
}



 int main(){
    int A[] = {3, 5, 7, 10, 15}; // Example array to create the circular linked list
    create(A, 5);   
    Rdisplay(head); // Display the circular linked list
    return 0; // Return success
 }
