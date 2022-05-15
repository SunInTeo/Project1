#pragma once
#include "Book.h"
#include <vector>
#include <algorithm>

/**
	 class Library is a storage for the books
	 */
class Library
{
private:
	std::vector<Book> books;
	std::fstream file;
	std::string currentPath;

	static const int MAX_STRING_SIZE = 10000;

public:
	Library();
	Library(const char* directory); 
	~Library();

	void open(const char* path);
	Book getBookByTitle(const char* title);

	void addBook(); // asks for password
	void removeBook(const char* title = nullptr,
					const char* ISBN = nullptr); // asks for password
	// displays given book's full text 
	// if numberOfRows is not specified
	void printBook(Book book, int numberOfRows = 0, const char punctuationMark = '#');
	/* order:  0 - ascending, 1 - descending
	by:
		1 - title
		2 - author
		3 - rating
	if nothing is specified, the default order will be ascending 
	and the list will be ordered by title
	print order <title>, <author>, <ISBN> */
	void displaySorted(bool order = 0, int by = 1);
	void displayAllInfo();
	// title, author, isbn, part of a description
	void find(const char* title = nullptr,
		const char* author = nullptr,
		const char* ISBN = nullptr,
		const char* description = nullptr);
};