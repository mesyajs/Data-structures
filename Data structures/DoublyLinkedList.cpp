#include <iostream>
using namespace std;

struct List {
	int value;
	int key;
	List* next;
	List* prev;
};
List* pev = nullptr;
void bubbleSort(List*& head) {
	if (head->next == nullptr || head->next->next == nullptr) {
		return;
	}
	bool swapped;
	do {
		swapped = false;
		List* temp = head->next;

		while (temp != nullptr && temp->next != nullptr) {
			if (temp->value > temp->next->value) {
				List* first = temp;
				List* second = temp->next;
				first->next = second->next;
				if (second->next != nullptr) {
					second->next->prev = first;
				}
				second->prev = first->prev;
				if (first->prev != nullptr) {
					first->prev->next = second;
				}
				first->prev = second;
				second->next = first;
				if (second->prev == nullptr) {
					head->next = second;
				}

				swapped = true;
			}
			temp = temp->next;
		}
	} while (swapped);
}
bool checkKey(List*& head, int key) {
	List* current = head->next;
	while (current != nullptr) {
		if (current->key == key) {
			return true;
		}
		current = current->next;
	}
	return false;
}
List* findBySorted(List* head, int a) {
	List* current = head;
	while (current != nullptr) {
		if (current->value == a) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
List* initializ(List*& head, int a, int key) {
	if (head->next == nullptr) {
		List* newNode = new List;
		newNode->value = a;
		newNode->key = key;
		newNode->next = nullptr;
		newNode->prev = head;
		head->next = newNode;
		return head;
	}
	else {
		cout << "Список уже создан" << endl;
		return head;
	}
}
List* find(List*& head, int a) {
	List* current = head->next;
	List* temp = head->next;
	int count = 0;
	while (temp != nullptr) {
		if (temp->value == a) {
			cout << ++count << ".Найдено: " << temp->value << endl;
		}
		temp = temp->next;
	}
	if (count >= 2) {
		int number = 0;
		cout << "Введите номер элемента: ";
		cin >> number;
		temp = head->next;
		int i = 0;
		while (temp != nullptr) {
			if (temp->value == a) {
				i++;
				if (i == number) {
					return temp;
				}
			}
			temp = temp->next;
		}
	}
	while (current != nullptr) {
		if (current->value == a) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
List* find5(List*& head, int a) {
	List* current = head->next;
	List* temp = head->next;
	int count = 0;
	while (temp != nullptr) {
		if (temp->value == a) {
			cout << ++count << ".Найдено: " << temp->value << endl;
		}
		temp = temp->next;
	}
	if (count >= 2) {
		int number = 0;
		cout << "Введите номер элемента: ";
		cin >> number;
		temp = head->next;
		int i = 0;
		while (temp != nullptr) {
			if (temp->value == a) {
				i++;
				if (i == number) {
					return temp;
				}
			}
			temp = temp->next;
		}
	}
	while (current != nullptr) {
		if (current->value == a && current->next != nullptr) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
List* find2(List*& head, int position) {
	if (position == 0 || position == 1) {
		return nullptr;
	}
	List* current = head->next;
	int index = 1;
	while (current != nullptr) {
		if (index == position && current != nullptr) {
			return current;
		}
		index++;
		current = current->next;
	}
	return nullptr;
}
List* find3(List*& head, int position) {
	List* current = head->next;
	if (position <= -1) {
		return nullptr;
	}
	else if (position == 0) {
		return head;
	}
	int index = 1;
	while (current != nullptr) {
		if (index == position && current->next != nullptr) {
			return current;
		}
		index++;
		current = current->next;
	}
	return nullptr;
}
List* findBeforeValue(List*& head, int a) {
	List* current = head->next;
	if (current->value == a) {
		return current;
	}
	while (current != nullptr) {
		if (current != nullptr && current->value == a) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
List* findAfterValue(List*& head, int a) {
	List* current = head->next;
	while (current != nullptr) {
		if (current->value == a) {
			return current;
		}
		current = current->next;
	}
	return nullptr;
}
List* findBeforePosition(List*& head, int position) {
	if (position <= 0) {
		cout << "Недопустимая позиция" << endl;
		return nullptr;
	}
	List* current = head->next;
	if (position == 1) {
		return current;
	}
	int i = 1;
	while (current != nullptr) {
		if (i == position - 1 && current != nullptr) {
			return current;
		}
		i++;
		current = current->next;
	}
	return nullptr;
}
List* findAfterPosition(List*& head, int position) {
	if (position <= 0) {
		cout << "Недопустимая позиция" << endl;
		return nullptr;
	}
	else if (position == 2) {
		return head;
	}
	int i = 1;
	List* current = head->next;
	while (current != nullptr) {
		if (i == position - 2 && current != nullptr) {
			return current;
		}
		i++;
		current = current->next;
		if (current == nullptr) {
			return nullptr;
		}
	}
	return nullptr;
}
List* push(List*& head, int a, int k) {
	List* current = head->next;
	while (current->next != nullptr) {
		current = current->next;
	}
	List* newNode = new List;
	newNode->value = a;
	newNode->key = k;
	newNode->next = nullptr;
	newNode->prev = current;
	current->next = newNode;
	return head;
}
List* pushBeforeValue(List*& head, int a, int val, int k) {
	List* current = findBeforeValue(head, a);
	List* newNode = new List;
	newNode->value = val;
	newNode->key = k;
	newNode->next = nullptr;

	if (current == nullptr) {
		cout << "Элемент был не найден" << endl;
		return head;
	}
	if (current == head->next) {
		newNode->next = current;
		newNode->prev = head;
		(current->prev)->next = newNode;
		current->prev = newNode;
		return head;
	}
	newNode->next = current;
	(current->prev)->next = newNode;
	newNode->prev = current->prev;
	current->prev = newNode;
	return head;
}
List* pushAfterValue(List*& head, int a, int val, int k) {
	List* current = findAfterValue(head, a);
	List* newNode = new List;
	newNode->value = val;
	newNode->key = k;
	newNode->next = nullptr;
	if (current == nullptr) {
		cout << "Элемент был не найден" << endl;
		return head;
	}
	newNode->next = current->next;
	newNode->prev = current;
	(current->next)->prev = newNode;
	current->next = newNode;
	return head;
}
List* pushBeforePosition(List*& head, int pos, int val, int k) {
	List* current = findBeforePosition(head, pos);
	List* newNode = new List;
	newNode->value = val;
	newNode->key = k;
	newNode->prev = nullptr;
	newNode->next = nullptr;
	if (current == nullptr) {
		cout << "Недопустимое место для вставки" << endl;
		return head;
	}
	if (current == head->next) {
		newNode->next = current;
		newNode->prev = head;
		head->next = newNode;
		current->prev = newNode;
		return head;
	}
	newNode->next = current;
	(current->prev)->next = newNode;
	newNode->prev = current->prev;
	current->prev = newNode;
	return head;
}
List* pushAfterPosition(List*& head, int pos, int val, int k) {
	List* current = findAfterPosition(head, pos);
	List* newNode = new List;
	newNode->value = val;
	newNode->key = k;
	newNode->next = nullptr;
	if (current == nullptr) {
		cout << "Недопустимое место для вставки" << endl;
		return head;
	}
	if (current == head) {
		newNode->next = head->next;
		newNode->prev = (head->next)->prev;
		(head->next)->prev = newNode;
		head->next = newNode;
		return head;
	}
	else if (current->next == nullptr) {
		newNode->next = nullptr;
		newNode->prev = current;
		current->next = newNode;
		return head;
	}
	newNode->next = current->next;
	newNode->prev = (current->next)->prev;
	(current->next)->prev = newNode;
	current->next = newNode;
	return head;

}
void searchBeforeValue(List*& head, int a) {
	int i = 1;
	List* current = head->next;
	bool is = false;
	if (current->value == a) {
		cout << "Перед указанным значением была найдена голова списка" << endl;
		cout << "Адрес: " << &head->value << "  Значение: " << head->value << endl;
		bool prov = false;
		List* temp = head->next->next;
		while (temp != nullptr) {
			if (temp->value == a) {
				prov = true;
			}
			temp = temp->next;
		}
		if (!prov) {
			return;
		}
	}
	while (current != nullptr) {
		if (current->next != nullptr && current->next->value == a) {
			cout << i++ << ".По значению был найден элемент: " << current->value << "  Адрес: " << &current->value << endl;
			is = true;
		}
		current = current->next;
	}
	if (!is) {
		cout << "Элемент с указанным значением не найден" << endl;
		return;
	}
	return;
}
void searchAfterValue(List*& head, int a) {
	int i = 1;
	List* current = head->next;
	bool is = false;
	while (current != nullptr) {
		if (current->next != nullptr && current->value == a) {
			cout << i++ << ".По значению был найден элемент: " << current->next->value << "  Адрес: " << &current->next->value << endl;
			is = true;
		}
		current = current->next;
	}
	if (!is) {
		cout << "Элемент с указанным значением не найден" << endl;
		return;
	}
	return;
}
void searchBeforePosition(List*& head, int position) {
	List* current = head->next;
	bool is = false;
	if (position == 1) {
		cout << "Перед указанным значением была найдена голова списка" << endl;
		cout << "Адрес: " << &head->value << "  Значение: " << head->value << endl;
		return;
	}
	int index = 1;
	while (current != nullptr) {
		if (index == position - 1 && current != nullptr) {
			cout << "Перед позицией был найден элемент: " << current->value << "  Адрес: " << &current->value << endl;
			is = true;
			break;
		}
		index++;
		current = current->next;
	}
	if (!is) {
		cout << "Элемент с указанным значением не найден" << endl;
		return;
	}
	return;
}
void searchAfterPosition(List*& head, int position) {
	List* current = head->next;
	bool is = false;
	if (position == 0) {
		cout << "Адрес: " << &head->next->value << "  Значение: " << head->next->value << endl;
		return;
	}
	int index = 1;
	while (current != nullptr) {
		if (index == position && current->next != nullptr) {
			cout << "Перед позицией был найден элемент: " << current->next->value << "  Адрес: " << &current->next->value << endl;
			is = true;
			break;
		}
		index++;
		current = current->next;
	}
	if (!is) {
		cout << "Элемент с указанным значением не найден" << endl;
		return;
	}
	return;
}
List* delValue(List*& head, int a) {
	List* current = find(head, a);
	if (current == nullptr) {
		cout << "Недопустимое место для удаления" << endl;
		return head;
	}
	else if (current == head->next) {
		List* temp = current;
		head->next = current->next;
		(current->next)->prev = head;
		delete temp;
		return head;
	}
	else if (current != nullptr) {
		List* temp = current;
		if (current->next == nullptr) {
			(temp->prev)->next = nullptr;
			delete temp;
			return head;
		}
		(temp->prev)->next = current->next;
		(current->next)->prev = temp->prev;
		delete temp;
		return head;
	}
}
List* delbeforeValue(List*& head, int a) {
	List* current = find(head, a);
	if (current == head->next) {
		cout << "Недопустимое место для удаления" << endl;
		return head;
	}
	else if (current != nullptr) {
		List* temp = current->prev;
		(temp->prev)->next = current;
		current->prev = temp->prev;
		delete temp;
		return head;
	}
}
List* delafterValue(List*& head, int a) {
	List* current = find5(head, a);
	if (current == nullptr) {
		cout << "Недопустимое место для удаления" << endl;
		return head;
	}
	else {
		if (current->next->next == nullptr) {
			List* temp = current->next;
			current->next = temp->next;
			delete temp;
			return head;
		}
		else {
			List* temp = current->next;
			current->next = temp->next;
			(temp->next)->prev = current;
			delete temp;
			return head;
		}
	}
}
List* delbeforePosition(List*& head, int a) {
	List* current = find2(head, a);
	if (current == nullptr) {
		cout << "Недопустимая позиция для удаления" << endl;
		return head;
	}
	else if (current == head->next->next) {
		List* temp = current->prev;
		head->next = current;
		current->prev = head;
		delete temp;
		return head;
	}
	else {
		List* temp = current->prev;
		(temp->prev)->next = current;
		current->prev = temp->prev;
		delete temp;
		return head;
	}
}
List* delafterPosition(List*& head, int a) {
	List* current = find3(head, a);
	if (current == nullptr) {
		cout << "Недопустимая позиция для удаления" << endl;
		return head;
	}
	if (current == head) {
		List* temp = current->next;
		head->next = temp->next;
		(temp->next)->prev = head;
		delete temp;
		return head;
	}
	else if (current->next != nullptr) {
		List* temp = current->next;
		current->next = temp->next;
		if (temp->next != nullptr) {
			(temp->next)->prev = current;
		}
		delete temp;
		return head;
	}
}
List* swap(List*& head, int a) {
	List* current = find(head, a);
	if (!current || !current->next) {
		return head;
	}
	List* temp = current->next;
	if (current->prev) {
		current->prev->next = temp;
	}
	temp->prev = current->prev;
	if (head->next == current) {
		head->next = temp;
	}
	if (temp->next) {
		temp->next->prev = current;
	}
	current->next = temp->next;
	current->prev = temp;
	temp->next = current;

	return head;
}
void round(List*& head) {
	List* current = head->next;
	while (current != nullptr) {
		if (current->next == nullptr) {
			current->next = head->next;
			(head->next)->prev = current;
			break;
		}
		current = current->next;
	}
	cout << "true" << endl;
}
void noRound(List*& head) {
	List* current = head->next;
	while (current->next != head->next) {
		current = current->next;
	}
	current->next = nullptr;
	head->next->prev = head;
	cout << "true" << endl;
}
void request(List*& head) {
	int cyrcle;
	cout << "Введите количество кругов: ";
	cin >> cyrcle;
	int i = 0;
	List* current = head->next;
	while (current->next != head->next) {
		current = current->next;
	}
	cout << "current->next: " << &current->next->value << endl;
	cout << "head->next: " << &head->next->value << endl;
	cout << "|     Адрес      |" << "   Значение |" << "   Ключ |" << endl;
	for (current = head->next; current != nullptr; current = current->next) {
		if (current == head->next) {
			i++;
		}
		else if (i == cyrcle) {
			cout << "Кругов было сделано: " << i << endl;
			break;
		}
		cout << "|" << &current->value << "|    " << current->value << "      |    " << current->key << "    |" << endl;
	}
	current = head->next;
	while (current->next != head->next) {
		current = current->next;
	}
	cout << "head->prev: " << &head->next->prev->value << endl;
	cout << "current: " << &current->value << endl;
	cout << "|     Адрес      |" << "   Значение |" << "   Ключ |" << endl;
	i = 0;
	for (List* pv = current; pv != nullptr; pv = pv->prev) {
		if (pv == head->next) {
			i++;
		}
		else if (i == cyrcle) {
			cout << "Кругов было сделано: " << i << endl;
			break;
		}
		cout << "|" << &pv->value << "|    " << pv->value << "      |    " << pv->key << "    |" << endl;
	}
}
void runningLeftRight(List*& head) {
	List* left = head->next;
	int index = 1;
	cout << "Просмотр слева направо: " << endl;
	while (left != nullptr) {
		cout << "Адрес: " << &left->value << " Значение: " << left->value << " Ключ: " << left->key << " Позиция: " << index++ << endl;
		left = left->next;
	}
	index = index - 1;
	List* current = head->next;
	while (current->next != nullptr) {
		current = current->next;
	}
	cout << "Просмотр справа налево: " << endl;
	List* right = current;
	while (right != nullptr) {
		cout << "Адрес: " << &right->value << " Значение: " << right->value << " Ключ: " << right->key << " Позиция: " << index-- << endl;
		right = right->prev;
	}
}
void output(List*& head) {
	List* current = head->next;
	int index = 1;
	while (current != nullptr) {
		cout << "Адрес: " << &current->value << " Значение: " << current->value << " Ключ: " << current->key << " Позиция: " << index++ << endl;
		current = current->next;
	}
	cout << endl;
}
void inition1(List*& head, List*& head2) {
	int choice = -1, value, key, a;
	while (choice != 0) {
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "|     1.Инициализировать список     |" << "  |  9.Поиск элемента перед позицией |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "|     2.Добавить элемент в список   |" << "  |  10.Поиск элемента после позиции  |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 3.Добавить элемент перед значением|" << "  |  11.Удаление элемента по значению |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 4.Добавить элемент после значения |" << "  |12.Удаление элемента перед значением|" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 5.Добавить элемент перед позицией |" << "  |13.Удаление элемента после значения |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 6.Добавить элемент после позиции  |" << "  |14.Удаление элемента перед позицией |" << endl;
		cout << "-------------------------------------" << "  --------------------------------------" << endl;
		cout << "| 7.Поиск перед указанным элементом |" << "  |15.Удаление элемента после позиции  |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "| 8.Поиск после указанного элемента |" << " |16.Просмотр слева направо и справа налево|" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|  19.Перестановка 2-х соседних     |" << " |    17.Кольцевой двусвязнный список      |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|         20.сортировка             |" << " |         18.Запрос для кругов           |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|   22.Меню для конкатенации        |" << " |          21.Отцепить список             |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			initializ(head, value, key);
			output(head);
			break;
		case 2:
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			push(head, value, key);
			output(head);
			break;
		case 3:
			cout << "Введите элемент перед которым добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushBeforeValue(head, a, value, key);
			output(head);
			break;
		case 4:
			cout << "Введите элемент после которого добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushAfterValue(head, a, value, key);
			output(head);
			break;
		case 5:
			cout << "Введите позицию перед которым добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushBeforePosition(head, a, value, key);
			output(head);
			break;
		case 6:
			cout << "Введите позицию после которого добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushAfterPosition(head, a + 2, value, key);
			output(head);
			break;
		case 7:
			cout << "Введите элемент: ";
			cin >> a;
			searchBeforeValue(head, a);
			break;
		case 8:
			cout << "Введите элемент: ";
			cin >> a;
			searchAfterValue(head, a);
			break;
		case 9:
			cout << "Введите позицию: ";
			cin >> a;
			searchBeforePosition(head, a);
			break;
		case 10:
			cout << "Введите позицию: ";
			cin >> a;
			searchAfterPosition(head, a);
			break;
		case 11:
			cout << "Введите элемент: ";
			cin >> a;
			delValue(head, a);
			output(head);
			break;
		case 12:
			cout << "Введите элемент: ";
			cin >> a;
			delbeforeValue(head, a);
			output(head);
			break;
		case 13:
			cout << "Введите элемент: ";
			cin >> a;
			delafterValue(head, a);
			output(head);
			break;
		case 14:
			cout << "Введите элемент: ";
			cin >> a;
			delbeforePosition(head, a);
			output(head);
			break;
		case 15:
			cout << "Введите элемент: ";
			cin >> a;
			delafterPosition(head, a);
			output(head);
			break;
		case 16:
			runningLeftRight(head);
			break;
		case 17:
			round(head);
			break;
		case 18:
			request(head);
			break;
		case 19:
			cout << "Введите элемент для swap: ";
			cin >> a;
			swap(head, a);
			output(head);
			break;
		case 20:
			bubbleSort(head);
			output(head);
			break;
		case 21:
			noRound(head);
			break;
		}
	}
}
void inition2(List*& head, List*& head2) {
	int choice = -1, value, key, a;
	while (choice != 0) {
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "|     1.Инициализировать список     |" << "  |  9.Поиск элемента перед позицией |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "|     2.Добавить элемент в список   |" << "  |  10.Поиск элемента после позиции  |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 3.Добавить элемент перед значением|" << "  |  11.Удаление элемента по значению |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 4.Добавить элемент после значения |" << "  |12.Удаление элемента перед значением|" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 5.Добавить элемент перед позицией |" << "  |13.Удаление элемента после значения |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 6.Добавить элемент после позиции  |" << "  |14.Удаление элемента перед позицией |" << endl;
		cout << "-------------------------------------" << "  --------------------------------------" << endl;
		cout << "| 7.Поиск перед указанным элементом |" << "  |15.Удаление элемента после позиции  |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "| 8.Поиск после указанного элемента |" << " |16.Просмотр слева направо и справа налево|" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|  19.Перестановка 2-х соседних     |" << " |    17.Кольцевой двусвязнный список      |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|         20.сортировка             |" << " |         18.Запрос для кругов           |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|   22.Меню для конкатенации        |" << " |          21.Отцепить список             |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			initializ(head2, value, key);
			output(head2);
			break;
		case 2:
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) != false) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			push(head2, value, key);
			output(head2);
			break;
		case 3:
			cout << "Введите элемент перед которым добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushBeforeValue(head2, a, value, key);
			output(head2);
			break;
		case 4:
			cout << "Введите элемент после которого добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushAfterValue(head, a, value, key);
			output(head2);
			break;
		case 5:
			cout << "Введите позицию перед которым добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) || checkKey(head2, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushBeforePosition(head2, a, value, key);
			output(head2);
			break;
		case 6:
			cout << "Введите позицию после которого добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head2, key) || checkKey(head, key)) {
				cout << "Данный ключ занят. Введите другой ключ: ";
				cin >> key;
			}
			pushAfterPosition(head2, a + 2, value, key);
			output(head2);
			break;
		case 7:
			cout << "Введите элемент: ";
			cin >> a;
			searchBeforeValue(head2, a);
			break;
		case 8:
			cout << "Введите элемент: ";
			cin >> a;
			searchAfterValue(head2, a);
			break;
		case 9:
			cout << "Введите позицию: ";
			cin >> a;
			searchBeforePosition(head2, a);
			break;
		case 10:
			cout << "Введите позицию: ";
			cin >> a;
			searchAfterPosition(head2, a);
			break;
		case 11:
			cout << "Введите элемент: ";
			cin >> a;
			delValue(head2, a);
			output(head2);
			break;
		case 12:
			cout << "Введите элемент: ";
			cin >> a;
			delbeforeValue(head2, a);
			output(head2);
			break;
		case 13:
			cout << "Введите элемент: ";
			cin >> a;
			delafterValue(head2, a);
			output(head2);
			break;
		case 14:
			cout << "Введите элемент: ";
			cin >> a;
			delbeforePosition(head2, a);
			output(head2);
			break;
		case 15:
			cout << "Введите элемент: ";
			cin >> a;
			delafterPosition(head2, a);
			output(head2);
			break;
		case 16:
			runningLeftRight(head2);
			break;
		case 17:
			round(head2);
			break;
		case 18:
			request(head2);
			break;
		case 19:
			cout << "Введите элемент для swap: ";
			cin >> a;
			swap(head2, a);
			output(head2);
			break;
		case 20:
			bubbleSort(head2);
			output(head2);
			break;
		case 21:
			noRound(head2);
			break;
		}
	}
}
List* concatenation1(List*& head, List*& head2) {
	if (head->next == nullptr || head2->next == nullptr) {
		cout << "Один из списков пустой" << endl;
		return nullptr;
	}
	List* current = head->next;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = head2->next;
	head2->next->prev = current;
	return head;
}
List* concatenation2(List*& head, List*& head2) {
	if (head->next == nullptr || head2->next == nullptr) {
		cout << "Один из списков пустой" << endl;
		return nullptr;
	}
	List* current = head2->next;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = head->next;
	head->next->prev = current;
	return head2;
}
void delConcat1(List*& head, List*& head2) {
	List* current = head->next;
	while (current->next != head2->next) {
		current = current->next;
	}
	current->next = nullptr;
	(head2->next)->prev = head2;
}
void delConcat2(List*& head, List*& head2) {
	List* current = head2->next;
	while (current->next != head->next) {
		current = current->next;
	}
	current->next = nullptr;
	(head->next)->prev = head;
}
void menuConcat2(List*& head, List*& head2) {
	int choice = -1;
	while (choice != 0) {
		cout << "1.Создать первый список" << endl;
		cout << "2.Создать второй список" << endl;
		cout << "3.     1 + 2           " << endl;
		cout << "4.     2 + 1           " << endl;
		cout << "5.Отцепить первый список   " << endl;
		cout << "6.Отцепить второй список   " << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			inition1(head, head2);
			break;
		case 2:
			inition2(head, head2);
			break;
		case 3:
			concatenation1(head, head2);
			output(head);
			break;
		case 4:
			concatenation2(head, head2);
			output(head2);
			break;
		case 5:
			delConcat1(head, head2);
			break;
		case 6:
			delConcat2(head, head);
			break;
		}
	}
}
void menu(List*& head, List*& head2) {
	int choice = -1, value, key, a;
	while (choice != 0) {
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "|     1.Инициализировать список     |" << "  |  9.Поиск элемента перед позицией |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "|     2.Добавить элемент в список   |" << "  |  10.Поиск элемента после позиции  |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 3.Добавить элемент перед значением|" << "  |  11.Удаление элемента по значению |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 4.Добавить элемент после значения |" << "  |12.Удаление элемента перед значением|" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 5.Добавить элемент перед позицией |" << "  |13.Удаление элемента после значения |" << endl;
		cout << "-------------------------------------" << "  -------------------------------------" << endl;
		cout << "| 6.Добавить элемент после позиции  |" << "  |14.Удаление элемента перед позицией |" << endl;
		cout << "-------------------------------------" << "  --------------------------------------" << endl;
		cout << "| 7.Поиск перед указанным элементом |" << "  |15.Удаление элемента после позиции  |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "| 8.Поиск после указанного элемента |" << " |16.Просмотр слева направо и справа налево|" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|  19.Перестановка 2-х соседних     |" << " |    17.Кольцевой двусвязнный список      |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|         20.сортировка             |" << " |         18.Запрос для кругов           |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cout << "|   22.Меню для конкатенации        |" << " |          21.Отцепить список             |" << endl;
		cout << "-------------------------------------" << "  -----------------------------------------" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			initializ(head, value, key);
			output(head);
			break;
		case 2:
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) != false) {
				cout << "Данный ключ занят" << endl;
				cin >> key;
			}
			push(head, value, key);
			output(head);
			break;
		case 3:
			cout << "Введите элемент перед которым добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) != false) {
				cout << "Данный ключ занят" << endl;
				cin >> key;
			}
			pushBeforeValue(head, a, value, key);
			output(head);
			break;
		case 4:
			cout << "Введите элемент после которого добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) != false) {
				cout << "Данный ключ занят" << endl;
				cin >> key;
			}
			pushAfterValue(head, a, value, key);
			output(head);
			break;
		case 5:
			cout << "Введите позицию перед которым добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) != false) {
				cout << "Данный ключ занят" << endl;
				cin >> key;
			}
			pushBeforePosition(head, a, value, key);
			output(head);
			break;
		case 6:
			cout << "Введите позицию после которого добавить: ";
			cin >> a;
			cout << "Введите элемент: ";
			cin >> value;
			cout << "Введите ключ: ";
			cin >> key;
			while (checkKey(head, key) != false) {
				cout << "Данный ключ занят" << endl;
				cin >> key;
			}
			pushAfterPosition(head, a + 2, value, key);
			output(head);
			break;
		case 7:
			cout << "Введите элемент: ";
			cin >> a;
			searchBeforeValue(head, a);
			break;
		case 8:
			cout << "Введите элемент: ";
			cin >> a;
			searchAfterValue(head, a);
			break;
		case 9:
			cout << "Введите позицию: ";
			cin >> a;
			searchBeforePosition(head, a);
			break;
		case 10:
			cout << "Введите позицию: ";
			cin >> a;
			searchAfterPosition(head, a);
			break;
		case 11:
			cout << "Введите элемент: ";
			cin >> a;
			delValue(head, a);
			output(head);
			break;
		case 12:
			cout << "Введите элемент: ";
			cin >> a;
			delbeforeValue(head, a);
			output(head);
			break;
		case 13:
			cout << "Введите элемент: ";
			cin >> a;
			delafterValue(head, a);
			output(head);
			break;
		case 14:
			cout << "Введите элемент: ";
			cin >> a;
			delbeforePosition(head, a);
			output(head);
			break;
		case 15:
			cout << "Введите элемент: ";
			cin >> a;
			delafterPosition(head, a);
			output(head);
			break;
		case 16:
			runningLeftRight(head);
			break;
		case 17:
			round(head);
			break;
		case 18:
			request(head);
			break;
		case 19:
			cout << "Введите элемент для swap: ";
			cin >> a;
			swap(head, a);
			output(head);
			break;
		case 20:
			bubbleSort(head);
			output(head);
			break;
		case 21:
			noRound(head);
			break;
		case 22:
			menuConcat2(head, head2);
			break;
		}
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	List* head = new List;
	List* head2 = new List;
	const unsigned int n = 99999;
	int b = -1;
	head->value = n;
	head->key = b;
	head->next = nullptr;
	head->prev = nullptr;
	head2->value = n;
	head2->key = b;
	head2->next = nullptr;
	head2->prev = nullptr;
	menu(head, head2);
	return 0;
}
