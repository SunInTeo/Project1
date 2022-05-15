#pragma once
#include <iostream>
#include <fstream>
#include <string>

/**
     * utilities class with functions used in multiple files in the project
     */

/**
          * makes a copy of a string to another
          * @param str a char* object
          * @return a copy of the char*
          */
char* makecopy(const char* str);
//https://stackoverflow.com/questions/26576714/deleting-specific-line-from-file
  /**
       * erases a line in a file
       * @param path the path to the file
       * @param eraseLine line to be erased
       * @return void
       */
void eraseFileLine(std::string path, std::string eraseLine);
/**
     * makes all the chars uppercase
     * @param str string 
     * @return string in all uppercase
     */
std::string toUpperCase(const std::string& str);
//https://stackoverflow.com/questions/29595934/c-find-substring-in-a-string-with-pointers
  /**
       * finds if given string is a substring og another
       * @param string the big string
       * @param substr the small one
       * @return nullptr if it is not a substring else the substring
       */
char* findSubstr(const char* string, const char* substr);