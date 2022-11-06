#include <iostream>
#include<stdlib.h>
using namespace std;
struct node *f=NULL;
struct node *r=NULL;
struct node{
    int data;
    struct node *next;
};

void display(){
    cout<<"elements are: "<<endl;
    struct node *p=f;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

struct node* enqueue(int val){
    struct node n=(struct node)malloc(sizeof(struct node));
    if(n==NULL)
        cout<<"Queue is Full"<<endl;
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL)
            f=r=n;
        else{
            r->next=n;
            r=n;
        }
    }
}
struct node *dequeue(){
    if(f==NULL)
        cout<<"Queue is empty"<<endl;
    else{
        struct node *temp=f;
        f=f->next;
        cout<<"Deleted element is: "<<temp->data<<endl;
        free(temp);
    }
}
int main()
{
    enqueue(78);
    enqueue(8);
    enqueue(7899);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
