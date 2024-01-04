#include "foo.h"

extern struct table* head , * tail;

void create_list_by_hand()
{
	table* ptr, * previous;
	
	previous = nullptr;
	do {
		ptr = new table;
		cout << "������� �������� ���������, ��� ���, ���������� � ������� �������\n";
		cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
		
		ptr->prev = previous;
		if (previous != nullptr)
			previous->next = ptr;
		else
			head = ptr;
		previous = ptr;
		puts(" �������� - <esc>");
	} while (_getch() != 27);
	
	tail = ptr;
	tail->next = nullptr;
}
void create_list_random() {
	table* ptr,* previous;

	head = previous = ptr = new table;
	previous = nullptr;

	int N;
	cout << "Enter N: ";
	cin >> N;
	char symbol[3] = { 'T','�','�' };
	string names[12] = { "�����","�����","�����","������","������","������","����","�����","��������","������","������","�������" };
	string sign[10] = { "0-100","0-10","0-20","15-30","35-50","40-70","10-40","0-25","75-100","15-65" };

	for (int i = 0; i < N; i++)
	{
		ptr = new table;
		
		strcpy_s(ptr->name, names[rand() % 5].c_str());
		ptr->type = symbol[rand() % 3];
		strcpy_s(ptr->cnt, sign[rand() % 10].c_str());
		ptr->sq = (double)(rand()) / RAND_MAX * 100;
		
		ptr->prev = previous;
		if (previous != nullptr)
			previous->next = ptr;
		else
			head = ptr;
		previous = ptr;
	}
	tail = ptr;
	tail->next = nullptr;
	
}
void print_list_begin(table* head) {
	table* ptr = head;
	while (ptr != nullptr)
	{
		printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->next;
	}
	cout << "\n";
}
void print_list_end(table* tail) {
	table* ptr = tail;
	while (ptr != nullptr)
	{
		printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
		ptr = ptr->prev;
	}
	cout << "\n";
}
void search_by_name(table* p, char* name) {
	table* ptr = p;
	if (ptr == head)
	{
		while (ptr)
		{
			if (strcmp(ptr->name, name) == 0)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else 
	{
		while (ptr)
		{
			if (strcmp(ptr->name, name) == 0)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void search_by_type(table* p, char type) {
	table* ptr = p;
	if (ptr == head) 
	{
		while (ptr)
		{
			if (ptr->type == type)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (ptr->type == type)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void search_by_cnt(table* p, char* count) {
	table* ptr = p;
	if (ptr == head) {
		while (ptr)
		{
			if (strcmp(ptr->cnt, count) == 0)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr)
		{
			if (strcmp(ptr->cnt, count) == 0)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void search_by_sq(table* p, float sq) {
	table* ptr = p;
	if (ptr == head) 
	{
		while (ptr) 
		{
			if (round(ptr->sq * 10) / 10 == sq)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->next;
		}
	}
	else
	{
		while (ptr) {
			if (round(ptr->sq * 10) / 10 == sq)
				printf("\n[ %-11s   %10c   %13s   %10.1f ]", ptr->name, ptr->type, ptr->cnt, ptr->sq);
			ptr = ptr->prev;
		}
	}
}
void add_to_begin() {
	table* ptr = new table;
	cout << "\n������� �������� � ���-��:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	ptr->prev = nullptr; // ���������� ��������� �� nullptr
	ptr->next = head;// ��������� ��������� �� ������ �������
	head->prev = ptr; // ���������� ��������� �� ����� ����
	head = ptr; // ����� ���� ���������� �������
	 
	
	
}
void add_to_end() {
	table* ptr = head;
	table* previous = nullptr;

	while (ptr)
	{
		previous = ptr;
		ptr = ptr->next;
	}
	ptr = new table;
	cout << "\n������� �������� � ���-��:\n";
	cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
	previous->next = ptr; // ���������� ��������� �� �������
	ptr->prev = previous; // ������� ��������� �� ����������
	ptr->next = nullptr; // ����� ������
	tail = ptr;
}
void add_after_element()
{
	table* ptr = head;
	table* previous = head;
	char name[12];
	cout << "\n������� �������� ���������: ";
	cin >> name;
	while (ptr)
	{
		if (strcmp(previous->name, name) == 0)
		{
			ptr = new table;
			ptr->next = previous->next; // ��������� ��������� �� �������
			previous->next->prev = ptr; // ������� ��������� �� ����������
			ptr->prev = previous; // ���������� ��������� �� ����� ����
			previous->next = ptr; // ���������� ���������� �������
			cout << "\n������� �������� � ���-��:\n";
			cin >> ptr->name >> ptr->type >> ptr->cnt >> ptr->sq;
			break;
		}

		previous = ptr; // ���������� ���������� �������
		ptr = ptr->next; // ������� ���������� ���������

	}
}
void delete_first() {
	table* ptr = head;
	head = ptr->next;
	head->prev = NULL;
	free(ptr);
	ptr = head;
}
void delete_last() {
	table* ptr = head;
	table* previous = nullptr;
	while (ptr->next) {
		previous = ptr;
		ptr = ptr->next;
	}
	if (previous == nullptr) {
		delete_first();
		return;
	}
	previous->next = nullptr;
	tail = previous;
	free(ptr);
	
}
void delete_element() {
	table* ptr = head;
	table* previous = nullptr;
	char name[11];
	cout << "\n������� �������� ���������: ";
	cin >> name;
	if (strcmp(ptr->name, name) == 0) {
		delete_first();
		system("cls");
		return;
	}
	while (ptr) {
		if (strcmp(ptr->name, name) == 0) {
			if (ptr->next == nullptr) {
				previous->next = nullptr;
				tail = previous;
				free(ptr);
				system("cls");
				return;
			}
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
			free(ptr);
			system("cls");
			return;
		}
		else {
			previous = ptr;
			ptr = ptr->next;
		}
	}
}
void sort() {
	table* left = head;
	table* right = head->next;
	while (left->next) { // ���� �� ����� �� ����� ������
		while (right) {
			if ((strcmp(left->name, right->name) > 0)) { // ���� ����� ������ ������� �� ��������
				swap(left->name, right->name);
				swap(left->type, right->type);
				swap(left->cnt, right->cnt);
				swap(left->sq, right->sq);
			}
			right = right->next; // ��������� � ���������� ��������
		}
		left = left->next; // ��������� � ���������� ��������
		right = left->next; // ��������� � ���������� ��������
	}
}
void input_in_file() {
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
void read_from_file() {
	table* ptr, * previous;
	ptr = head = previous = new table;
	head->prev = nullptr;
	FILE* f;
	char fname[] = "file.txt";
	fopen_s(&f, fname, "rt");

	fscanf(f, " %s %c %s %f", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
	while (!feof(f)) {
		ptr = new table;
		fscanf(f, " %s %c %s %f", &ptr->name, &ptr->type, &ptr->cnt, &ptr->sq);
		previous->next = ptr;
		ptr->prev = previous;
		previous = ptr;
	}
	ptr->next = nullptr;
	tail = ptr;
	cout << "Done!" << endl;
	fclose(f);

}
