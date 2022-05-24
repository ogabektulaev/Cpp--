#include <iostream>
using namespace std;

class Point3d{
private:
    double m_x;
    double m_y;
    double m_z;

public:
    Point3d(double x = 0, double y = 0, double z = 0) : m_x(x), m_y(y), m_z(z){};

    void print(){
        cout << "Point3d(" << m_x <<", "<< m_y <<", " << m_z <<")"<<endl;
    }
};

int main(){
    Point3d p1{};
    Point3d p2 {3.0, 4.0, 5.0};

    p1.print();
    p2.print();
    
    return 0;
}