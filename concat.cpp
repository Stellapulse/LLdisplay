#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node* next;
} *first = NULL,*second = NULL,*third=NULL;

int isloop(struct Node *f){
    struct Node *p,*q;
    p=q=f; // Initialize both pointers to the start of the list
    do {
        p = p->next; // Move p one step
        q = q->next; // Move q one step
        if(q != NULL) {
            q = q->next; // Move q another step
        }
    } while(p && q && p != q); // Continue until they meet or reach the end

    if(p == q) {
        return true; // Loop detected
    } else {
        return false; // No loop detected
    }
}


 void merging(struct Node *p, struct Node *q) {
    struct Node *last;
    if(p->data < q->data) {
        third = last = p; // Initialize third and last to the smaller node
        p = p->next; // Move p to the next node
        last->next = NULL; // Initialize last's next to NULL
    } else {
        third = last = q; // Initialize third and last to the smaller node
        q = q->next; // Move q to the next node
        last->next = NULL; // Initialize last's next to NULL
    }
    while(p != NULL && q != NULL) {
        if(p->data < q->data) {
            last->next = p; // Link the smaller node to the merged list
            last = p; // Move last to the newly added node
            p = p->next; // Move p to the next node
            last->next = NULL; // Ensure last's next is NULL
        } else {
            last->next = q; // Link the smaller node to the merged list
            last = q; // Move last to the newly added node
            q = q->next; // Move q to the next node
            last->next = NULL; // Ensure last's next is NULL
        }
    }
    if(p != NULL) {
        last->next = p; // If there are remaining nodes in p, link them
    } else {
        last->next = q; // If there are remaining nodes in q, link them
    }
}    
    
   void concate(struct Node *p, struct Node *q) {
    third=p;
    while(p->next != NULL) 
        p = p->next; // Traverse to the end of the first list
    
    p->next=q;
    
    
}
   
 void create(int A[],int n){
    struct Node *t,*last;
    first = new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}
 void create2(int A[],int n){
    struct Node *t,*last;
    second = new Node;
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
  int A[]={2,8,10,15,21};
 // int B[]={4,7,12,14,18};
  create(A,5);
 // create2(B,5);
 // cout<<"merged"<<endl;

 // merging(first,second);
 // display(third);
  struct Node *t1,*t2;
   /* t1=first->next->next; // Point to the third node of the  list
    t2=first->next->next->next->next; // Point to the last node of the list
    t2->next=t1; // Create a ll loop by linking the last node to the third node */

    isloop(first) ? cout << "Loop detected" << endl : cout << "No loop detected" << endl;

  return 0;

}