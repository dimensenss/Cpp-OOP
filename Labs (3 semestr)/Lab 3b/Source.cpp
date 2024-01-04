#include "Header.h"
Book::Book(const string& author, const string& book_name , const int& pages ) {
	this->author = author;
	this->book_name = book_name;
	this->pages = pages;
}
void Book::Show_b() {
	cout << "Current book:\n";
	cout << "Author > " << author << "\nBook > " << book_name << "\nPages > " << pages << "\n\n";
}

void Book::set_b(const string& author, const string& book_name, const int& pages) {
	this->author = author;
	this->book_name = book_name;
	this->pages = pages;
}
string Book::get_b() {
	return book_name;
}

Library::Library
(
	const string& author,
	const string& book_name, 
	const int& pages,
	const int& catalog,
	const int& avalible ,
	const int& copies
):Book(author, book_name, pages)
{
	this->catalog = catalog;
	this->avalible = avalible;
	this->copies = copies;
	
};

void Library::Show() {
	string s;
	if (avalible)
		s = "yes";
	else
		s = "no";

	cout << "Current Lib:\n";
	cout << "Catalog > " << catalog << "\nAvalible > " << s << "\nCopies > " << copies << "\n\n";
	Show_b();
}
Library Library::operator ()
(
	const string& author,
	const string& book_name,
	const int& pages,
	const int& catalog,
	const int& avalible ,
	const int& copies
)
{
	set_b(author, book_name, pages);
	this->catalog = catalog;
	this->avalible = avalible;
	this->copies = copies;
	return *this;
}
ostream& operator<<(ostream& stream, Library& ob1){
	ob1.Show();
	cout << "-------------------------------------\n";
	return stream;
}

void Library::search_book(const string& book, Library* arr) {
	for (int i = 0; i < 3; i++)
	{
		if (arr[i].get_b() == book) {
			cout << "Book founded!\n";
			if (arr[i].avalible)
				cout << "Book in library!\n\n\n";
			else
				cout << "Sorry, book isn`t in library\n\n";
		}
	}
}
void Library::pop_book(const string& book, Library*& arr) {
	for (int i = 0; i < 3; i++)
	{
		if (arr[i].get_b() == book) {
			if (arr[i].avalible) {
				arr[i].avalible -= 1;
				cout << "You take a book!\n";
			}
			else
				cout << "Sorry, book isn`t in library\n\n";
		}
	}
}
void Library::push_book(const string& book, Library*& arr) {
	
	for (int i = 0; i < 3; i++)
	{
		if (arr[i].get_b() == book) {
			if (arr[i].avalible != arr[i].copies) {
				arr[i].avalible += 1;
				cout << "You return a book!\n";
			}
			else if (arr[i].avalible == arr[i].copies) {
				cout << "Your book from another library!!!\n\n";
			}
			else
				cout << "Sorry, book isn`t in library\n\n";
		}
	}
}
