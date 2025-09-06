
/*
author - mesyajs
*/
#include <iostream>
using namespace std;

struct QueueNode {
    int value;
    int priority;
    int key;
    QueueNode* next;
};

bool checkKey(QueueNode*& head, int key) {
    for (QueueNode* current = head; current != nullptr; current = current->next) {
        if (current->key == key) {
            cout << "This key is already taken" << endl;
            return true;
        }
    }
    return false;
}

QueueNode* initializeQueue(QueueNode*& head, QueueNode*& tail, int value, int priority, int key) {
    QueueNode* newNode = new QueueNode;
    newNode->value = value;
    newNode->priority = priority;
    newNode->key = key;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return head;
    }

    if (head->priority >= newNode->priority) {
        newNode->next = head;
        tail = head;
        head = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

QueueNode* pushElement(QueueNode*& head, QueueNode*& tail, int value, int priority, int key) {
    if (head == nullptr) {
        cout << "Queue is empty" << endl;
        return head;
    }

    QueueNode* newNode = new QueueNode;
    newNode->value = value;
    newNode->priority = priority;
    newNode->key = key;
    newNode->next = nullptr;

    if (head->priority >= newNode->priority) {
        newNode->next = head;
        tail = head;
        head = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

QueueNode* popElement(QueueNode*& head, QueueNode*& tail) {
    if (head == nullptr) {
        cout << "Queue is empty" << endl;
        return head;
    }
    QueueNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printQueue(QueueNode*& head) {
    for (QueueNode* current = head; current != nullptr; current = current->next) {
        cout << current->value << " | priority: " << current->priority << " | (" << current->key << ") ";
    }
    cout << endl;
}

void menu() {
    QueueNode* head = nullptr;
    QueueNode* tail = nullptr;
    int choice = -1;
    int value, key, priority;

    while (choice != 0) {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Initialize priority queue" << endl;
        cout << "2. Add element" << endl;
        cout << "3. Remove element" << endl;
        cout << "4. Print queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter priority: ";
            cin >> priority;
            cout << "Enter key: ";
            cin >> key;
            while (checkKey(head, key)) {
                cout << "Enter another key: ";
                cin >> key;
            }
            initializeQueue(head, tail, value, priority, key);
            cout << endl;
            printQueue(head);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter priority: ";
            cin >> priority;
            cout << "Enter key: ";
            cin >> key;
            while (checkKey(head, key)) {
                cout << "Enter another key: ";
                cin >> key;
            }
            pushElement(head, tail, value, priority, key);
            cout << endl;
            printQueue(head);
            break;

        case 3:
            cout << "Queue before deletion: ";
            printQueue(head);
            cout << "Queue after deletion: ";
            popElement(head, tail);
            printQueue(head);
            break;

        case 4:
            printQueue(head);
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}
