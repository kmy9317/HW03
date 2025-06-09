#include <iostream>
#include <algorithm>

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
        if (currentSize == currentCapacity)
        {
            int newCapacity = currentCapacity + 5;
            resize(newCapacity);
        }

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
        if (newCapacity <= currentSize) return;
        currentCapacity = newCapacity;

        T* newData = new T[newCapacity];

        for (int i = 0; i < currentSize; ++i)
            newData[i] = data[i];

        if (data) delete[] data;
        data = newData;
    }

    void sortData()
    {
        sort(data, data + currentSize);
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
    SimpleVector<int> vec(1);

    // resize 동작 확인
    vec.push_back(10);
    vec.push_back(11);
    vec.push_back(14);
    vec.push_back(17);
    vec.push_back(14);
    vec.push_back(16);
    vec.push_back(13);

    // push_back 동작 확인
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << *(vec.data + i) << endl;
    }

    // pop_back 동작 확인
    vec.pop_back();
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << *(vec.data + i) << endl;
    }

    vec.sortData();

    // 정렬 확인
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << *(vec.data + i) << endl;
    }
}
