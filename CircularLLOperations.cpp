#include <iostream>
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

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = newNode;
            head->next = head; // circular link
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Inserted: " << val << endl;
    }

    // Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // only one node
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        cout << "Deleted: " << head->data << endl;
        head = head->next;
        last->next = head;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == head) { // only one node
            cout << "Deleted: " << head->data << endl;
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        cout << "Deleted: " << temp->next->data << endl;
        delete temp->next;
        temp->next = head;
    }

    // Delete a given element
    void deleteElement(int key) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        // If head node itself holds the key
        if (head->data == key) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;
        do {
            prev = temp;
            temp = temp->next;
            if (temp->data == key) {
                prev->next = temp->next;
                cout << "Deleted: " << temp->data << endl;
                delete temp;
                return;
            }
        } while (temp != head);

        cout << "Element " << key << " not found!" << endl;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, val;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete from Beginning\n";
        cout << "3. Delete from End\n";
        cout << "4. Delete a given element\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> val;
            cll.insert(val);
            break;
        case 2:
            cll.deleteFromBeginning();
            break;
        case 3:
            cll.deleteFromEnd();
            break;
        case 4:
            cout << "Enter element to delete: ";
            cin >> val;
            cll.deleteElement(val);
            break;
        case 5:
            cll.display();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
