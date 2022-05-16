#include <iostream>
using namespace std;
int main()
{
    int country, city;  //declaring variables

    cout << "Select a country" << endl;
    cout << "(1)Korea, (2)Japan, (3)Uzbekistan" << endl;  
    cin >> country;  //storing input to the variable
    switch (country)  
    {
    case 1:  //case statement
        cout << "Select a city: (1)Seoul, (2)Incheon" << endl;
        cin >> city;
        if (city == 1)
            cout << "You select Seoul Korea." << endl;
        else
            cout << "You select Incheon Korea." << endl;
        break;
    case 2:
        cout << "Select a city: (1)Osaka, (2)Tokyo" << endl;
        cin >> city;
        if (city == 1)
            cout << "You select Osaka Japan." << endl;
        else
            cout << "You select Tokyo Japan." << endl;
        break;
    case 3:   //new case statement
        cout << "Select a city: (1) Tashkent, (2) Karshi" << endl;  
        cin >> city;
        if (city == 1)
            cout << "You selected Tashkent. " << endl;
        else if(city == 2)
            cout << "You selected Karshi. " << endl;
        else
            cout << "Your input is wrong. Please enter 1 or 2. \n" << endl;
    default:
        cout << "Please select 1 or 2 for country." << endl;
    }
    return 0;
}