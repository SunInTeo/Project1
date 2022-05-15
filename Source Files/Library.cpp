#include "../Header Files/Library.h"

Library::Library() 
	: currentPath("default.txt"), file("default.txt", std::ios::in | std::ios::out | std::ios::app)
{
}

Library::Library(const char* directory) 
	: currentPath(directory), file(directory, std::ios::in | std::ios::out | std::ios::app)
{
}

Library::~Library()
{
	file.close();
}

void Library::open(const char* path)
{
	currentPath = path;
	file.open(currentPath, std::ios::in | std::ios::out | std::ios::app);
}

void Library::addBook()
{
	Book newBook;
	std::string author, title, fileName, description, ISBN;
	std::string rating;

	std::cout << "In order to add a book, you need to provide all the necessary information about it.\n";
	std::cout << "Author: ";
	getline(std::cin, author);
	newBook.setAuthor(author.c_str());
	std::cout << "Title: ";
	getline(std::cin, title);
	newBook.setTitle(title.c_str());
	std::cout << "Filename where the text is stored: ";
	getline(std::cin, fileName);
	newBook.setFileName(fileName.c_str());
	std::cout << "Description: ";
	getline(std::cin, description);
	newBook.setDescription(description.c_str());
	std::cout << "Rating: ";
	getline(std::cin, rating);
	newBook.setRating(std::stoi(rating));
	std::cout << "ISBN: ";
	getline(std::cin, ISBN);
	newBook.setISBN(description.c_str());

	books.push_back(newBook);
}

Book Library::getBookByTitle(const char* title)
{
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		if (strcmp(toUpperCase(it->getTitle()).c_str(), toUpperCase(title).c_str()) == 0) {
			return *it;
		}
	}
	return Book();
}

void Library::removeBook(const char* title, const char* ISBN)
{
	if (title != nullptr)
	{
		for (auto it = books.begin(); it != books.end(); ++it)
		{
			if (strcmp(it->getTitle(), title) == 0)
			{
				eraseFileLine(currentPath, it->getAuthor());
				eraseFileLine(currentPath, it->getTitle());
				eraseFileLine(currentPath, it->getFileName());
				eraseFileLine(currentPath, it->getDescription());
				eraseFileLine(currentPath, (char*)it->getRating());
				eraseFileLine(currentPath, it->getISBN());
				books.erase(it);
			}
		}
	}
	if (ISBN != nullptr)
	{
		for (auto it = books.begin(); it != books.end(); ++it)
		{
			if (strcmp(it->getISBN(), ISBN) == 0)
			{
				eraseFileLine(currentPath, it->getAuthor());
				eraseFileLine(currentPath, it->getTitle());
				eraseFileLine(currentPath, it->getFileName());
				eraseFileLine(currentPath, it->getDescription());
				eraseFileLine(currentPath, (char*)it->getRating());
				eraseFileLine(currentPath, it->getISBN());
				books.erase(it);
			}
		}
	}
}

void Library::displayAllInfo()
{
	for (auto it = books.begin(); it != books.end(); ++it)
	{
		std::cout << "Author: " << it->getAuthor();
		std::cout << "Title: " << it->getTitle();
		std::cout << "File with text: " << it->getFileName();
		std::cout << "Description: " << it->getDescription();
		std::cout << "Rating: " << it->getRating();
		std::cout << "ISBN: " << it->getISBN();
	}
}

void Library::printBook(Book book, int numberOfRows, const char punctuationMark) 
{
	std::string input;

	std::string sentinel = (char*)punctuationMark;

	std::string output;

	std::string path = book.getFileName();

	std::ifstream file(path, std::ios::ate);

	int endline = (numberOfRows > 0) ? numberOfRows : 1024;
	while (file >> output) {
		for (int i = 0; i < endline; ++i) {
			getline(file, output);
			std::cout << output << std::endl;
		}
	}

	file.close();
	return;
}

void Library::displaySorted(bool order, int by) 
{
	//haven't implemented ascending/descending feature
	switch (by)
	{
	case 1:
		bool swapped = true;
		while (swapped) {
			swapped = false;
			for (size_t i = 0; i < books.size() - 1; ++i) {
				if (strcmp(books[i].getTitle(), books[i + 1].getTitle()) < 0) {
					std::swap(books[i], books[i + 1]);
					swapped = true;
				}
			}
		}
		break;
	case 2:
		bool swapped = true;
		while (swapped) {
			swapped = false;
			for (size_t i = 0; i < books.size() - 1; ++i) {
				if (strcmp(books[i].getAuthor(), books[i + 1].getAuthor()) < 0) {
					std::swap(books[i], books[i + 1]);
					swapped = true;
				}
			}
		}
		break;
	case 3:
		bool swapped = true;
		while (swapped) {
			swapped = false;
			for (size_t i = 0; i < books.size() - 1; ++i) {
				if (books[i].getRating() < books[i + 1].getRating()) {
					std::swap(books[i], books[i + 1]);
					swapped = true;
				}
			}
		}
		break;
	default:
		std::cout << "Incorrect value.\n";
		return;
		break;
	}

	for (auto it = books.begin(); it != books.end(); ++it) 
	{
		std::cout << it->getTitle() << it->getAuthor() << it->getISBN() << std::endl;
	}
}

void Library::find(const char* title,
	const char* author,
	const char* ISBN,
	const char* description)
{
	for (auto it = books.begin(); it != books.end(); ++it) {
		if (strcmp(toUpperCase(title).c_str(), it->getTitle()))
		{
			printBook(*it);
		}
		else if (strcmp(toUpperCase(author).c_str(), it->getAuthor()))
		{
			printBook(*it);
		}
		else if (strcmp(toUpperCase(ISBN).c_str(), it->getISBN()))
		{
			printBook(*it);
		}
		else if (findSubstr(toUpperCase(description).c_str(), it->getDescription()))
		{
			printBook(*it);
		}
	}

	
}