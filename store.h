#include "book.h"
#include <string>
class Store 
{
public:
Store();
~Store();
void setRegister(double x);
void addBook(Book& b);
void findBook(std::string s);
void sellBook(std::string t);
void displayShelf();
void genreDisplay(char g);
double getMoneys();


private:
char title[30];
char author[30];
Genre type;
double price;
int index;
int startSpace = 2;
int inventory = 0;

double cashRegister;
Book *array = new Book[startSpace];
};