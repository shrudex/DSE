#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next;
};

void traversal(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

struct node *insertatend(struct node *head,int num){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=ptr;
    ptr->data=num;
    ptr->next=NULL;
    return head;
}

struct node *insertatbeginning(struct node *head,int num){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    ptr->data=num;
    ptr->next=head;
    return ptr;
}

struct node *insertbefore(struct node *head,int num,int ele){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    struct node *q=temp->next;
    while(q->data!=num){
        temp=temp->next;
        q=q->next;
    }
    ptr->data=ele;
    temp->next=ptr;
    ptr->next=q;
    return head;
}

struct node *deletenode(struct node *head,int num){
    if(head->data==num){
        head=head->next;
        return head;
    }
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    struct node *q=temp->next;
    while(q->data!=num){
        temp=temp->next;
        q=q->next;
    }
    temp->next=q->next;
    return head;
}

struct node *insertafter(struct node *head,int num,int ele){
    struct node ptr=(struct node)malloc(sizeof(struct node));
    struct node *temp=head;
    while(temp->data!=num){
        temp=temp->next;
    }
    ptr->data=ele;
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}

int main()
{
    struct node head=(struct node)malloc(sizeof(struct node));
    struct node second=(struct node)malloc(sizeof(struct node));
    struct node third=(struct node)malloc(sizeof(struct node));
    struct node fourth=(struct node)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=fourth;
    fourth->data=40;
    fourth->next=NULL;
    cout<<"Press 1 to insert in beginning of the list "<<endl;
    cout<<"Press 2 to insert in the end of the list "<<endl;
    cout<<"Press 3 to insert before another element of the list "<<endl;
    cout<<"Press 4 to insert after another element of the list "<<endl;
    cout<<"Press 5 to delete element of the list "<<endl;
    cout<<"Press 6 to print the list "<<endl;
    cout<<"Press 7 to exit: "<<endl;
    int ch;
    do{
        cout<<"enter your choice: "<<endl;
        cin>>ch;
        switch(ch){
            
            case 1:
            int num1;
            cout<<"enter element: "<<endl;
            cin>>num1;
            head=insertatbeginning(head,num1);
            break;
            
            case 2:
            int num2;
            cout<<"enter element: "<<endl;
            cin>>num2;
            head=insertatend(head,num2);
            break;
            
            case 3:
            int num3,num4;
            cout<<"enter number after which you want to insert: "<<endl;
            cin>>num3;
            cout<<"enter number to insert: "<<endl;
            cin>>num4;
            head=insertafter(head,num3,num4);
            break;
            
            case 4:
            int num5,num6;
            cout<<"enter number before which you want to insert: "<<endl;
            cin>>num5;
            cout<<"enter number to insert: "<<endl;
            cin>>num6;
            head=insertbefore(head,num5,num6);
            break;
            
            case 5:
            int num7;
            cout<<"enter number to delete: "<<endl;
            cin>>num7;
            head=deletenode(head,num7);
            break;
            
            case 6:
            cout<<"elements are: "<<endl;
            traversal(head);
            break;
            
            case 7:
                cout<<"Exited"<<endl;
                break;
                
            default:
                cout<<"Invalid choice: "<<endl;
        }
    }while(ch!=7);
    return 0;
}
