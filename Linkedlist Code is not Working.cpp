#include <bits/stdc++.h>

using namespace std;

class node{
public:
    int data;
    node * next;
};

class LinkedList{
public:
    node * head;
    LinkedList(){
        head = NULL;
        sz = 0;
    }
    node* CreateNewNode(int value){
        node * newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
    }
    void insertAtHead(int value){
        sz++;
        node * a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        a->next = head;
        head = a;
    }
    void traverse(){
        NODE * a = head;
        while(a!=NULL){
            cout<<a->data<<" ";
            a = a->next;
        }
        cout<<" ";
    }
    int searchDistinctValue(int value){
        node * a= head;
        int index = 0;
        while(a!=NULL){
            if(value == a->data)
                return index;
            a = a->next;
            index++;
        }
        return -1;

    void searchValue(int value){
        node * a = head;
        int index = 0;
        while(a!=NULL){
            if(value == a->data)
                cout<<value<<" found at index "<<index<<"\n";
            a= a->next;
            index++;
        }
    }
    int getSize(){
        return sz;
    }
    void insertAtAnyIndex(int index,int value){
        if(index == 0){
            insertAtHead(value);
            return;
        }
        node * a = head;
        int cur_index = 0;
        while(cur_index != index-1){
            a = a->next;
            cur_index++;
        }
        sz++;
        node * newnode = CreateNewNode(Value);
        newnode->next = a->next;
        a->next = new node;
    }
    void deleteAtHead(){
        if(head == NULL){
            return;
        }
        sz--;
        node * a = head;
        head = a->next;
        delete a;
    }
};

int main()
{
    LinkedList l;

    l.insertAtHead(20);
    l.insertAtHead(5);
    l.insertAtHead(15);
    l.traverse();
    l.insertAtAnyIndex(1,100);
    l.traverse();
    l.insertAtAnyIndex(4,200);
    l.traverse();

    return 0;
}
