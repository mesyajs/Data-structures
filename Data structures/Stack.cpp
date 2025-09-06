#include <iostream>
using namespace std;

// ��������� ����
struct Node {
    int data;
    Node* next;
};

// ��������� �����
struct Stack {
    Node* top = nullptr;
};

// ���������� ��������
void push(Stack* stack, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// �������� ��������
int pop(Stack* stack) {
    if (!stack->top) {
        cout << "���� ����!" << endl;
        return -1;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    delete temp;
    return value;
}

// �������� �������� ��������
int peek(Stack* stack) {
    if (!stack->top) {
        cout << "���� ����!" << endl;
        return -1;
    }
    return stack->top->data;
}

// ����� ���� ���������
void display(Stack* stack) {
    if (!stack->top) {
        cout << "���� ����!" << endl;
        return;
    }
    Node* current = stack->top;
    cout << "����: ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// ����� ���� ���������
int sumStack(Stack* stack) {
    int total = 0;
    Node* current = stack->top;
    while (current) {
        total += current->data;
        current = current->next;
    }
    return total;
}

// ����
void menu(Stack* stack) {
    int choice, value;
    do {
        cout << "\n���� �����:\n";
        cout << "1. �������� ������� (push)\n";
        cout << "2. ������� ������� (pop)\n";
        cout << "3. �������� �������� �������� (peek)\n";
        cout << "4. ������� ����\n";
        cout << "5. ����� ���������\n";
        cout << "0. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� �������� ��� ����������: ";
            cin >> value;
            push(stack, value);
            break;
        case 2:
            cout << "�������� �������: " << pop(stack) << endl;
            break;
        case 3:
            cout << "������� �������: " << peek(stack) << endl;
            break;
        case 4:
            display(stack);
            break;
        case 5:
            cout << "����� ���������: " << sumStack(stack) << endl;
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� �����!" << endl;
        }
    } while (choice != 0);
}

int main() {
    Stack stack;
    menu(&stack);
    return 0;
}
