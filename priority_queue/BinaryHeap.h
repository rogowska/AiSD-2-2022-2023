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
private:
    T FindParent(int index);
    int FindParentIndex(int index);
};

template <typename T>
void BinaryHeap<T>::Print() const
{
    for (int i = 0; i < count; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
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
int BinaryHeap<T>::FindParentIndex(int index){
    return (index - 1) / 2;
}

template <typename T>
T BinaryHeap<T>::FindParent(int index){
    int parent_index = FindParentIndex(index);
    return data[parent_index];
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
        T parent = FindParent(element_index);

        while (!(parent < element) && !(element_index == 0))
        {
            // swapping parent with element
            std::swap(data[FindParentIndex(element_index)], data[element_index]);
            
            // searching for new parent
            element_index = FindParentIndex(element_index);
            parent = FindParent(element_index);
        }
    }
}

template <typename T>
T BinaryHeap<T>::FindMin() const
{
    return data[0];
}

template <typename T>
T BinaryHeap<T>::DequeueMin()
{
    T root = data[0];
    if (count > 1)
    {
        T child1 = data[1];
        T child2 = data[2];
        int empty_index = 0;
        int child1_index = 1;
        int child2_index = 2;
        while ((child1_index != count - 1) && (child2_index != count - 1))
        {
            if (child1 < child2)
            {
                data[empty_index] = data[child1_index];
                empty_index = child1_index;
            }
            else
            {
                data[empty_index] = data[child2_index];
                empty_index = child2_index;
            }
            child1_index = 2 * empty_index + 1;
            child2_index = 2 * empty_index + 2;
            child1 = data[child1_index];
            child2 = data[child2_index];
        }
        if (child1_index == count - 1)
        {
            data[empty_index] = data[child1_index];
        }
        else
        {
            if (child2_index == count - 1)
            {
                if (child1 < child2)
                {
                    data[empty_index] = data[child1_index];
                    empty_index = child1_index;
                }
                else
                {
                    data[empty_index] = data[child2_index];
                    empty_index = child2_index;
                }
            }
        }
    }
    count--;
    return root;
}

#endif