#include <iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};

void display(struct node *p){
    cout<<"elements are: "<<endl;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}

int isfull(){
    struct node n=(struct node)malloc(sizeof(struct node));
    if(n==NULL)
        return 1;
    else
        return 0;
}

int isempty(struct node *top){
    if(top==NULL)
        return 1;
    else
        return 0;
}

struct node* push(struct node *top,int x){
    if(isfull()){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        struct node n=(struct node)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
    }
}
struct node* pop(struct node **top){
    if(isempty(*top))
        cout<<"Stack Underflow"<<endl;
    else{
        struct node *temp=*top;
        int x=(*top)->data;
        *top=temp->next;
        free(temp);
        cout<<"popped element is: "<<x<<endl;
    }
}
int main()
{
    struct node *top=NULL;
    top=push(top,56);
    top=push(top,5);
    top=push(top,567);
    display(top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    return 0;
}
