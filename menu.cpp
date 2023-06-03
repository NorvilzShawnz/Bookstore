#include "store.h"
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
void menuDisplay();
int main(){
    int a,b,c,d;
    Book storage;
    Store store;
    string search;
    char choice; // To navigate/choose through the menu
    char title[30];
    char author[20]; 
    double startMoney;
    double priceP; // cannot be negative
    char genre; // must be F , M , S, or C
    Genre type;
    std::cout<<"How much money is in the cash register?";
    std::cin >> startMoney;
    while(startMoney < 0){
        cout<<"\nNegative numbers aren't allowed please re-enter: ";
        cin >> startMoney;
    }
    store.setRegister(startMoney);
    menuDisplay();
    std::cin >> choice;
while ((choice != 'x') && (choice != 'X') && ((choice == 'a') || (choice == 'A') || (choice == 'f') || (choice == 'F') ||(choice == 's') || (choice == 'S') || (choice == 'd') || (choice == 'D') ||(choice == 'g') || (choice == 'G') ||(choice == 'm') || (choice == 'M'))){
        if ((choice == 'a') || (choice == 'A')){
            cout<< "Enter title: ";
            cin.ignore();
            cin.getline(title, 30);
            cout<< "Enter author: ";
            cin.getline(author, 20);
            cout<< "Enter genre:  ";
            cin >> genre;
            while ((genre != 'f') && (genre != 'F') && (genre != 'm') && (genre != 'M') && (genre != 's') && (genre != 'S') && (genre != 'c') && (genre != 'C')){
            cout<<"Invalid genre, please re-enter. (F, M , S, C)\n";
            cin >> genre;
          }
            cout << "Enter price: ";
            cin >> priceP;
            while(priceP < 0){
                cout<<"\nNegative numbers aren't allowed please re-enter: ";
                cin >> priceP;
            }
            if ((genre == 'F') || (genre == 'f')){type = FICTION;}
            if ((genre == 'M') || (genre == 'm')){type = MYSTERY;}
            if ((genre == 'S') || (genre == 's')){type = SCIFI;}
            if ((genre == 'C') || (genre == 'c')){type = COMPUTER;}
            storage.Set(title, author, type, priceP);
            storage.Display();
            cout<<"\n";
            store.addBook(storage);
            menuDisplay();
            cin >> choice;
        }
        if ((choice == 'f') || (choice == 'F')){
            cout<< "Enter a search string, A title, or an author: ";
            cin.ignore();
            getline(cin, search);
            store.findBook(search);
            cout<<endl;
            menuDisplay();
            cin >> choice;

            }
        if ((choice == 's') || (choice == 'S')){
            cout<< "Enter the books title: ";
            cin.ignore();
            getline(cin, search);
            store.sellBook(search);
            menuDisplay();
            cin >> choice;
        }        
        if ((choice == 'd') || (choice == 'D')){
            store.displayShelf();
            menuDisplay();
            cin >> choice;
        }        
        if ((choice == 'g') || (choice == 'G')){
            cout<<"\nPlease enter in the genre you would like to search: ";
            cin >> genre;
            while ((genre != 'f') && (genre != 'F') && (genre != 'm') && (genre != 'M') && (genre != 's') && (genre != 'S') && (genre != 'c') && (genre != 'C')){
            cout<<"Invalid genre, please re-enter. (F, M , S, C)\n";
            cin >> genre;
          }
            store.genreDisplay(genre);
            menuDisplay();
            cin >> choice;

        }        
        if ((choice == 'm') || (choice == 'M')){
            cout<<"\n";
            menuDisplay();
            cin >> choice;
        }
}
    if (toupper(choice) == 'X'){
        cout << "Final Cash Register Amount: " << setprecision(2) << fixed << store.getMoneys() << "\nBye!\n";

    }
    }

void menuDisplay(){
    cout <<"A:   Add a book to inventory\n"
               "F:   Find a book from inventory\n"
               "S:   Sell a book\n"
               "D:   Display the inventory list\n"
               "G:   Genre summary\n" 
               "M:   Show this Menu\n" 
               "X:   Exit the program \n";
}