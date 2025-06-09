#include <iostream>

using namespace std;

template<typename T>
class SimpleVector
{
public:
    SimpleVector()
    {
        data = new T[10];
        currentCapacity = 10;
    }
    SimpleVector(int capacity)
    {
        data = new T[capacity];
        currentCapacity = capacity;
    }

    ~SimpleVector()
    {
        if (data) delete[] data;
    }

    void push_back(const T& value)
    {
        if (currentSize == currentCapacity) return;

        data[currentSize] = value;
        currentSize++;
    }

    void pop_back()
    {
        if (currentSize == 0) return;
        currentSize--;
    }

    int size()
    {
        return currentSize;
    }

    int capacity()
    {
        return currentCapacity;
    }

    void resize(int newCapacity)
    {

    }

public:
    T* data;
    // 원소의 갯수
    int currentSize = 0;
    // 배열 크기
    int currentCapacity = 0;
};

int main()
{
    SimpleVector<int> vec;


    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(14);

    for (int i = 0; i < vec.size(); ++i)
    {
        cout << *(vec.data + i) << endl;
    }

    vec.pop_back();
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << *(vec.data + i) << endl;
    }
}
