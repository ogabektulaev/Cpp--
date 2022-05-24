#include <iostream>
#include <string>
using namespace std;


class Book{  //Base class 
public:
    string m_title;
    string m_ISBN;
    double m_price;
    
    Book(string title, string ISBN, double price) : m_title(title), m_ISBN(ISBN), m_price(price) {}

    void ShowBookInfo(){
        cout << "Title: " << m_title << endl;
        cout << "ISBN: " << m_ISBN << endl;
        cout << "Price(USD): " << m_price << endl;
    }

};

class EBook : public Book{  //Derived class 
public:
    string m_DRMKey;
    string m_Format;

    EBook(string title, string ISBN, double price, string DRMKey, string format="Kindle") : Book(title, ISBN, price), m_DRMKey(DRMKey), m_Format(format) {}

    void ShowEBookInfo(){
        cout << "Title: " << m_title << endl;
        cout << "ISBN: " << m_ISBN << endl;
        cout << "Price(USD): " << m_price << endl;
        cout << "DRMKey: " << m_DRMKey << endl;
        cout << "Format: " << m_Format << endl << endl << endl;
    }
};

class EBookLibrary {
public:
    EBook* lib[100]; //pointer array for storing Ebooks 
    int counter = 0;

    void AddBook(EBook *book) {
        lib[counter] = book;
        counter++;
    }

    void ShowAllBooks() {
        for(int i=0; i<counter; i++)
            lib[i] -> ShowEBookInfo();
    }
};


int main() {
    EBookLibrary elib;
    elib.AddBook(new EBook{ "Book1", "1234567890", 10.99, "AAAAAA", "ePub" }); //new - allocates dynamic memory and returns pointer
    elib.AddBook(new EBook{ "Book2", "2345678901", 20.99, "BBBBBB" });
    elib.AddBook(new EBook{ "Book3", "3456789012", 30.99, "CCCCCC", "ePub"});
    elib.AddBook(new EBook{ "Book4", "4567890123", 40.99, "DDDDDD" });
    elib.ShowAllBooks();

    return 0;
}
