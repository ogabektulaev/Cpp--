#include <iostream>
using namespace std;

// Function prototype (declaration)
int add(int, int);
int multiplication(int, int);

int main()
{
    int num1, num2, sum;
    cout << "Enters two numbers to add: " <<endl;
    cin >> num1 >> num2;
    // Function call
    sum = add(num1, num2);
    cout << num1 << " + " << num2 << " = " << sum << endl;
    //Function call
    cout << num1 << " * " << num2 << " = " << multiplication(num1, num2) << endl;
    return 0;
}

// Function definition
int add(int a, int b)
{
    int add;
    add = a + b;
    // Return statement
    return add;
}

//New Function definition
int multiplication(int a, int b){
    return a*b; //returns mulitiplication of two paramaters
}