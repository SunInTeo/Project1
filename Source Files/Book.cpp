#include "../Header Files/Book.h"

static char def_str[] = "N/A";

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
	//author = new (std::nothrow) char[strlen(other.author) + 1];
	//if (!author) {
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(author, other.author);
	author = makecopy(other.author);

	//title = new (std::nothrow) char[strlen(other.title) + 1];
	//if (!title)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(title, other.title);
	title = makecopy(other.title);

	strcpy(fileName, other.fileName);

	//description = new (std::nothrow) char[strlen(other.description) + 1];
	//if (!description)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(description, other.description);
	description = makecopy(other.description);

	rating = other.rating;
	
	//ISBN = new (std::nothrow) char[strlen(other.ISBN) + 1];
	//if (!ISBN)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(ISBN, other.ISBN);
	ISBN = makecopy(other.ISBN);
}

char* Book::makecopy(const char* str)
{
	char *copy = new (std::nothrow) char[strlen(str) + 1];
	if (!copy)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(copy, str);

	return copy;
}

Book::Book()
	: author(def_str), title(def_str), description(def_str), ISBN(def_str)
{
	strcpy(fileName, "default.txt");
	rating = 0;
}

Book::Book(const char* author, const char* title, 
			const char* fileName, const char* description, 
			short rating, const char* ISBN)
	: author(makecopy(author)), title(makecopy(title)), description(makecopy(description)), 
		rating(rating), ISBN(makecopy(ISBN))
{
	//this->author = new (std::nothrow) char[strlen(author) + 1];
	//if (!this->author)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(this->author, author);

	//this->title = new (std::nothrow) char[strlen(title) + 1];
	//if (!this->title)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(this->title, title);

	strcpy(this->fileName, fileName);

	//this->description = new (std::nothrow) char[strlen(description) + 1];
	//if (!this->description)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(this->description, description);

	//this->ISBN = new (std::nothrow) char[strlen(ISBN) + 1];
	//if (!this->ISBN)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}
	//strcpy(this->ISBN, ISBN);
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

void Book::displaySorted()
{
	std::cout << title << ", " << author << ", " << ISBN << '\n';
}

void Book::setAuthor(const char* author)
{
	assert(author != nullptr);

	delete[] this->author;
	//this->author = new (std::nothrow) char[strlen(author) + 1];
	//if (!this->author)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}

	//strcpy(this->author, author);
	this->author = makecopy(author);
}

void Book::setTitle(const char* title) {
	assert(title != nullptr);

	delete[] this->title;
	//this->title = new (std::nothrow) char[strlen(title) + 1];
	//if (!this->title)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}

	//strcpy(this->title, title);
	this->title = makecopy(title);
}

void Book::setFileName(const char* fileName)
{
	strcpy(this->fileName, fileName);
}

void Book::setDescription(const char* description) {
	assert(description != nullptr);

	delete[] this->description;
	//this->description = new (std::nothrow) char[strlen(description) + 1];
	//if (!this->description)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}

	//strcpy(this->description, description);
	this->description = makecopy(description);
}

void Book::setRating(short rating)
{
	this->rating = rating;
}

void Book::setISBN(const char* ISBN)
{
	assert(ISBN != nullptr);

	delete[] this->ISBN;
	//this->ISBN = new (std::nothrow) char[strlen(ISBN) + 1];
	//if (!this->ISBN)
	//{
	//	std::cout << "Memory problem!" << std::endl;
	//	return;
	//}

	//strcpy(this->ISBN, ISBN);
	this->ISBN = makecopy(ISBN);
}