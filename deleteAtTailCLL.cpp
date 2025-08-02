#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
    Node* head;
    Node* tail;

public:
    CircularList() {
        head = tail = NULL;
    }

    void inserAtHead(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }

    void print() {
        if (head == NULL) return;

        cout << head->data << "->";
        Node* temp = head->next;

        while (temp != head) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
            tail->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtHead() {
        if (head == NULL) return;
        else if (head == tail) {
            delete head;
            head = tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;

            temp->next = NULL;
            delete temp;
        }
    }

    void deleteAtTail() {
        if (head == NULL) return;
        else if (head == tail) {
            delete tail;
            head = tail = NULL;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;
        }
    }
};

int main() {
    CircularList cll;
    cll.inserAtHead(10);
    cll.inserAtHead(20);
    cll.inserAtHead(30);
    cll.insertAtTail(56);
    cll.deleteAtHead();
    cll.deleteAtTail();
    cll.print();
    return 0;
}
