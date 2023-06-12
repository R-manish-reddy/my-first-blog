#include <iostream>

using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertBegin(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAfter(int key, int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        Node* current = head;
        while (current != NULL) {
            if (current->data == key) {
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                break;
            }
            current = current->next;
        }
    }

    void insertByPosition(int position, int value) {
        if (position <= 0) {
            insertBegin(value);
        } else if (position >= countNodes()) {
            insertEnd(value);
        } else {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = NULL;

            Node* current = head;
            for (int i = 0; i < position - 1; i++) {
                current = current->next;
            }

            newNode->prev = current;
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void deleteBegin() {
        if (head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
    }

    void deleteEnd() {
        if (tail == NULL) {
            return;
        }

        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
    }

    void deleteAfter(int key) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == key && current->next != NULL) {
                Node* temp = current->next;
                current->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = current;
                } else {
                    tail = current;
                }
                delete temp;
                break;
            }
            current = current->next;
        }
    }

    void deleteByPosition(int position) {
        if (position <= 0) {
            deleteBegin();
        } else if (position >= countNodes() - 1) {
            deleteEnd();
        } else {
            Node* current = head;
            for (int i = 0; i < position; i++) {
                current = current->next;
            }

            Node* temp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete temp;
        }
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    int countNodes() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    DoublyLinkedList list;

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
