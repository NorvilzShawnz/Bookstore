# Bookstore


Programming Assignment #4
Due: Thurs, March 9
Objective
Upon completion of this program, you should gain experience in working with dynamic arrays of objects, as well as working with two classes in a "has-a" relationship. This will also give some extra practice with array and c-string usage.
Task
You will be writing classes that implement an inventory list simulation for a bookstore.  The list will be a dynamic array of Book objects, each of which stores several pieces of information about a book.  You will need to finish the writing of two classes:  Book and Store.  The full header file for the Book class has been provided in a file called book.h.  You can get a copy of it here.
Program Details and Requirements
1) Using the Book class declaration, write the book.cpp file and define all of the member functions that are declared in the file book.h.   (Do not change book.h in any way.  Just take the existing class interface and fill in the function definitions).  Notice that there are only four genres of books in this class:  FICTION, MYSTERY, SCIFI, and COMPUTER.  The expected functions behaviors are described in the comments of this header file.
 

2) Write a class called Store (filenames are store.h and store.cpp).  A Store object should contain at least the following information:  the amount of money in the store cash register and a book inventory list.  There is no size limit to the inventory list, so it should be implemented with a dynamically allocated array.  (This means you'll need an array of Book objects).  You can add any public or private functions into the Store class that you feel are helpful.  In addition to the Store class itself, you will also create a menu program to manage the inventory of books.  However, the Store class will be able to do much of the work, as the Store member functions will be the interface between the menu program and the internally stored data (cash register and list of books).

Rules for the Store class:

All member data of class Store must be private
There should be no cin statements inside the Store class member functions.  To ensure the class is more versatile, any user input (i.e. keyboard) described in the menu program below should be done in the menu program itself.  Design the Store class interface so that any items of information from outside the class are received through parameters of the public member functions.
The list of Books must be implemented with a dynamically allocated array.  There should never be more than 5 unused slots in this array (i.e. the number of allocated spaces may be at most 5 larger than the number of slots that are actually filled with real data).  This means that you will need to ensure that the array allocation expands or shrinks at appropriate times.  Whenever the array is resized, print a message (for testing purposes) that states that the array is being resized, and what the new size is.  Example:  "** Array being resized to 10 allocated slots".
Since dynamic allocation is being used inside the Store class, an appropriate destructor must be defined, to clean up memory. The class must not allow any memory leaks
You must use the const qualifier in all appropriate places (const member functions, const parameters, const returns, where appropriate).
3) Write a main program (filename menu.cpp) that creates a single Store object and then implements a menu interface to allow interaction with the object.  The program should begin by asking the user to input the starting amount of money in the store's cash register (as a double).  This should be stored in the Store object.  Your main program should implement the following menu loop (any single letter options should work on both lower and upper case inputs):

  A:   Add a book to inventory 
  F:   Find a book from inventory 
  S:   Sell a book 
  D:   Display the inventory list 
  G:   Genre summary 
  M:   Show this Menu 
  X:   eXit the program 
Behavior of menu selections:

Always ask for user input in the order specified.  Remember, all user inputs described in the menu options below should be done by the menu program (not inside the Store class). Such input can then be sent into the Store class -- the Store class member functions should do most of the actual work, since they will have access to the list of books and the cash register. For all user inputs (keyboard), assume the following:

a book title and author will always be input as strings (c-style strings), of maximum lengths 30 and 20, respectively.  You may assume that the user will not enter more characters than the stated limits for these inputs.
when asking for the genre, user entry should always be a single character.  The correct values are F, M, S, and C - for fiction, mystery, sci-fi, and computer, respectively.  Uppercase and lowercase inputs should both be accepted.  Whenever the user enters any other character for the genre, this is an error -- print an error message and prompt the user to enter the data again (Example error message: "Invalid genre entry.  Please re-enter: ").
user input of the price should be a positive double.  You may assume that the user will enter a double.  Whenever the user enters a number that is not positive, it is considered an error -- so an error message should be printed and the user should be prompted to re-enter the price.  (Example: "Must enter a positive price.  Please re-enter: ").
User input of menu options are letters, and both upper and lower case entries should be allowed.
A:  This menu option should allow the adding of a book to the inventory list.  The user will need to type in the book's information.  Prompt and allow the user to enter the information in the following order:   title, author, genre, price.  The information should be sent into the Store object and stored in the list of books.
F:  This option should allow the user to search for a book in the inventory list by title or by author.  When this option is selected, ask the user to enter a search string (may assume user entry will be a string 30 characters or less).  If the search string matches a book title, display the information for that book (output format is described in the Display function of the Book class).  If the search string matches an author in the list, display the information for all books by that author.  If no matching books are found, display an appropriate message informing the user.

S:  This option should allow a sale to be made.  When this option is selected, ask the user to type in the title of the book (you may assume that book titles in the list will be unique).  Remove this book from the inventory list, and since it is being purchased, add the purchase price into the store's cash register.  If there is no such title, inform the user and return to the menu.

D:  This option should simply display the entire inventory list, one line per book, in an organized manner (like a table).  Each line should contain one book's information, as described in the book.h file.  Also, display the total number of books in the inventory list, as well as the current amount of money in the store cash register.

G:  This option should list the inventory contents for one specific genre.  When this option is selected, ask the user to input a genre.  For the category selected, print out the contents of the inventory list, as in the Display option, but for the books matching the selected genre only.  (e.g. list all of the Mystery books).  After this, also display the total quantity, as well as the total cost (the sum of the prices), of the books in this genre.

M:  Re-display the menu.
X:  Exit the menu program.  Upon exiting, print out the final amount of money in the store cash register.
 

5) General Requirements:

All class member data must be private
ALL string usages in this assignment are to be implemented with C-style strings (i.e. null-terminated character arrays). You may NOT use the C++ string class library. A large point of this assignment is to do your own dynamic memory allocation and management.
An invalid menu selection should produce an appropriate output message to the user, like "Not a valid option, choose again."
For all of these options, any output to the screen should be user-friendly.  By this, assume that the user of the program has never seen it before.  All output should clearly indicate what information is being presented, and the user should always be told what is expected in terms of input.
Adhere to the good programming practices discussed in class.  (No global variables, other than constants or enumerations.  Don't #include .cpp files. Document your code. etc).
You may use the following libraries:  iostream, iomanip, cstring, cctype
Do not use any C++11-only features/libraries
All monetary output to the screen should be in dollars and cents notation, with the $.  (Example:   $ 20.50).   Hint:  For printing out money values in dollars and cents, you'll need to print out to two decimal places.  You can use the stream manipulators setprecision and fixed (from the iomanip library) for this. The following is an example that illustrates the use of these stream manipulators.
 double amount = 34.6751 
 cout << setprecision(2) << fixed;	// set manipulators 
 cout << amount; 			// print the value
      // x will now print to two decimal places:  34.68 
