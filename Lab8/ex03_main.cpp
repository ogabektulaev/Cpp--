#include <iostream>
#include <string>
using namespace std;


class Book{
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

class EBook : public Book{
public:
    string m_DRMKey;
    string m_Format;

    EBook(string title, string ISBN, double price, string DRMKey) : Book(title, ISBN, price), m_DRMKey(DRMKey) { m_Format = "Kindle"; }

    void ShowEBookInfo(){
        cout << "Title: " << m_title << endl;
        cout << "ISBN: " << m_ISBN << endl;
        cout << "Price(USD): " << m_price << endl;
        cout << "DRMKey: " << m_DRMKey << endl;
        cout << "Format: " << m_Format << endl;
    }

};

int main() {
    Book book("Modern C++ Programming Cookbook", "1800208987", 49.99);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Modern C++ Programming Cookbook(ebook)", "1800208987", 34.99, "dkb34x!@*~");
    ebook.ShowEBookInfo();

    return 0;
}
