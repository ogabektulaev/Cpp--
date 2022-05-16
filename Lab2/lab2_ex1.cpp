#include<iostream>
#include<limits>
using namespace std;

int main() {
    int i;
    char str[20];
    cout << "Input a string: ";

    cin.getline(str, 20); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //maximum number of characters to ignore

    cout << str << endl;
    cout << "Input an integer number: ";
    cin >> i;
    cout << i << endl;
    cout << "Input an integer number: ";
    cin >> i;
    cout << i << endl;
    return 0;
}