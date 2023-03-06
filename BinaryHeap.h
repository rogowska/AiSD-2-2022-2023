#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <vector>
#include <iostream>
#include "PriorityQueue.h"

template <typename T>
class BinaryHeap : public PriorityQueue<T>
{
protected:
    int count;
    std::vector<T> data;

public:
    BinaryHeap(unsigned int n);
    ~BinaryHeap() { ; };
    void MakeNull();
    void Enqueue(T element);
    T FindMin() const;
    T DequeueMin();
    bool IsEmpty() const;
    bool IsFull() const;
    unsigned int Count() const { return count; }
    void Print() const;
};

template <typename T>
void BinaryHeap<T>::Print() const
{
    for (T element : data)
    {
        std::cout << element << " ";
    }
}

template <typename T>
BinaryHeap<T>::BinaryHeap(unsigned int n)
{
    count = 0;
    std::vector<T> data(n);
}

template <typename T>
void BinaryHeap<T>::MakeNull()
{
    count = 0;
}

template <typename T>
bool BinaryHeap<T>::IsEmpty() const
{
    {
        return Count() == 0;
    }
}

template <typename T>
bool BinaryHeap<T>::IsFull() const
{
    {
        return Count() == data.max_size();
    }
}

template <typename T>
void BinaryHeap<T>::Enqueue(T element)
{
    if (IsFull())
    {
        data.resize(count);
    }

    data.push_back(element);
    count++;

    if (count > 1)
    {
        int element_index = count - 1;
        int parent_index = (element_index - 1) / 2;
        T parent = data[parent_index];

        while (!(parent < element) || (element_index == 0))
        {
            // swapping parent with element
            data[parent_index] = data[element_index];
            data[element_index] = parent;
            // searching for new parent
            element_index = parent_index;
            parent_index = (parent_index - 1) / 2;
            parent = data[parent_index];
        }
    }
}

template <typename T>
T BinaryHeap<T>::FindMin() const
{
    return data[0];
}

template <typename T>
T BinaryHeap<T>::DequeueMin() {}

#endif