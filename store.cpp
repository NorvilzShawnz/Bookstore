#include "store.h"
#include <iostream>
#include <string>
#include <iomanip>

double Store::getMoneys(){
    return cashRegister;
}
void Store::findBook(std::string s){
    std::string newSearch;
    newSearch = s;
    bool found = false;
    for (int i = 0; i < startSpace; i++){
        if (newSearch == array[i].GetTitle()){
            array[i].Display();
            found = true;
        }
        else if (newSearch != array[i].GetTitle()){
            if (newSearch == array[i].GetAuthor()){
            array[i].Display();
            std::cout<< "\n";
            found = true;
        }
        }

    }
    if (found == false){
        std::cout<<"\nSorry! We do not have that book.\n";    
    }

}
void Store::displayShelf(){
    for (int i = 0; i < inventory; i++){
        array[i].Display();
        std::cout<<"\n";
    }
}

void Store::addBook(Book& b){
    array[index] = b;
    ++index;
    if (index >= startSpace){
        Book* newSpace = new Book[startSpace*2];
        for (int i = 0; i < startSpace; i++){
             newSpace[i] = array[i];
        }
        startSpace *= 2;
    }
    inventory++;
}

void Store::sellBook(std::string t){
    double income;
    int sold = 1;
    std::string findBook;
    findBook = t;
    for (int i = 0; i < startSpace; i++){
        if (array[i].GetTitle() == findBook){
            income = array[i].GetPrice();
            for (int j = i; j < startSpace ;j++){
                array[j] = array[j+1];
            }
            startSpace--;
            inventory--;
            cashRegister = cashRegister + income;
            sold--;
            std::cout << std::setprecision(2) << std::fixed;
            std::cout<<"\nSold! , for $"<<  income << "\n\n";
        }
    }
    
    if(sold != 0){std::cout<<"\nSorry! There is no such book with that title, returning to menu\n";}
    
}
void Store::genreDisplay(char g){
    int checker = 0;
    double total = 0;
    if (toupper(g) == 'F'){
        for (int i  = 0; i < index; i++){
            if (array[i].GetGenre() == FICTION){
                array[i].Display();
                std::cout<<"\n";
                checker++;
                total += array[i].GetPrice();
            }
        }
        if(checker == 0){
            std::cout<<"Sorry, there are currently no books under this genre \n";
        }
        else{
            std::cout<<"The number of books in  this genre are: " << checker << "\nand the total price for all of these books is: $" << total << "\n";
        }
    }
    else if (toupper(g) == 'M'){
        for (int i  = 0; i < index; i++){
            if (array[i].GetGenre() == MYSTERY){
                array[i].Display();
                std::cout<<"\n";
                checker++;
                total += array[i].GetPrice();
            }
        }
        if(checker == 0){
            std::cout<<"Sorry, there are currently no books under this genre \n";
        }
        else{
            std::cout<<"The number of books in  this genre are: " << checker << "\nand the total price for all of these books is: $" << total << "\n";
        }
    }
    else if (toupper(g) == 'S'){
        for (int i  = 0; i < index; i++){
            if (array[i].GetGenre() == SCIFI){
                array[i].Display();
                std::cout<<"\n";
                checker++;
                total += array[i].GetPrice();
            }
        }
        if(checker == 0){
            std::cout<<"Sorry, there are currently no books under this genre \n";
        }
        else{
            std::cout<<"The number of books in  this genre are: " << checker << "\nand the total price for all of these books is: $" << total << "\n\n";
        }
    }
    else if (toupper(g) == 'C'){
        for (int i  = 0; i < index; i++){
            if (array[i].GetGenre() == COMPUTER){
                array[i].Display();
                std::cout<<"\n";
                checker++;
                total += array[i].GetPrice();
            }
        }
        if(checker == 0){
            std::cout<<"Sorry, there are currently no books under this genre \n";
        }
        else{
            std::cout<<"The number of books in  this genre are: " << checker << "\nand the total price for all of these books is: $" << total << "\n";
        }
    }
    
}

Store::Store(){
cashRegister = 0.0;
index = 0;

}
void Store::setRegister(double x){
    cashRegister = x;
}
Store:: ~Store(){
    delete [] array;
}

