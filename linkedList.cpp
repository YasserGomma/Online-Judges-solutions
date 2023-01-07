#include <bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()), ((v).end())
#define sz(v) v.size()
#define endl "\n"
struct node{
    int data;
    node* next;
};
node* head=NULL;
void insertNode(int val);
void display();
void deleteNode(int val);
void insertNodeAtBeginning(int val);
void deleteNodeAtBeginning();
void deleteNodeAtEnd();

int main()
{
    insertNode(5);
    insertNode(10);
    insertNode(15);
    insertNode(7);
    display();
    cout<<"-----\n";
    deleteNode(15);
    display();
    cout<<"-----\n";
    insertNodeAtBeginning(1);
    display();
    cout<<"-----\n";
    deleteNodeAtBeginning();
    display();
    cout<<"-----\n";
    deleteNodeAtEnd();
    display();
    cout<<"-----\n";
}
void insertNode(int val)
{
   node *new_node= new node;
   new_node->data=val;
   if(head==NULL)
   {
       head=new_node;
       new_node->next=NULL;
   }
   else{
       node *lst=head;
       while(lst->next!=NULL)lst=lst->next;
       lst->next=new_node;
       new_node->next=NULL;
   }
}
void display() {

    node *lst;
    if (head == NULL) {
        cout<<"Ops, Empty Linked list :(\n";
    } else {
        lst = head;
        while (lst!= NULL) {
            cout << lst->data << endl;
            lst = lst->next;
        }
    }
}
void deleteNode(int val)
{
    node* cur,*pre;
    cur=pre=head;
    if(cur->data==val)
    {
        head=cur->next;
        delete(cur);
        return;
    }
    while(cur->data!=val)
    {
        pre=cur;
        cur=cur->next;
    }
    pre->next=cur->next;
    delete(cur);
}
void insertNodeAtBeginning(int val)
{
    node* new_node=new node;
    new_node->data=val;
    new_node->next=head;
    head=new_node;
}
void deleteNodeAtBeginning()
{
    if(head==NULL)
    {
        cout<<"Ops, Empty Linked list :(\n";
        return;
    }
    node* first_node=head;
    head=first_node->next;
    delete(first_node);
}
void deleteNodeAtEnd()
{
    if(head==NULL)
    {
        cout<<"Ops, Empty Linked list :(\n";
        return;
    }
    if(head->next==NULL)
    {
        delete(head);
        head=NULL;
    }
    else
    {
        node *ptr=head;
        while (ptr->next->next!=NULL)
            ptr=ptr->next;
        delete(ptr->next);
        ptr->next=NULL;
    }
}
