#include <iostream>
using namespace std;

// Структура узла
struct Node {
    int data;
    Node* next;
};

// Структура стека
struct Stack {
    Node* top = nullptr;
};

// Добавление элемента
void push(Stack* stack, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Удаление элемента
int pop(Stack* stack) {
    if (!stack->top) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    delete temp;
    return value;
}

// Просмотр верхнего элемента
int peek(Stack* stack) {
    if (!stack->top) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    return stack->top->data;
}

// Вывод всех элементов
void display(Stack* stack) {
    if (!stack->top) {
        cout << "Стек пуст!" << endl;
        return;
    }
    Node* current = stack->top;
    cout << "Стек: ";
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Сумма всех элементов
int sumStack(Stack* stack) {
    int total = 0;
    Node* current = stack->top;
    while (current) {
        total += current->data;
        current = current->next;
    }
    return total;
}

// Меню
void menu(Stack* stack) {
    int choice, value;
    do {
        cout << "\nМеню стека:\n";
        cout << "1. Добавить элемент (push)\n";
        cout << "2. Удалить элемент (pop)\n";
        cout << "3. Просмотр верхнего элемента (peek)\n";
        cout << "4. Вывести стек\n";
        cout << "5. Сумма элементов\n";
        cout << "0. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите значение для добавления: ";
            cin >> value;
            push(stack, value);
            break;
        case 2:
            cout << "Удалённый элемент: " << pop(stack) << endl;
            break;
        case 3:
            cout << "Верхний элемент: " << peek(stack) << endl;
            break;
        case 4:
            display(stack);
            break;
        case 5:
            cout << "Сумма элементов: " << sumStack(stack) << endl;
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор!" << endl;
        }
    } while (choice != 0);
}

int main() {
    Stack stack;
    menu(&stack);
    return 0;
}
