#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
struct Node {
    int info;
    int next;
};
struct List {
    Node nodes[MAX_SIZE];
    int head;
    int freeIndex;
    List() {
        head = -1;       
        freeIndex = 0;   
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            nodes[i].next = i + 1; 
        }
        nodes[MAX_SIZE - 1].next = -1; 
    }

  
    int getFreeNode() {
        if (freeIndex == -1) {
            cout << "List is full.\n";
            return -1;
        }
        int freeNode = freeIndex;
        freeIndex = nodes[freeIndex].next; 
        return freeNode;
    }

    void releaseNode(int index) {
        nodes[index].next = freeIndex;
        freeIndex = index;
    }
};
void insertAtBeginning(List& list, int data) {
    int newIndex = list.getFreeNode();
    if (newIndex == -1) return;

    list.nodes[newIndex].info = data;
    list.nodes[newIndex].next = list.head;
    list.head = newIndex;
}
void insertAtEnd(List& list, int data) {
    int newIndex = list.getFreeNode();
    if (newIndex == -1) return;

    list.nodes[newIndex].info = data;
    list.nodes[newIndex].next = -1;

    if (list.head == -1) {
        list.head = newIndex;
        return;
    }

    int temp = list.head;
    while (list.nodes[temp].next != -1) {
        temp = list.nodes[temp].next;
    }
    list.nodes[temp].next = newIndex;
}
void insertAfterElement(List& list, int element, int data) {
    int temp = list.head;
    while (temp != -1 && list.nodes[temp].info != element) {
        temp = list.nodes[temp].next;
    }
    if (temp == -1) {
        cout << "Element " << element << " not found.\n";
        return;
    }

    int newIndex = list.getFreeNode();
    if (newIndex == -1) return;

    list.nodes[newIndex].info = data;
    list.nodes[newIndex].next = list.nodes[temp].next;
    list.nodes[temp].next = newIndex;
}
void deleteFromBeginning(List& list) {
    if (list.head == -1) {
        cout << "List is empty.\n";
        return;
    }

    int temp = list.head;
    list.head = list.nodes[temp].next;
    list.releaseNode(temp);
}
int deleteFromEnd(List& list) {
    if (list.head == -1) {
        cout << "List is empty.\n";
        return -1;
    }

    if (list.nodes[list.head].next == -1) {
        int del_item = list.nodes[list.head].info; 
        list.releaseNode(list.head);
        list.head = -1;
        return del_item;
    }

    int temp = list.head;
    while (list.nodes[list.nodes[temp].next].next != -1) {
        temp = list.nodes[temp].next;
    }

    int lastNode = list.nodes[temp].next;
    int del_item = list.nodes[lastNode].info; 
    list.nodes[temp].next = -1;
    list.releaseNode(lastNode);
    return del_item;
}
void deleteAfterElement(List& list, int element) {
    int temp = list.head;
    while (temp != -1 && list.nodes[temp].info != element) {
        temp = list.nodes[temp].next;
    }
    if (temp == -1 || list.nodes[temp].next == -1) {
        cout << "Element " << element << " not found or no element exists after it.\n";
        return;
    }

    int nodeToDelete = list.nodes[temp].next;
    list.nodes[temp].next = list.nodes[nodeToDelete].next;
    list.releaseNode(nodeToDelete);
}
void displayList(List& list) {
    int temp = list.head;
    while (temp != -1) {
        cout << list.nodes[temp].info << " ";
        temp = list.nodes[temp].next;
    }
    cout << endl;
}
class Queue
{
    List* list;
    public:
    Queue(){
        list = new List();
    }
    void Enqueue(int data)
    {
        insertAtEnd(*list,data);
    }
    int Dequeue(){
        return deleteFromEnd(*list);

    }
    void display()
    {
        displayList(*list);
    }

};



int main() {

    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.display();
    q.Enqueue(10);
    q.Enqueue(11);
    q.Enqueue(12);
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();
    q.display();
    q.Dequeue();

    return 0;
}
