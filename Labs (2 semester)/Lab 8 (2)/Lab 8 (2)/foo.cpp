#include "foo.h"


table* create_list_by_hand()
{
	table* ptr, * head, * previous;

	head = previous = ptr = new table;
	int N = 0;

	cout << "Введите название материала, его тип, количество и процент наценки\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;

	char c = 'y';

	while (N < 20 && c == 'y')
	{
		ptr = new table;

		if (head == nullptr)
			head = ptr; // если нет элементов в списке, то первый элемент становится первым
		else
			previous->next = ptr; // предыдущий указывает на текущий

		previous = ptr; // предыдущий становится текущим

		cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;

		cout << "Fill the next one?(y/other key)\n";
		c = _getch();
		++N;
	}
	previous->next = nullptr; //конец списка
	return head;
}

table* create_list_random() {
	table* ptr, * head, * previous;

	head = previous = ptr = new table;

	int N;
	cout << "Enter N: ";
	cin >> N;
	char symbol[3] = { 'T','М','Д' };
	string names[12] = { "Олово","Сталь","Чугун","Золото","Бронза","Золото","Медь","Кварц","Композит","Латунь","Никель","Серебро" };
	string sign[10] = { "0-100","0-10","0-20","15-30","35-50","40-70","10-40","0-25","75-100","15-65" };

	strcpy_s(ptr->name, names[rand() % 12].c_str());
	ptr->type = symbol[rand() % 3];
	strcpy_s(ptr->cnt, sign[rand() % 10].c_str());
	ptr->sq = (double)(rand()) / RAND_MAX * 100;
	--N;

	for (int i = 0; i < N; i++)
	{
		ptr = new table; // выделяем память под следующий элемент
		if (head == nullptr) 
			head = ptr; // если нет элементов в списке, то первый элемент становится первым
		else
			previous->next = ptr; // предыдущий указывает на текущий

		previous = ptr; // предыдущий указатель становится текущим
		

		strcpy_s(ptr->name, names[rand() % 5].c_str());
		ptr->type = symbol[rand() % 3];
		strcpy_s(ptr->cnt, sign[rand() % 10].c_str());
		ptr->sq = (double)(rand()) / RAND_MAX * 100;
	}
	previous->next = nullptr;
	return head;
}


void print_list(table* head) {
	table* ptr = head;
	while (ptr != nullptr)
	{
		printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	cout << "\n";
}
table* search_by_name(table* head, char* name) {
	table* ptr = head;
	while (ptr)
	{
		if (strcmp(ptr->name, name) == 0)
			printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}
table* search_by_type(table* head, char type) {
	table* ptr = head;
	while (ptr)
	{
		if (ptr->type == type)
			printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}
table* search_by_cnt(table* head, char* count) {
	table* ptr = head;
	while (ptr) {
		if (strcmp(ptr->cnt, count) == 0)
			printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}
table* search_by_sq(table* head, float sq) {
	table* ptr = head;
	while (ptr) {
		if (round(ptr->sq * 10) / 10 == sq)
			printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	return nullptr;
}

void add_to_begin(table** head) {
	table* ptr = new table;
	cout << "\nВведите материал и хар-ки:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	ptr->next = *head; // первый элемент становится вторым
	*head = ptr; // первый элемент становится первым
}
void add_to_end(table* head) {
	table* ptr = head;
	table* previous = nullptr;

	while (ptr)
	{
		previous = ptr;
		ptr = ptr->next;
	}
	ptr = new table;
	cout << "\nВведите материал и хар-ки:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	previous->next = ptr; // предыдущий указывает на текущий
	ptr->next = nullptr; // конец списка
}

void add_after_element(table* head)
{
	table* ptr = head;
	table* previous = head;
	char name[12];
	cout << "\nВведите название материала: ";
	cin >> name;
	while (ptr)
	{
		if (strcmp(previous->name, name) == 0)
		{
			ptr = new table;
			ptr->next = previous->next; // предыдущий указывает на текущий
			previous->next = ptr; // предыдущий становится текущим
			cout << "\nВведите материал и хар-ки:\n";
			cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
			break;
		}

		previous = ptr; // предыдущий становится текущим
		ptr = ptr->next; // текущий становится следующим

	}
}

void delete_first(table** head) {
	table* ptr = *head;
	*head = ptr->next;
	delete ptr;
}
void delete_last(table** head) {
	table* ptr = *head;
	table* previous = nullptr;
	while (ptr->next) {
		previous = ptr;
		ptr = ptr->next;
	}
	if (previous == nullptr) {
		delete_first(head);
		return;
	}
	previous->next = nullptr;
	delete ptr;
}
void delete_element(table** head) {
	table* ptr = *head;
	table* previous = nullptr;
	char name[11];
	cout << "\nВведите название материала: ";
	cin >> name;
	if (strcmp(ptr->name, name) == 0) {
		delete_first(head);
		system("cls");
		return;
	}
	while (ptr) {
		if (strcmp(ptr->name, name) == 0) {
			previous->next = ptr->next;
			delete ptr;
			system("cls");
			return;
		}
		else {
			previous = ptr;
			ptr = ptr->next;
		}
	}
}

void sort(table* head) {
	table* left = head;
	table* right = head->next;
	while (left->next) { // пока не дошли до конца списка
		while (right) {
			if ((strcmp(left->name, right->name) > 0)) { // если левый больше правого по алфавиту
				swap(left->name, right->name);
				swap(left->type, right->type);
				swap(left->cnt, right->cnt);
				swap(left->sq, right->sq);
			}
			right = right->next; // переходим к следующему элементу
		}
		left = left->next; // переходим к следующему элементу
		right = left->next; // переходим к следующему элементу
	}
}

void input_in_file(table* head) {
	table* ptr = head;

	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "wt");

	while (ptr)
	{
		fprintf(f, "\n %-11s   %10c   %13s   %10.1f", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	fclose(f);
}

table* read_from_file() {
	table* ptr, * head, * previous;
	ptr = head = previous = new table;
	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "rt");

	fscanf(f, " %s %c %s %f", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
	while (!feof(f)) {
		ptr = new table;
		fscanf(f, " %s %c %s %f", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
		previous->next = ptr;
		previous = ptr;
	}
	ptr->next = nullptr;
	cout << "Done!" << endl;
	fclose(f);
	return head;
	
}


