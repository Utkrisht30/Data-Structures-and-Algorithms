#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
}*first=NULL; //create it here only so that it becomes globally accessible

void create(int A[],int n)
{
    struct node *t,*last; //t will help in creating a new node and last will help us in deciding when to end the list
    first=new node; //creating a node in heap
    first->data=A[0];
    first->next=NULL;
    last=first;//because right now the first node is the last node

    for(int i = 1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t; // the last node should point to the newly created node
        last=t; // the newly created node will be the last node
    }
}

void display(struct node *p)
{

    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

void Recursivedisplay(struct node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<endl;
        Recursivedisplay(p->next);
    }
}

void revRecursivedisplay(struct node *p)
{
    if(p!=NULL)
    {
        revRecursivedisplay(p->next);
        cout<<p->data<<endl;
    }
}

int icount(struct node *p)
{
    int  count = 0;

    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

int rcount(struct node *p)
{
    if(p!=NULL)
    {
        return rcount(p->next)+1;
    }
    else
        return 0;
}

int isum(struct node *p)
{
    int sum=0;
    while(p!=0)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int rsum(struct node *p)
{
    if(p!=NULL)
    {
        return rsum(p->next)+p->data;
    }
    else
        return 0;
}

int imax(struct node *p)
{
    int max=p->data;

    while(p!=NULL)
    {

        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
}

int rmax(struct node *p)
{
    if(p==0)
        return -1;
    else
    {
        int x;
        x=rmax(p->next);
        if(x>p->data)
            return x;
        else
            return p->data;
    }
}

node* isearch(struct node *p,int key)
{
    while(p!=0)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return nullptr;
}

node* rsearch(struct node *p,int key)
{
    if(p==NULL)
        return nullptr;
    else if(key==p->data)
        return p;
    else
        rsearch(p->next,key);
}


int main()
{
    int A[5]={1,2,3,15,5};
    create(A,5);
    display(first);
    //Recursivedisplay(first);
    //revRecursivedisplay(first);
    //cout<<icount(first)<<endl;
    //cout<<rcount(first)<<endl;
    //cout<<isum(first)<<endl;
    //cout<<rsum(first)<<endl;
    //cout<<imax(first)<<endl;
    //cout<<rmax(first)<<endl;
    //cout<<search(first,1);
    //cout<<rsearch(first,1)<<endl;
    //cout<<transpositionIsearch(first,15)<<endl;
}
