#include "Book.h"

void Book::deallocate()
{
	if (!author)
		delete[] author;
	if (!title)
		delete[] title;
	if (!description)
		delete[] description;
	if (!ISBN)
		delete[] ISBN;
}

void Book::copy(const Book& other)
{
	author = new (std::nothrow) char[strlen(other.author) + 1];
	if (!author) {
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(author, other.author);

	title = new (std::nothrow) char[strlen(other.title) + 1];
	if (!title)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(title, other.title);

	strcpy(fileName, other.fileName);

	description = new (std::nothrow) char[strlen(other.description) + 1];
	if (!description)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(description, other.description);

	rating = other.rating;
	
	ISBN = new (std::nothrow) char[strlen(other.ISBN) + 1];
	if (!ISBN)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(ISBN, other.ISBN);
}

Book::Book()
{
	strcpy(author, "N/A");
	strcpy(title, "N/A");
	strcpy(fileName, "default.txt");
	strcpy(description, "N/A");
	rating = 0;
	strcpy(ISBN, "N/A");
}

Book::Book(const char* author, const char* title, 
			const char* fileName, const char* description, 
			short rating, const char* ISBN)
	: rating(rating)
{
	this->author = new (std::nothrow) char[strlen(author) + 1];
	if (!this->author)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(this->author, author);

	this->title = new (std::nothrow) char[strlen(title) + 1];
	if (!this->title)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(this->title, title);

	strcpy(this->fileName, fileName);

	this->description = new (std::nothrow) char[strlen(description) + 1];
	if (!this->description)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(this->description, description);

	this->ISBN = new (std::nothrow) char[strlen(ISBN) + 1];
	if (!this->ISBN)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(this->ISBN, ISBN);
}

Book::Book(const Book& other)
{
	copy(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other) {
		deallocate(); // not sure here though
		copy(other);
	}

	return *this;
}

Book::~Book()
{
	deallocate();
}

void Book::setAuthor(const char* author)
{
	assert(author != nullptr);

	delete[] this->author;
	this->author = new (std::nothrow) char[strlen(author) + 1];
	if (!this->author)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	strcpy(this->author, author);
}

void Book::setTitle(const char* title) {
	assert(title != nullptr);

	delete[] this->title;
	this->title = new (std::nothrow) char[strlen(title) + 1];
	if (!this->title)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	strcpy(this->title, title);
}

void Book::setFileName(const char* fileName)
{
	strcpy(this->fileName, fileName);
}

void Book::setDescription(const char* description) {
	assert(description != nullptr);

	delete[] this->description;
	this->description = new (std::nothrow) char[strlen(description) + 1];
	if (!this->description)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	strcpy(this->description, description);
}

void Book::setRating(short rating)
{
	this->rating = rating;
}

void Book::setISBN(const char* ISBN)
{
	assert(ISBN != nullptr);

	delete[] this->ISBN;
	this->ISBN = new (std::nothrow) char[strlen(ISBN) + 1];
	if (!this->ISBN)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}

	strcpy(this->ISBN, ISBN);
}

std::ostream& operator<<(std::ostream& os, const Book& other)
{
	// os << other.title << other.author <<

	return os;
}
