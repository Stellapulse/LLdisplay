#include<iostream>
using namespace std;


struct Node {
    int data;
    // Pointer to the next node in the linked list
    struct Node* next;
} *first=NULL;
void create(int A[], int n) {
    struct Node *t, *last;
    first = new Node; // Allocate memory for the first node
    first->data = A[0]; // Set the data for the first node
    first->next = NULL; // Initialize the next pointer to NULL
    last = first; // Set last to point to the first node

    for (int i = 1; i < n; i++) {
        t = new Node; // Allocate memory for the new node
        t->data = A[i]; // Set the data for the new node
        t->next = NULL; // Initialize the next pointer to NULL
        last->next = t; // Link the last node to the new node
        last = t; // Move last to point to the new node
    }
}

void display(struct Node* p) {
    while (p != NULL) {
        cout << p->data << " "; // Print the data of the current node
        p = p->next; // Move to the next node
    }
    cout << endl; // Print a newline at the end
}

int main() {
    int A[] = {3, 5, 7, 10, 15}; // Example array to create the linked list

    create(A, 5); // Create the linked list with the array

    display(first); // Display the linked list

    return 0; // Return success
}
