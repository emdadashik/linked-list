#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int sz ;

public:
    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    
    Node* createNewNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode;
    }

    void insertAtHead(int data){
        Node* newNode = createNewNode(data);
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    }
    void insertAtTail(int data){
        Node* newNode = createNewNode(data);
        newNode->prev = tail;
        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL) {
            head = newNode;
        }
    }
    void insertAfter(Node* prevNode, int data) {
        if (prevNode == NULL) {
            cout << "Previous node cannot be NULL" << endl;
            return;
        }
    
        Node* newNode = createNewNode(data);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        if (prevNode->next != NULL) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if (prevNode == tail) {
            tail = newNode;
        }
    }

    void deleteNode(int data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == data) {
                if (current == head) {
                    head = current->next;
                }
                if (current == tail) {
                    tail = current->prev;
                }
                if (current->prev != NULL) {
                    current->prev->next = current->next;
                }
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Node with data " << data << " not found" << endl;
    }

    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    Node* search(int data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
};

int main(){
    DoublyLinkedList l;
    
    l.insertAtHead(10);
    l.insertAtHead(15);
    l.insertAtHead(11);
    l.insertAtHead(12);
    l.printList();

    l.deleteNode(11);
    
    l.printList();
    
    return 0;
}
