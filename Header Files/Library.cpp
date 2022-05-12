#include "Library.h"

Library::~Library()
{
	delete[] books;
}

void Library::addBook()
{
	std::cout << "In order to add a book, you need to provide all the necessary information about it.\n";
	std::cout << "Title: ";
	// input title
	std::cout << "Author: ";
	// input author
	std::cout << "Filename where the text is stored: ";
	// input filename
	std::cout << "Description: ";
	// input description
	std::cout << "Rating: ";
	// input rating
	std::cout << "ISBN: ";
	// input isbn

	// open and write to file
}