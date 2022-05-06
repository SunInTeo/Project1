#pragma once

#include <iostream>
#include <cstring>
#include <cassert>

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

	static char* makecopy(const char* str);

public:
	Book();
	Book(const char* author, const char* title, 
			const char* fileName, const char* description, 
			short rating, const char* ISBN );
	Book(const Book& other);
	Book& operator = (const Book& other);
	~Book();
	
	// <title>, <author>, <ISBN>
	// we need that for the first command 
	void displaySorted();

	// all the info
	// for the find command
	void displayFind();

	// for the last command
	// working on implementation
	// still need to think of the arguments that the function will need in order to work
	void display();

	// still not sure whether the setters will be used 
	// will remove the if unnecessary
	void setAuthor(const char* author);
	void setTitle(const char* title);
	void setFileName(const char* fileName);
	void setDescription(const char* description);
	void setRating(short rating);
	void setISBN(const char* ISBN);
};
