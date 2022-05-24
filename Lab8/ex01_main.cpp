#include <iostream>
#include <string>
using namespace std;

class Fruit{  //Base class
public:
    string m_name;
    string m_color;

    string getName(){
        return m_name;
    }
    string getColor(){
        return m_color;
    }
};

class Apple : public Fruit{  //Derived class
public:
    Apple(string color){
        m_color = color;
        m_name = "apple";
    }
};

class Banana : public Fruit{ //Derived class 
public:
    Banana(){
        m_color = "yellow";
        m_name = "banana";
    }
};

int main() {
    Apple a{ "red" };
    Banana b;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;  
}
