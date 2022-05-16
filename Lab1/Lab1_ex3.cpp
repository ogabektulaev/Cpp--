#include <iostream>
using namespace std;

int main()
{   
    //declaring variablees
    int x;  
    int min = INT_MAX;  //assigning maximum int number
    int max = 0;

    for (int i = 0; i < 10; i++)  //this loop works 10 times
    {
        cout << "Type an integer number: ";
        cin >> x;
        if (x > max){  //checking max
            max = x;
        }
        
        if (x < min){  //checking min
            min = x;
        }
    }
    cout << "The maximum number you typed is " << max << endl;
    cout << "The minimum number you typed is " << min << endl;
    return 0;
}