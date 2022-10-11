#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;
int total=0;
struct Node
{
    int data;
    Node *next;
};
void insert_last(Node* ptr, int item)
{
    Node * newNode, *tmp;
    tmp=ptr;
    newNode=new Node;
    while(1)
    {
        if(tmp->next==NULL)
        {
            tmp->next=newNode;
            newNode->data=item;
            newNode->next=NULL;
            break;
        }
        tmp=tmp->next;
    }
}
void insert_first(Node* ptr, int item)
{
    Node * newNode, *tmp;
    newNode=new Node;
    newNode->next=ptr->next;
    newNode->data=item;
    ptr->next=newNode;
}
void delete_first(Node* ptr)
{
    Node * newNode;
    newNode=new Node;
    newNode=ptr->next;
    ptr->next=newNode->next;
}
void delete_last(Node* ptr)
{
    int i;
    Node  *tmp;
    tmp=ptr;
    while(1)
    {
        if(tmp->next->next!=NULL)
        {
            tmp=tmp->next;
        }
        else
        {
            tmp->next=NULL;
            break;
        }
    }
}
void insert_custom(Node *ptr, int n, int item)
{
    int i;
    Node *newNode, *tmp;
    tmp=ptr;
    newNode=new Node;
    newNode->data=item;
    for(i=1; i<n; i++)
    {
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;

}
void delete_custom(Node *ptr, int n)
{
    Node *tmp;
    tmp=ptr;
    int i;
    for(i=1; i<n; i++)
    {
        tmp=tmp->next;
    }
    tmp->next=tmp->next->next;
}
void display_list(Node * ptr)
{
    if(total<=0)
    {
        cout<<"List is empty.";
    }
    else
    {
        while(1)
        {
            if(ptr->next==NULL)
            {
                break;
            }
            else
            {
                ptr=ptr->next;
                cout<<ptr->data<<" ";
            }
        }
    }
}
typedef struct Node NODE;
int main()
{
    int i,choose, item;
    char ch;
    NODE *head=NULL;
    head=new NODE;
    head->next=NULL;
    while(1)
    {
        system("CLS");
        cout<<"Current list: ";
        display_list(head);
        cout<<endl<<"Enter your choose: "<<endl;
        cout<<"1. Insert."<<endl;
        cout<<"2. Delete."<<endl;
        cout<<"3. Exit."<<endl;
        cin>>choose;
        if(choose==1)
        {
            system("CLS");
            cout<<"Current list: ";
            display_list(head);
            cout<<endl;
            if(total==0)
            {
                cout<<"Enter an element to insert: ";
                cin>>item;
                insert_first(head,item);
                total++;
            }
            else
            {
                cout<<"Enter 'F' & Element to insert at first."<<endl;
                cout<<"Enter 'L' & Element to insert at last."<<endl;
                cout<<"Enter 'n'th position & Element to insert at nth Position."<<endl;
                cin>>ch>>item;
                if(ch=='F')
                {
                    insert_first(head,item);
                    total++;
                }
                else if(ch=='L')
                {
                    insert_last(head,item);
                    total++;
                }
                else if(isdigit(ch))
                {
                    int a;
                    a=ch-'0';
                    if(a>total+1)
                    {
                        cout<<"Invalid position. Try again.";
                        Sleep(2000);
                    }
                    else
                    {
                        insert_custom(head,a,item);
                        total++;
                    }
                }
            }
        }
        else if(choose==2)
        {
            if(total<=0)
            {
                system("CLS");
                cout<<"The list is Empty."<<endl;
                Sleep(3000);
            }
            else if(total==1)
            {
                delete_last(head);
                total--;
            }
            else
            {
                system("CLS");
                cout<<"Current list: ";
                display_list(head);
                cout<<endl;
                cout<<"Enter 'F' to delete at first."<<endl;
                cout<<"Enter 'L' to delete at last."<<endl;
                cout<<"Enter 'n'th position to delete the nth element."<<endl;
                cin>>ch;
                if(ch=='F')
                {
                    delete_first(head);
                    total--;
                }
                else if(ch=='L')
                {
                    delete_last(head);
                    total--;
                }
                else if(isdigit(ch))
                {
                    int a;
                    a=ch-'0';
                    if(a>total)
                    {
                        cout<<"Invalid position. Try again.";
                        Sleep(2000);
                    }
                    else
                    {
                        delete_custom(head,a);
                        total--;
                    }
                }
            }
        }
        else if(choose==3)
        {
            break;
        }
    }
    return 0;
}
