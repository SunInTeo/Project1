#pragma once

#include <cstring>
#include <cassert>
#include "Utils.h"

/**
	 * class defining a Book
	 */
class Book
{
private:
	char* author = nullptr;
	char* title = nullptr;
	char fileName[50]{}; //book's text is stored in that file
	char* description = nullptr;
	short rating;
	char* ISBN = nullptr; // TO DO: Make a class/structure ISBN-13 for validating and etc.

	void deallocate();
	void copy(const Book& other);

public:
	Book();
	Book(const char* author, const char* title, 
			const char* fileName, const char* description, 
			short rating, const char* ISBN );
	Book(const Book& other);
	Book& operator = (const Book& other);
	~Book();

	// still not sure whether the setters will be used 
	// will remove the if unnecessary
	void setAuthor(const char* author);
	void setTitle(const char* title);
	void setFileName(const char* fileName);
	void setDescription(const char* description);
	void setRating(short rating);
	void setISBN(const char* ISBN);

	// same applies for the getters
	// we may need to get the fileName where the text of the book is stored
	// in a higher class
	char* getAuthor() const;
	char* getTitle() const;
	char* getFileName() const;
	// opens the file where the text of the book is stored
	// and reads it and returns the content 
	char* getBookText() const;
	char* getDescription() const; 
	short getRating() const;
	char* getISBN() const;
};
