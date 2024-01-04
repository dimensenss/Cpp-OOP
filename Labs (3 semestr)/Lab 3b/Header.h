#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Book {
	string author;
	string book_name;
	int pages;
public:
	Book(const string& author = "None", const string& book_name = "None_book", const int& pages = 0);
	void Show_b();
	void set_b(const string& author, const string& book_name, const int& pages);
	string get_b();
};

class Library: protected Book {
	int catalog;
	int avalible;
	int copies;
	friend ostream& operator<<(ostream& stream, Library& ob1);
public:

	Library
	(
		const string& author = "None",
		const string& book_name = "None_book",
		const int& pages = 0,
		const int& catalog = 0,
		const int& avalible = 0,
		const int& copies = 0
	);

	void Show();
	Library operator ()(
		const string& author = "None",
		const string& book_name = "None_book",
		const int& pages = 0,
		const int& catalog = 0,
		const int& avalible = 0,
		const int& copies = 0);
	void search_book(const string& book, Library* arr);
	void pop_book(const string& book, Library*& arr);
	void push_book(const string& book, Library*& arr);
};
