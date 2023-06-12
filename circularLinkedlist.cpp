#include <iostream>

using namespace std;

class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == NULL) {
            newNode->next = newNode;
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
        head = newNode;
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
    }

    void insertAfter(int key, int value) {
        if (head == NULL) {
            return;
        }

        Node* current = head;
        do {
            if (current->data == key) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = current->next;
                current->next = newNode;
                if (current == head && current->next == head) {
                    head = newNode;
                }
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void insertByPosition(int position, int value) {
        if (position <= 0) {
            insertBegin(value);
        } else {
            Node* newNode = new Node();
            newNode->data = value;

            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
                if (current == head) {
                    return;
                }
            }

            newNode->next = current->next;
            current->next = newNode;
            if (current == head && newNode->next == head) {
                head = newNode;
            }
        }
    }

    void deleteBegin() {
        if (head == NULL) {
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    void deleteEnd() {
        if (head == NULL) {
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }

        prev->next = head;
        delete current;
    }

    void deleteAfter(int key) {
        if (head == NULL) {
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        while (current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }

        if (current == NULL || current->next == head) {
            return; // Key not found or there is only one node
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    void deleteByPosition(int position) {
        if (position <= 0) {
            deleteBegin();
        } else {
            Node* current = head;
            Node* prev = NULL;
            for (int i = 0; i < position; i++) {
                if (current == head) {
                    return; // Invalid position
                }
                prev = current;
                current = current->next;
            }

            prev->next = current->next;
            delete current;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    int choice, value, key, position;
    while (true) {
        cout << "1. Insert at beginning\n"
             << "2. Insert at end\n"
             << "3. Insert after a specific element\n"
             << "4. Insert at a specific position\n"
             << "5. Delete from beginning\n"
             << "6. Delete from end\n"
             << "7. Delete the element after a specific element\n"
             << "8. Delete from a specific position\n"
             << "9. Display the list\n"
             << "10. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertBegin(value);
                cout << "Element inserted at the beginning.\n";
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertEnd(value);
                cout << "Element inserted at the end.\n";
                break;
            case 3:
                cout << "Enter the key element: ";
                cin >> key;
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertAfter(key, value);
                cout << "Element inserted after " << key << ".\n";
                break;
            case 4:
                cout << "Enter the position: ";
                cin >> position;
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertByPosition(position, value);
                cout << "Element inserted at position " << position << ".\n";
                break;
            case 5:
                list.deleteBegin();
                cout << "Element deleted from the beginning.\n";
                break;
            case 6:
                list.deleteEnd();
                cout << "Element deleted from the end.\n";
                break;
            case 7:
                cout << "Enter the key element: ";
                cin >> key;
                list.deleteAfter(key);
                cout << "Element deleted after " << key << ".\n";
                break;
            case 8:
                cout << "Enter the position: ";
                cin >> position;
                list.deleteByPosition(position);
                cout << "Element deleted from position " << position << ".\n";
                break;
            case 9:
                cout << "Current list: ";
                list.display();
                break;
            case 10:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
