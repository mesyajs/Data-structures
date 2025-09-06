
/*
author - mesyajs
*/
#include <iostream>

class List {
private:
	int key;
	int value;
	List* next;
public:

	List() = default;

	List(int key, int value, List* next) : key(key), value(value), next(next) {}

	List* createList(List*& head, int value, int key) {
		if (head == nullptr) {
			List* newList = new List(key, value, nullptr);
			head = newList;
			return head;
		}
		else {
			std::cout << "Список уже создан" << std::endl;
			return head;
		}
	}

	List* add(List*& head, int value, int key) {
		if (head == nullptr) {
			createList(head, value, key);
			return head;
		}
		List* newList = new List(key, value, nullptr);
		List* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newList;
		return head;
	}
	List* findPosition(List*& head, int index) {
		if (index == 0) {
			List* current = head;
			return current;
		}
		for (int i = 0; List * current = head; current != nullptr; current = current->next; i++) {
			if (i == index - 1 && current != nullptr) {
				return current;
			}
		}
	}
	List* addByPosition(List*& head, int position, int value, int key) {
		List* newList = new List(key, value, nullptr);
		List* current = findPosition(head, position);
		if (current == nullptr) {
			return head;
		}
		else if (position == 0) {
			newList->next = head;
			head = newList;
			return head;
		}
		else {
			newList->next = current->next;
			current->next = newList;
			return head;
		}
	}
	List* findValue(List*& head, int value) {
		if (head == nullptr) {
			std::cout << "Список пуст" << std::endl;
			return head;
		}
		bool checked = false;
		for (List* current = head; current->next != nullptr; current = current->next) {
			if (current->value == value) {
				checked = true;
				return current;
			}
			else if (current->next->value == value) {
				checked = true;
				return current;
			}
		}
		return nullptr;
	}
	List* addByValue(List*& head, int element, int value, int key) {
		if (head == nullptr) {
			std::cout << "Список пуст" << std::endl;
			return head;
		}
		List* newList = new List(key, value, nullptr);
		List* current = findValue(head, element);
		if (current == nullptr) {
			return head;
		}
		else if (head->value == element && current->value == element) {
			newList->next = current;
			current = newList;
			head = newList;
			return head;
		}
		else {
			newList->next = current->next;
			current->next = newList;
			return head;
		}
	}
	List* pushAfterValue(List*& head, int targetVal, int value, int key) {
		if (!head) {
			std::cout << "Список пуст" << std::endl;
			return head;
		}

		auto findNode = [&](List* start, int val) -> List* {
			List* current = start;
			while (current && current->value != val) {
				current = current->next;
			}
			return current;
			};

		List* current = findNode(head, targetVal);
		if (!current) {
			std::cout << "Элемент " << targetVal << " не найден" << std::endl;
			return head;
		}

		List* newNode = new List(key, value, nullptr);
		newNode->next = current->next;
		current->next = newNode;

		return head;
	}
	void searchByKey(List*& head, int key) {
		if (head == nullptr) {
			return;
		}
		bool checked = false;
		for (List* current = head; current != nullptr; current = current->next) {
			if (current->key == key) {
				std::cout << current->value << std::endl;
				checked = true;
			}
		}
		if (!checked) {
			return;
		}
	}
	void searchByValue(List*& head, int x) {
		if (!head) {
			return;
		}
		for (List* current = head; current != nullptr; current = current->next) {
			if (current->value == x) {
				std::cout << current->value << std::endl;
				return;
			}
		}
		return;
	}
	void output(List*& head) {
		for (List* current = head; current != nullptr; current = current->next) {
			std::cout << "Адрес: " << &current->value << "  Значение: " << current->value << "  Ключ: " << current->key << std::endl;
		}
		std::cout << std::endl;
	}
	~List() = default;

	~List() {
		List* current = head;
		while (current->next != nullptr) {
			List* temp = current;
			current = current->next;
			delete temp;
		}
	}
};


int main()
{


}



/*
#include <iostream>
#include <string>
using namespace std;

struct Node {
	string str;
	Node *next;
};
Node *head = nullptr;

Node *create(string str) {
	head = new Node;
	for(int i = 0; i != 1; ++i) {
		head->str = str[i];
	}
	Node *current = head;
	for(int i = 1; i != str.length(); ++i) {
		Node *pv = new Node;
		pv->str = str[i];
		current->next = pv;
		current = pv;
	}
	return head;
}
Node *algorithms() {
	Node *current = head;
	if(current->str == "A" || current->str == "a") {
		while(current != nullptr) {
			if(current->next == nullptr) {
				current->str = "A";
			}
			current = current->next;
		}
	}
	current = head;
	bool check = false;
	if(current->str != "A" && current->str != "a") {
		while(current->next != nullptr) {
			if(current->next->str == "A" || current->next->str == "a") {
				if(current->next->next == nullptr) {
					delete current->next;
					current->next = nullptr;
					break;
				} else if(current->next->str == "A" || current->next->str == "a") {
					Node *temp = current->next;
					current->next = current->next->next;
					delete temp;
					check = true;
				}
			} else {
				check = false;
			}
			if(!check) {
				current = current->next;
			}
		}
	}
	return head;
}
void output() {
	Node*current = head;
	while(current != nullptr) {
		cout << current->str;
		current = current->next;
	}
	cout << endl;
}
int main() {
	string str;
	cout << "Введите строку: ";
	cin >> str;
	create(str);
	algorithms();
	output();
}
*/