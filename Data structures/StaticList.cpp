#include <iostream> 
using namespace std;

const int maxn = 100;

struct L {
	int element[maxn];
	int last = 0;
};

L* initialization(L* l, int value) {
	if (l->last < maxn) {
		l->element[l->last++] = value;
	}
	else {
		cout << "Список переполнен" << endl;
	}
	return l;
}

void output(L* l) {
	for (int i = 0; i != l->last; ++i) {
		cout << l->element[i] << " ";
	}
	cout << endl;
}

L* add(L* l, int positions, int value) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	if (positions <= -1) {
		cout << "Ошибка: позиция должна быть больше или равна нулю." << endl;
	}
	for (int i = l->last; i > positions; --i) {
		if (positions >= 0 && positions < maxn && positions < l->last + 1) {
			l->element[i] = l->element[i - 1];
		}
		else if (l->last >= maxn) {
			cout << "Список заполнен" << endl;
		}
		else if (positions > maxn) {
			cout << "Такой позиции не существует" << endl;
		}
	}
	l->element[positions] = value;
	l->last++;
	return l;
}


static L* add_before(L* l, int position, int value) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	if (position <= 0) {
		cout << "Ошибка: позиция должна быть больше нуля" << endl;
		return l;
	}
	for (int i = l->last; i > position - 1; --i) {
		if (position >= 0 && position < maxn && position <= l->last + 1) {
			l->element[i] = l->element[i - 1];
		}
		else if (l->last >= maxn) {
			cout << "Список заполнен" << endl;
		}
		else if (position > maxn) {
			cout << "Такой позиции нет" << endl;
		}
		else if (position > l->last) {
			cout << "Нельзя вставлять после порядкового номера" << endl;
		}
	}
	l->element[position - 1] = value;
	l->last++;
	return l;
}


L* add_after(L* l, int position, int value) {       // после 
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	if (l->last >= maxn) {
		cout << "Список переполнен" << endl;
		return l;
	}
	if (position <= l->last) {
		cout << "Недопустимая позиция для добавления" << endl;
		return l;
	}
	if (position < 0) {
		cout << "Позиция должна быть больше нуля или равна нулю." << endl;
		return l;
	}
	for (int i = l->last; i > position + 1; --i) {
		if (position >= 0 && position < maxn && position < l->last) {
			l->element[i] = l->element[i - 1];
		}
		else if (position == maxn) {
			cout << "Список заполнен" << endl;
		}
		else if (position < 0) {
			cout << "Такой позиции нет" << endl;
		}
	}
	l->element[position + 1] = value;
	l->last++;
	return l;
}


L* add_val(L* l, int p_element, int value) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	int index = 0;
	bool isDigit = true;
	for (int i = 0; i != l->last; ++i) {
		if (l->element[i] == p_element) {
			index = i;
			isDigit = true;
			break;
		}
		else {
			isDigit = false;
		}
	}
	if (isDigit != true) {
		cout << "Такого значения нет!!!" << endl;
		return l;
	}

	for (int i = l->last; i >= index; --i) {
		l->element[i + 1] = l->element[i];
		if (l->element[i] == p_element) {
			l->element[i] = value;
			l->last++;
		}
	}
	return l;
}
L* delete_p(L* l, int position) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	for (int i = position; i <= l->last - 1; ++i) {
		if (position >= 0 && position < maxn) {
			l->element[i] = l->element[i + 1];
		}
		else if (position == maxn) {
			cout << "Список заполнен" << endl;
		}
		else if (position > l->last) {
			cout << "Такой позиции нет, для удаления элемента" << endl;
		}
	}
	l->last--;
	return l;
}
L* delete_bef(L* l, int position) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	for (int i = position - 1; i < l->last - 1; ++i) {
		l->element[i] = l->element[i + 1];
	}
	l->last--;
	return l;
}
L* delete_aft(L* l, int position) {
	for (int i = position + 1; i <= l->last - 1; ++i) {
		l->element[i] = l->element[i + 1];
	}
	if (position == -1) {
		cout << "Позиция не найдена" << endl;
	}
	l->last--;
	return l;
}
L* delete_val(L* l, int p_value) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return l;
	}
	int index1 = -1;
	int index2 = -1;
	bool found = false;

	for (int i = 0; i != l->last; ++i) {
		if (l->element[i] == p_value) {
			index1 = i;
			found = true;
			break;
		}
	}
	for (int i = l->last - 1; i >= 0; --i) {
		if (l->element[i] == p_value) {
			index2 = i;
			found = true;
			break;
		}
	}

	if (!found) {
		cout << "Такого значения в списке нет!!!" << endl;
		return l;
	}

	int choice;
	do {
		cout << "1. Удалить первый найденный элемент" << endl;
		cout << "2. Удалить последний найденный элемент" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			for (int i = index1; i < l->last - 1; ++i) {
				l->element[i] = l->element[i + 1];
			}
			l->last--;
			return l;

		case 2:
			for (int i = index2; i < l->last - 1; ++i) {
				l->element[i] = l->element[i + 1];
			}
			l->last--;
			return l;

		default:
			cout << "Неправильный выбор, попробуйте снова." << endl;
		}
	} while (choice != 1 && choice != 2);

	return l;
}
int search_p(L* l, int position) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return -1;
	}
	int index = 0;
	int value = 0;
	bool isDigit = true;
	for (int i = 0; i != l->last; ++i) {
		if (i == position) {
			index = i;
			value = l->element[i];
			isDigit = true;
			break;
		}
		else {
			isDigit = false;
		}

	}
	if (isDigit != true) {
		cout << "Нет элемента на такой позиции" << endl;
	}
	return value;
}

int search_val(L* l, int element) {
	if (l->last == 0) {
		cout << "Список пуст: " << endl;
		return -1;
	}
	int value = 0;
	bool isDigit = true;
	for (int i = 0; i != l->last; ++i) {
		if (l->element[i] == element) {
			value = l->element[i];
			isDigit = true;
			break;
		}
		else {
			isDigit = false;
		}
	}
	if (isDigit != true) {
		cout << "Такого элемента нет в списке" << endl;
	}
	return value;
}

void delete_l(L* l) {
	if (l->last == 0) {
		cout << "Список пустой" << endl;
	}
	else {
		for (int i = 0; i != l->last; ++i) {
			l->element[i] = 0;
		}
	}
	for (int i = 0; i != l->last; ++i) {
		cout << l->element[i] << " " << endl;
	}
	l->last = 0;
}
// СРС 
L* add_e_aft(L* l, int value, int element) {
	if (l->last == 0) {
		cout << "Список пустой" << endl;
	}
	else if (l->last >= maxn) {
		cout << "Список переполнен " << endl;
	}

	int index = 0;
	bool isdigit = true;
	for (int i = 0; i != l->last; ++i) {
		if (l->element[i] == value) {
			index = i + 1;
			isdigit = true;
			break;
		}
		else {
			isdigit = false;
		}
	}
	if (isdigit != true) {
		cout << "Такого элемента нет в списке" << endl;
		return l;
	}
	for (int i = l->last; i > index; --i) {
		l->element[i] = l->element[i - 1];
	}
	l->element[index] = element;
	l->last++;
	return l;
}
void add_before2(L* l, int value, int element) {
	if (l->last == 0) {
		cout << "Список пустой" << endl;
		return;
	}
	if (l->last >= maxn) {
		cout << "Список переполнен" << endl;
		return;
	}
	int index = -1;
	for (int i = 0; i < l->last; ++i) {
		if (l->element[i] == value) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "Такого элемента нет в списке" << endl;
		return;
	}
	for (int i = l->last; i > index; --i) {
		l->element[i] = l->element[i - 1];
	}
	l->element[index] = element;
	l->last++;
}

void delete_after(L* l, int value) {
	if (l->last == 0) {
		cout << "Список пустой" << endl;
		return;
	}

	for (int i = 0; i < l->last - 1; ++i) {
		if (l->element[i] == value) {
			for (int j = i + 1; j < l->last - 1; ++j) {
				l->element[j] = l->element[j + 1];
			}
			l->last--;
			return;
		}
	}

	cout << "Элемент не найден или нет элемента после него" << endl;
}

void delete_before2(L* l, int value) {
	if (l->last <= 1) {
		cout << "Список пустой или недостаточно элементов" << endl;
		return;
	}
	for (int i = 1; i < l->last; ++i) {
		if (l->element[i] == value) {
			for (int j = i - 1; j < l->last - 1; ++j) {
				l->element[j] = l->element[j + 1];
			}
			l->last--;
		}
	}
	cout << "Элемент не найден или нет элемента перед ним" << endl;
}
int min_pos(L* l) {
	if (l->last == 0) {
		cout << "Список пустой" << endl;
		return -1;
	}

	int min_pos = 0;
	for (int i = 1; i < l->last; ++i) {
		if (l->element[i] < l->element[min_pos]) {
			min_pos = i;
		}
	}

	return min_pos;
}
void sort_list(L* l) {
	if (l->last == 0) {
		cout << "Список пустой" << endl;
		return;
	}
	for (int i = 0; i < l->last - 1; ++i) {
		for (int j = 0; j < l->last - i - 1; ++j) {
			if (l->element[j] > l->element[j + 1]) {
				int temp = l->element[j];
				l->element[j] = l->element[j + 1];
				l->element[j + 1] = temp;
			}
		}
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	L l;
	l.last = 0;
	int choice;
	int value, position;

	do {
		cout << "Меню:\n";
		cout << "1. Инициализация элемента\n";
		cout << "2. Добавить элемент по позиции\n";
		cout << "3. Добавить элемент перед позицией\n";
		cout << "4. Добавить элемент после позиции\n";
		cout << "5. Добавить элемент по значению\n";
		cout << "6. Удалить элемент по значению\n";
		cout << "7. Удалить элемент по позиции\n";
		cout << "8. Удалить элемент перед позицией\n";
		cout << "9. Удалить элемент после позиции\n";
		cout << "10. Поиск элемента по позиции\n";
		cout << "11. Поиск элемента по значению\n";
		cout << "12. Удаление списка\n";
		cout << "13. Добавление элемента после заданного значения\n";
		cout << "14. Добавление элемента перед заданным элементом\n";
		cout << "15. Удаление элемента после заданного значения\n";
		cout << "16. Удаление элемента перед заданным значением\n";
		cout << "17. Найти позицию минимального элемента\n";
		cout << "18. Отсортировать список\n";
		cout << "19. Вывести список\n";
		cout << "0. Выйти\n";
		cout << "Введите ваш выбор: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Введите значение для инициализации: ";
			cin >> value;
			cout << "Список до инициализации: ";
			output(&l);
			initialization(&l, value);
			cout << "Список после инициализации: ";
			output(&l);
			break;

		case 2:
			cout << "Введите позицию куда будем добавлять: ";
			cin >> position;
			cout << "Введите значение для добавления: ";
			cin >> value;
			cout << "Список до добавления: ";
			output(&l);
			add(&l, position, value);
			cout << "Список после добавления: ";
			output(&l);
			break;

		case 3:
			cout << "Введите позицию перед которой добавить: ";
			cin >> position;
			cout << "Введите значение для добавления: ";
			cin >> value;
			cout << "Список до добавления: ";
			output(&l);
			add_before(&l, position, value);
			cout << "Список после добавления: ";
			output(&l);
			break;

		case 4:
			cout << "Введите позицию после которой добавить: ";
			cin >> position;
			cout << "Введите значение для добавления: ";
			cin >> value;
			cout << "Список до добавления: ";
			output(&l);
			add_after(&l, position, value);
			cout << "Список после добавления: ";
			output(&l);
			break;

		case 5:
			cout << "Введите значение куда будем добавлять: ";
			cin >> value;
			cout << "Введите значение который будем добавлять: ";
			cin >> position;
			cout << "Список до добавления: ";
			output(&l);
			add_val(&l, value, position);
			cout << "Список после добавления: ";
			output(&l);
			break;

		case 6:
			cout << "Введите значение для удаления: ";
			cin >> value;
			cout << "Список до удаления: ";
			output(&l);
			delete_val(&l, value);
			cout << "Список после удаления: ";
			output(&l);
			break;

		case 7:
			cout << "Введите позицию для удаления: ";
			cin >> position;
			cout << "Список до удаления: ";
			output(&l);
			delete_p(&l, position);
			cout << "Список после удаления: ";
			output(&l);
			break;

		case 8:
			cout << "Введите позицию перед которой удалить: ";
			cin >> position;
			cout << "Список до удаления: ";
			output(&l);
			delete_bef(&l, position);
			cout << "Список после удаления: ";
			output(&l);
			break;

		case 9:
			cout << "Введите позицию после которой удалить: ";
			cin >> position;
			cout << "Список до удаления: ";
			output(&l);
			delete_aft(&l, position);
			cout << "Список после удаления: ";
			output(&l);
			break;

		case 10:
			cout << "Введите позицию для поиска элемента: ";
			cin >> position;
			cout << "Элемент найден: " << search_p(&l, position) << endl;
			break;

		case 11:
			cout << "Введите значение для поиска элемента: ";
			cin >> value;
			cout << "Элемент найден: " << search_val(&l, value) << endl;
			break;

		case 12:
			cout << "Список до уничтожения: ";
			output(&l);
			delete_l(&l);
			cout << "Список после уничтожения: ";
			output(&l);
			break;

		case 13:
			cout << "Введите элемент после которой добавить: ";
			cin >> position;
			cout << "Введите элемент которую добавить: ";
			cin >> value;
			cout << "Список до добавления: ";
			output(&l);
			add_e_aft(&l, position, value);
			cout << "Список после добавления: ";
			output(&l);
			break;

		case 14:
			cout << "Введите значение перед которым добавить: ";
			cin >> position;
			cout << "Введите элемент, который добавить: ";
			cin >> value;
			cout << "Список до добавления: ";
			output(&l);
			add_before2(&l, position, value);
			cout << "Список после добавления: ";
			output(&l);
			break;

		case 15:
			cout << "Введите значение после которого удалить: ";
			cin >> value;
			cout << "Список до удаления: ";
			output(&l);
			delete_after(&l, value);
			cout << "Список после удаления: ";
			output(&l);
			break;

		case 16:
			cout << "Введите значение перед которым удалить: ";
			cin >> value;
			cout << "Список до удаления: ";
			output(&l);
			delete_before2(&l, value);
			cout << "Список после удаления: ";
			output(&l);
			break;

		case 17:
			position = min_pos(&l);
			if (position != -1) {
				cout << "Позиция минимального элемента: " << position << endl;
			}
			break;

		case 18:
			cout << "Список до сортировки: ";
			output(&l);
			sort_list(&l);
			cout << "Список после сортировки: ";
			output(&l);
			break;

		case 19:
			cout << "Текущий список: ";
			output(&l);
			break;

		case 0:
			cout << "Выход из программы." << endl;
			break;

		default:
			cout << "Неверный выбор. Попробуйте снова." << endl;
		}
		cout << endl;
	} while (choice != 0);

	return 0;
}