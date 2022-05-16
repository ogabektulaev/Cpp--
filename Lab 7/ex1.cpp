#include <iostream>
using namespace std;
class IntArray
{
private:
    int *m_data;
    int m_len;

public:
    IntArray(int = 0, int = 0);
    IntArray(const IntArray &copy);
    ~IntArray();
    void print(void);
    void set(int, int);
};

IntArray::IntArray(int size, int init)
{
    if (size <= 0)
    {
        m_data = nullptr;
        m_len = 0;
    }
    else
    {
        m_data = new int[size];
        m_len = size;
        for (int idx = 0; idx < m_len; ++idx)
            *(m_data + idx) = init;
    }
}

IntArray::IntArray(const IntArray &copy){
    m_data = copy.m_data;
    m_len = copy.m_len;
}

IntArray::~IntArray()
{
    delete[] m_data;
}

void IntArray::set(int index, int value){
    m_data[index] = value;
}

void IntArray::print(void)
{
    for (int idx = 0; idx < m_len; ++idx)
        cout << *(m_data + idx) << ' ';
    cout << std::endl;
}

int main()
{
    cout << "a1: ";
    IntArray a1{10, 100};
    a1.print();
    cout << "a2: ";
    IntArray a2{a1};
    a2.set(3, 999);
    a2.set(9, 123);
    a2.print();
    return 0;
}