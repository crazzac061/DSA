#include <iostream>
#define MAXSIZE 100
using namespace std;

struct Node
{
    int data,next;
};

struct list
{
    Node node [MAXSIZE];
    int head;
    int freeindex;

    list()
    {
        head=-1;
        freeindex=0;
        for (int i=0; i<MAXSIZE;i++)
        {
            node[i].next=i+1;
        }
        node[MAXSIZE-1].next=-1;

    }

    int getfreeNode()
    {
        if (freeindex==-1)
        {
            cout<<"List is full";
            return -1;

        }
        int freenode=freeindex;
        freeindex=node[freenode].next;
        return freenode;
    }
    void releasenode(int index)
    {
        node[index].next=freeindex;
        freeindex=index;
    }
};

void insertAtBeginning(list &list, int data)
{
    int newindex=list.getfreeNode();
    if (newindex==-1)
    {
        return;
    }
    list.node[newindex].data=data;
    list.node[newindex].next=list.head;
    list.head=newindex;

}
void insertAtEnd(list &list, int data)
{
    int newindex=list.getfreeNode();
    if (newindex==-1)
    {
        return;
    }
    list.node[newindex].data=data;
    list.node[newindex].next=-1;
    int temp=list.head;

    if (list.head==-1){
        list.head=newindex;
        return;
    }
    while(list.node[temp].next!=-1)
    {
        temp=list.node[temp].next;
    }
    list.node[temp].next=newindex;
}

void insertAtPosition(list &list, int data, int pos)
{
    int newindex= list.getfreeNode();
    if (newindex==-1)
    {
        return;
    }
    int count=0;
    if (pos==0)
    {
        insertAtBeginning(list,data);
        return;
    }
    int temp=list.head;
    while(count<pos-1 && temp!=-1 && list.node[temp].next!=-1)
    {
        temp=list.node[temp].next;
        count++;
    }
    if (temp==-1)
    {
        cout<<"invalid position!!";
        list.releasenode(newindex);
        return;
    }
    list.node[newindex].data=data;
    list.node[newindex].next=list.node[temp].next;
    list.node[temp].next=newindex;
}
void deletefromBeginning(list &list)
{
    int temp= list.head;
    if (temp==-1)
    {
        cout<<"cannot delete from empty list"<<endl;
        return;
    }
    list.head=list.node[list.head].next;
    list.releasenode(temp);
}
void deletefromEnd(list &list)
{
    int temp= list.head;
    if (temp==-1)
    {
        cout<<"cannot delete from empty node"<<endl;
        return;
    }
    int prev;
    while(list.node[temp].next!=-1)
    {
        prev=temp;
        temp=list.node[temp].next;
    }
    list.node[prev].next=-1;
    list.releasenode(temp);


}
void deletePosition(list &list, int pos)
{
    int temp= list.head;
    if (temp==-1){
        cout<<"cannot delete from empty list"<<endl;
    }
    int count=0;
    if (pos==0)
    {
        deletefromBeginning(list);
        return;
    }
    int prev;
    while(count<pos&&temp!=-1&&list.node[temp].next!=-1)
    {
        prev=temp;
        temp=list.node[temp].next;
        count++;
    }
    if (temp==-1)
    {
        cout<<"cannot find the position to delete"<<endl;
        return;
    }
    list.node[prev].next=list.node[temp].next;
    list.releasenode(temp);



}
void print(list &list)
{
    int temp=list.head;
    while(temp!=-1)
    {
        cout<<list.node[temp].data<<" ";
        temp=list.node[temp].next;
    }
    cout<<endl;
}

int main()
{
    struct list list;
    insertAtBeginning(list,2);
    insertAtBeginning(list,1);
    insertAtEnd(list,4);
    insertAtPosition(list, 3, 2);
    insertAtEnd(list,5);
    print(list);
    deletefromBeginning(list);
    deletefromEnd(list);
    deletePosition(list,1);
    print(list);
    return 0;


}