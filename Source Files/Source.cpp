#include "../Header Files/CommandHandler.h"


// github: https://github.com/SunInTeo/Project1

/*
* Commands
* 1. sort books by criteria and print
*	-- prints in such order : <title>, <author>, <ISBN>
*	-- ascending or descending (user's choice) by criteria:
*		-- title/ author/ rating
* 2. find book by criteria
*	-- prints detailed info about a book by given title/ author/ ISBN/
*   or any part of a description
*	-- we don't care about lower-/upper- case letters
* 3. add a book
*	-- needs full information about a book
* 4. remove a book
*	-- removes book by title/ ISBN
*	-- asks if we want to remove the file where the book's text is stored
* 5. print book
*	-- shows the book's text
*	-- can be shown a page(number of rows)/ sentences(to a punctuation mark)
*/
int main(int argv, char** argc)
{
    std::string path;
    if (argv == 2)
    {
        path = argc[1];
    }
    else 
    {
        path = "dafult.txt";
    }
    
    CommandHandler::getInstance().startReading(path.c_str());

    return 0;
}