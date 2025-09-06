#include <iostream> 
#include <iomanip>
using namespace std;

struct Tree {
	int key;
	Tree* left;
	Tree* right;
};
struct List {
	int value;
	List* next;
};
int chooseValue(List* head, int value) {
	List* current = head;
	bool isdigit = false;

	while (current != nullptr) {
		if (current->value == value) {
			return current->value;
		}
		isdigit = false;
		current = current->next;
	}
	if (!isdigit) {
		cout << "������� �� ��� ������" << endl;
		return 0;
	}
}
List* push(List*& head, int value) {
	List* newNode = new List{ value, nullptr };

	if (head == nullptr) {
		head = newNode;
		return head;
	}
	List* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = newNode;
	return head;
}
Tree* sroot = nullptr;
int _count = 0;
Tree* insert(Tree*& top, int key) {
	Tree* newNode = new Tree{ key, nullptr, nullptr };
	if (top == nullptr) {
		top = newNode;
		return top;
	}
	else {
		if (top->key % 2 != 0) {
			insert(top->left, key);
			return top;
		}
		else if (top->key % 2 == 0) {
			insert(top->right, key);
			return top;
		}
	}
}
Tree* searchMinRoot(Tree* top) {
	while (top && top->left != nullptr) {
		top = top->left;
	}
	return top;
}
Tree* deleteRoot(Tree*& top, int root) {
	if (top == nullptr) {
		return nullptr;
	}

	if (root < top->key) {
		top->left = deleteRoot(top->left, root);
	}
	else if (root > top->key) {
		top->right = deleteRoot(top->right, root);
	}
	else {
		if (top->left == nullptr) {
			Tree* temp = top->right;
			delete top;
			return temp;
		}
		else if (top->right == nullptr) {
			Tree* temp = top->left;
			delete top;
			return temp;
		}
		else {
			Tree* minNode = searchMinRoot(top->right);
			top->key = minNode->key;
			top->right = deleteRoot(top->right, minNode->key);
		}
	}
	return top;
}
Tree* inOrder(Tree* top) {
	if (top == nullptr) {
		return nullptr;
	}
	inOrder(top->left);
	cout << top->key << " ";
	inOrder(top->right);
}
Tree* preOrder(Tree* top) {
	if (top == nullptr) {
		return nullptr;
	}
	cout << top->key << " ";
	preOrder(top->left);
	preOrder(top->right);
}
void postOrder(Tree* top) {
	if (top == nullptr) {
		return;
	}
	postOrder(top->left);
	postOrder(top->right);
	cout << top->key << " ";
}
int countingTop(Tree* top) {
	int count = 1;
	if (top == nullptr) {
		return 0;
	}
	count += countingTop(top->left);
	count += countingTop(top->right);
	return count;
}
int countList(Tree* root) {
	if (root == nullptr) {
		return 0;
	}
	if (root->left == nullptr && root->right == nullptr) {
		return 1;
	}
	return countList(root->left) + countList(root->right);
}
void deleteBinaryTree(Tree* top) {
	if (top == nullptr) {
		return;
	}
	deleteBinaryTree(top->left);
	deleteBinaryTree(top->right);
	delete top;
}
void searchByRoot(Tree* top, int root) {
	if (top->key == root) {
		if (sroot == nullptr) {
			cout << "����� �������: " << &top->key << "  �������: " << top->key << endl;
			cout << "����� ������� �������: " << &top->right->key << "  ������ �������: " << top->right->key << endl;
			cout << "����� ������ �������: " << &top->left->key << "  ����� �������: " << top->left->key << endl;
			return;
		}
		else if (sroot != nullptr && top->left != nullptr && top->right == nullptr) {
			cout << "����� ��������: " << &sroot->key << "  ��������: " << sroot->key << endl;
			cout << "����� �������: " << &top->key << "  �������: " << top->key << endl;
			cout << "����� ������ �������: " << &top->left->key << "  ����� �������: " << top->left->key << endl;
			return;
		}
		else if (sroot != nullptr && top->left == nullptr && top->right != nullptr) {
			cout << "����� ��������: " << &sroot->key << "  ��������: " << sroot->key << endl;
			cout << "����� �������: " << &top->key << "  �������: " << top->key << endl;
			cout << "����� ������� �������: " << &top->right->key << "  ������ �������: " << top->right->key << endl;
			return;

		}
		else if (sroot != nullptr && top->left == nullptr && top->right == nullptr) {
			cout << "����� ��������: " << &sroot->key << "  ��������: " << sroot->key << endl;
			cout << "����� �����: " << &top->key << "  ����: " << top->key << endl;
			return;
		}
		cout << "����� ��������: " << &sroot->key << "  ��������: " << sroot->key << endl;
		cout << "����� �������: " << &top->key << "  �������: " << top->key << endl;
		cout << "����� ������� �������: " << &top->right->key << "  ������ �������: " << top->right->key << endl;
		cout << "����� ������ �������: " << &top->left->key << "  ����� �������: " << top->left->key << endl;
		return;
	}
	sroot = top;
	if (root < top->key) {
		searchByRoot(top->left, root);
	}
	else if (root > top->key) {
		searchByRoot(top->right, root);
	}
}
void printTree(Tree* root, int space = 0, int indent = 5) {
	if (root == nullptr)
		return;
	space += indent;
	printTree(root->right, space);
	cout << endl;
	cout << setw(space) << root->key << endl;
	printTree(root->left, space);
}
void output(List* head) {
	List* current = head;
	while (current != nullptr) {
		cout << current->value << " ";
		current = current->next;
	}
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "RU");
	Tree* top = nullptr;
	List* head = nullptr;
	push(head, 10);
	push(head, 11);
	push(head, 12);
	push(head, 16);
	push(head, 17);
	push(head, 20);
	push(head, 19);
	push(head, 100);
	push(head, 99);
	int choice = -1, key, value;
	while (choice != 0) {
		cout << "1.���������� ������� ������" << endl;
		cout << "2.�������� ������� ������" << endl;
		cout << "3.����� ������� ������ �� �����" << endl;
		cout << "4.������� ���������� ������ ������" << endl;
		cout << "5.����� ������ �� �����" << endl;
		cout << "6.������� ���������� �������" << endl;
		cout << "7.����������� ������" << endl;
		cout << "8.Preorder VLR" << endl;
		cout << "9.Inorder LVR" << endl;
		cout << "10.Postorder LRV" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			output(head);
			cout << "������� ������� ������� ����� �����: ";
			cin >> key;
			value = chooseValue(head, key);
			insert(top, value);
			printTree(top);
			break;
		case 2:
			cout << "������� ������� ������: ";
			cin >> key;
			deleteRoot(top, key);
			printTree(top);
			break;
		case 3:
			cout << "������� ����: ";
			cin >> key;
			searchByRoot(top, key);
			break;
		case 4:
			cout << "���������� ������ ������: " << countingTop(top) << endl;
			break;
		case 5:
			printTree(top);
			break;
		case 6:
			cout << "���������� �������: " << countList(top) << endl;
			break;
		case 7:
			deleteBinaryTree(top);
			break;
		case 8:
			preOrder(top);
			break;
		case 9:
			inOrder(top);
			break;
		case 10:
			postOrder(top);
			break;
		}
	}
}