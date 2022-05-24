#include <iostream>
#include <string>
using namespace std;

class Fruit{
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

class Apple : public Fruit{
public:
    Apple(string color){
        m_color = color;
        m_name = "apple";
    }
};

class Banana : public Fruit{
public:
    Banana(){
        m_color = "yellow";
        m_name = "banana";
    }
};

class RedBanana : public Banana{
public:
    RedBanana(){
        m_color = "red";
        m_name = "red banana";
    }
};

int main() {
    Apple a{ "red" };
    Banana b;
    RedBanana c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
