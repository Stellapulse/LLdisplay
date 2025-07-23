#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;

}*first=NULL;

void reverse(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q; // Store the previous node
        q=p; // Move q to the current node
        p=p->next; // Move p to the next node
        q->next=r; // Reverse the link
    }
    first=q; // Update first to point to the new head
}

void Rdisplay(struct Node *p){
    if(p!=NULL){
        
    Rdisplay(p->next);
    cout<<p->data<<" ";
    }
    
    
    
}
void rdisplay(struct Node *p){
    if(p!=NULL){
     cout<<p->data<<" ";   
    rdisplay(p->next);
    
    }
    
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
void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main(){
    int A[]={1,2,3,4,5};

    create(A,5);

    display(first);

    Rdisplay(first);
    cout<<endl;
    reverse(first); // Reverse the linked list
    cout << "Reversed list: ";

    rdisplay(first);

    return 0;

}