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
    friend void reverse(IntArray&);
    friend void multiply(IntArray&, int);
    friend void negative(IntArray&);
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

IntArray::IntArray(const IntArray &copy)
{
    m_data = copy.m_data;
    m_len = copy.m_len;
}

IntArray::~IntArray()
{
    delete[] m_data;
}

void IntArray::set(int index, int value)
{
    m_data[index] = value;
}

void IntArray::print(void)
{
    for (int idx = 0; idx < m_len; ++idx)
        cout << *(m_data + idx) << ' ';
    cout << std::endl;
}

void reverse(IntArray& arr)
{
    int temp;
    int end = arr.m_len-1;

    for (int i = 0; i < arr.m_len/2; i++)
    {
        temp = arr.m_data[i];
        arr.m_data[i] = arr.m_data[end];
        arr.m_data[end] = temp;
        end--;
    }
}

void multiply(IntArray& arr, int number)
{
    for (int i=0; i<arr.m_len; i++){
        arr.m_data[i] *= number;
    }
}

void negative(IntArray& arr){
    for (int i=0; i<arr.m_len; i++){
        arr.m_data[i] *= -1;
    }
}


int main()
{
    IntArray a1{5, 0};
    for (int idx = 0; idx < 5; ++idx)
        a1.set(idx, 100 + idx * 50);
    cout << "a1:       ";
    a1.print();
    reverse(a1);
    cout << "reverse:  ";
    a1.print();
    multiply(a1, 3);
    cout << "multiply: ";
    a1.print();
    negative(a1);
    cout << "negative: ";
    a1.print();
    return 0;
}