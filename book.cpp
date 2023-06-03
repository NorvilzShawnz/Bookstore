#include <iostream>
#include <iomanip>
#include "book.h"
#include <string>
// int main(){
//     Book a,b;
//     a.Set("Suck my ass" , "Hissabee" , FICTION, 12.99);
//     a.Display();
// }

Book::Book(){
    title[0] = '\0';
    author[0] = '\0';
    type = MYSTERY;
    price = 0;

}

double Book::GetPrice() const{
    return price;
};

void Book::Set(const char* t, const char* a, Genre g, double p){
    strcpy(title, t );
    strcpy(author, a);
    type = g;
    price = p;
}

const char* Book::GetTitle() const {
    return title;
}
const char* Book::GetAuthor() const{
    return author;
}

Genre Book::GetGenre() const{
    return type;
}
void Book::Display() const {
    std::string genreSimplify;
    if (type == FICTION){
        genreSimplify = "FICTION";
    }
    else if (type == MYSTERY){
        genreSimplify = "MYSTERY";
    }
    else if (type == COMPUTER){
        genreSimplify = "COMPUTER";
    }
    else if (type == SCIFI){
        genreSimplify = "SCIFI";
    }
    std::cout<< title << "\t \t" << author << "\t \t" << genreSimplify << "\t \t" <<std::setprecision(2) << std::fixed << price;
}
