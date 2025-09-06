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
		cout << "������ ����������" << endl;
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
		cout << "������ ����: " << endl;
		return l;
	}
	if (positions <= -1) {
		cout << "������: ������� ������ ���� ������ ��� ����� ����." << endl;
	}
	for (int i = l->last; i > positions; --i) {
		if (positions >= 0 && positions < maxn && positions < l->last + 1) {
			l->element[i] = l->element[i - 1];
		}
		else if (l->last >= maxn) {
			cout << "������ ��������" << endl;
		}
		else if (positions > maxn) {
			cout << "����� ������� �� ����������" << endl;
		}
	}
	l->element[positions] = value;
	l->last++;
	return l;
}


static L* add_before(L* l, int position, int value) {
	if (l->last == 0) {
		cout << "������ ����: " << endl;
		return l;
	}
	if (position <= 0) {
		cout << "������: ������� ������ ���� ������ ����" << endl;
		return l;
	}
	for (int i = l->last; i > position - 1; --i) {
		if (position >= 0 && position < maxn && position <= l->last + 1) {
			l->element[i] = l->element[i - 1];
		}
		else if (l->last >= maxn) {
			cout << "������ ��������" << endl;
		}
		else if (position > maxn) {
			cout << "����� ������� ���" << endl;
		}
		else if (position > l->last) {
			cout << "������ ��������� ����� ����������� ������" << endl;
		}
	}
	l->element[position - 1] = value;
	l->last++;
	return l;
}


L* add_after(L* l, int position, int value) {       // ����� 
	if (l->last == 0) {
		cout << "������ ����: " << endl;
		return l;
	}
	if (l->last >= maxn) {
		cout << "������ ����������" << endl;
		return l;
	}
	if (position <= l->last) {
		cout << "������������ ������� ��� ����������" << endl;
		return l;
	}
	if (position < 0) {
		cout << "������� ������ ���� ������ ���� ��� ����� ����." << endl;
		return l;
	}
	for (int i = l->last; i > position + 1; --i) {
		if (position >= 0 && position < maxn && position < l->last) {
			l->element[i] = l->element[i - 1];
		}
		else if (position == maxn) {
			cout << "������ ��������" << endl;
		}
		else if (position < 0) {
			cout << "����� ������� ���" << endl;
		}
	}
	l->element[position + 1] = value;
	l->last++;
	return l;
}


L* add_val(L* l, int p_element, int value) {
	if (l->last == 0) {
		cout << "������ ����: " << endl;
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
		cout << "������ �������� ���!!!" << endl;
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
		cout << "������ ����: " << endl;
		return l;
	}
	for (int i = position; i <= l->last - 1; ++i) {
		if (position >= 0 && position < maxn) {
			l->element[i] = l->element[i + 1];
		}
		else if (position == maxn) {
			cout << "������ ��������" << endl;
		}
		else if (position > l->last) {
			cout << "����� ������� ���, ��� �������� ��������" << endl;
		}
	}
	l->last--;
	return l;
}
L* delete_bef(L* l, int position) {
	if (l->last == 0) {
		cout << "������ ����: " << endl;
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
		cout << "������� �� �������" << endl;
	}
	l->last--;
	return l;
}
L* delete_val(L* l, int p_value) {
	if (l->last == 0) {
		cout << "������ ����: " << endl;
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
		cout << "������ �������� � ������ ���!!!" << endl;
		return l;
	}

	int choice;
	do {
		cout << "1. ������� ������ ��������� �������" << endl;
		cout << "2. ������� ��������� ��������� �������" << endl;
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
			cout << "������������ �����, ���������� �����." << endl;
		}
	} while (choice != 1 && choice != 2);

	return l;
}
int search_p(L* l, int position) {
	if (l->last == 0) {
		cout << "������ ����: " << endl;
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
		cout << "��� �������� �� ����� �������" << endl;
	}
	return value;
}

int search_val(L* l, int element) {
	if (l->last == 0) {
		cout << "������ ����: " << endl;
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
		cout << "������ �������� ��� � ������" << endl;
	}
	return value;
}

void delete_l(L* l) {
	if (l->last == 0) {
		cout << "������ ������" << endl;
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
// ��� 
L* add_e_aft(L* l, int value, int element) {
	if (l->last == 0) {
		cout << "������ ������" << endl;
	}
	else if (l->last >= maxn) {
		cout << "������ ���������� " << endl;
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
		cout << "������ �������� ��� � ������" << endl;
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
		cout << "������ ������" << endl;
		return;
	}
	if (l->last >= maxn) {
		cout << "������ ����������" << endl;
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
		cout << "������ �������� ��� � ������" << endl;
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
		cout << "������ ������" << endl;
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

	cout << "������� �� ������ ��� ��� �������� ����� ����" << endl;
}

void delete_before2(L* l, int value) {
	if (l->last <= 1) {
		cout << "������ ������ ��� ������������ ���������" << endl;
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
	cout << "������� �� ������ ��� ��� �������� ����� ���" << endl;
}
int min_pos(L* l) {
	if (l->last == 0) {
		cout << "������ ������" << endl;
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
		cout << "������ ������" << endl;
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
		cout << "����:\n";
		cout << "1. ������������� ��������\n";
		cout << "2. �������� ������� �� �������\n";
		cout << "3. �������� ������� ����� ��������\n";
		cout << "4. �������� ������� ����� �������\n";
		cout << "5. �������� ������� �� ��������\n";
		cout << "6. ������� ������� �� ��������\n";
		cout << "7. ������� ������� �� �������\n";
		cout << "8. ������� ������� ����� ��������\n";
		cout << "9. ������� ������� ����� �������\n";
		cout << "10. ����� �������� �� �������\n";
		cout << "11. ����� �������� �� ��������\n";
		cout << "12. �������� ������\n";
		cout << "13. ���������� �������� ����� ��������� ��������\n";
		cout << "14. ���������� �������� ����� �������� ���������\n";
		cout << "15. �������� �������� ����� ��������� ��������\n";
		cout << "16. �������� �������� ����� �������� ���������\n";
		cout << "17. ����� ������� ������������ ��������\n";
		cout << "18. ������������� ������\n";
		cout << "19. ������� ������\n";
		cout << "0. �����\n";
		cout << "������� ��� �����: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "������� �������� ��� �������������: ";
			cin >> value;
			cout << "������ �� �������������: ";
			output(&l);
			initialization(&l, value);
			cout << "������ ����� �������������: ";
			output(&l);
			break;

		case 2:
			cout << "������� ������� ���� ����� ���������: ";
			cin >> position;
			cout << "������� �������� ��� ����������: ";
			cin >> value;
			cout << "������ �� ����������: ";
			output(&l);
			add(&l, position, value);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 3:
			cout << "������� ������� ����� ������� ��������: ";
			cin >> position;
			cout << "������� �������� ��� ����������: ";
			cin >> value;
			cout << "������ �� ����������: ";
			output(&l);
			add_before(&l, position, value);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 4:
			cout << "������� ������� ����� ������� ��������: ";
			cin >> position;
			cout << "������� �������� ��� ����������: ";
			cin >> value;
			cout << "������ �� ����������: ";
			output(&l);
			add_after(&l, position, value);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 5:
			cout << "������� �������� ���� ����� ���������: ";
			cin >> value;
			cout << "������� �������� ������� ����� ���������: ";
			cin >> position;
			cout << "������ �� ����������: ";
			output(&l);
			add_val(&l, value, position);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 6:
			cout << "������� �������� ��� ��������: ";
			cin >> value;
			cout << "������ �� ��������: ";
			output(&l);
			delete_val(&l, value);
			cout << "������ ����� ��������: ";
			output(&l);
			break;

		case 7:
			cout << "������� ������� ��� ��������: ";
			cin >> position;
			cout << "������ �� ��������: ";
			output(&l);
			delete_p(&l, position);
			cout << "������ ����� ��������: ";
			output(&l);
			break;

		case 8:
			cout << "������� ������� ����� ������� �������: ";
			cin >> position;
			cout << "������ �� ��������: ";
			output(&l);
			delete_bef(&l, position);
			cout << "������ ����� ��������: ";
			output(&l);
			break;

		case 9:
			cout << "������� ������� ����� ������� �������: ";
			cin >> position;
			cout << "������ �� ��������: ";
			output(&l);
			delete_aft(&l, position);
			cout << "������ ����� ��������: ";
			output(&l);
			break;

		case 10:
			cout << "������� ������� ��� ������ ��������: ";
			cin >> position;
			cout << "������� ������: " << search_p(&l, position) << endl;
			break;

		case 11:
			cout << "������� �������� ��� ������ ��������: ";
			cin >> value;
			cout << "������� ������: " << search_val(&l, value) << endl;
			break;

		case 12:
			cout << "������ �� �����������: ";
			output(&l);
			delete_l(&l);
			cout << "������ ����� �����������: ";
			output(&l);
			break;

		case 13:
			cout << "������� ������� ����� ������� ��������: ";
			cin >> position;
			cout << "������� ������� ������� ��������: ";
			cin >> value;
			cout << "������ �� ����������: ";
			output(&l);
			add_e_aft(&l, position, value);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 14:
			cout << "������� �������� ����� ������� ��������: ";
			cin >> position;
			cout << "������� �������, ������� ��������: ";
			cin >> value;
			cout << "������ �� ����������: ";
			output(&l);
			add_before2(&l, position, value);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 15:
			cout << "������� �������� ����� �������� �������: ";
			cin >> value;
			cout << "������ �� ��������: ";
			output(&l);
			delete_after(&l, value);
			cout << "������ ����� ��������: ";
			output(&l);
			break;

		case 16:
			cout << "������� �������� ����� ������� �������: ";
			cin >> value;
			cout << "������ �� ��������: ";
			output(&l);
			delete_before2(&l, value);
			cout << "������ ����� ��������: ";
			output(&l);
			break;

		case 17:
			position = min_pos(&l);
			if (position != -1) {
				cout << "������� ������������ ��������: " << position << endl;
			}
			break;

		case 18:
			cout << "������ �� ����������: ";
			output(&l);
			sort_list(&l);
			cout << "������ ����� ����������: ";
			output(&l);
			break;

		case 19:
			cout << "������� ������: ";
			output(&l);
			break;

		case 0:
			cout << "����� �� ���������." << endl;
			break;

		default:
			cout << "�������� �����. ���������� �����." << endl;
		}
		cout << endl;
	} while (choice != 0);

	return 0;
}