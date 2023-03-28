#ifndef SETASARRAY_H
#define SETASARRAY_H

#include <vector>
#include <iostream>
#include "Set.h"
#include "Visitor.h"
#include "Iterator.h"

class SetAsArray : public Set<int>
{
    std::vector<bool> array;

public:
    class Iter : public Iterator<int>
    {
        std::vector<bool> data;
        int universeSize;
        int index;

    public:
        Iter(std::vector<bool> array, int us)
        {
            int i = 0;
            data = array;
            universeSize = us;
            while (i < universeSize && data[i] == false)
            {
                i++;
            }
            index = i;
        }
        ~Iter() {}
        const int &operator*() { return index; }
        void operator++()
        {
            int i = index + 1;
            while (i < universeSize && data[i] == false)
            {
                i++;
            }
            index = i;

        };
        bool IsDone() const
        {
            int i = index + 1;
            while (i < universeSize && data[i] == false)
            {
                i++;
            }
            return (i == universeSize);

        }
    };

    SetAsArray(unsigned int n);

    void MakeNull(); // metody z containera
    bool IsFull() const { return (Count() == UniverseSize()); }
    void Insert(int element);
    bool IsMember(int element) const;
    void Withdraw(int element);
    void Display();

    // friend- funkcja uzyska prawo dostepu do prywatnych elementów danej klasy.
    friend SetAsArray operator+(
        SetAsArray const &, SetAsArray const &);
    friend SetAsArray operator-(
        SetAsArray const &, SetAsArray const &);
    friend SetAsArray operator*(
        SetAsArray const &, SetAsArray const &);
    friend bool operator==(
        SetAsArray const &, SetAsArray const &);
    friend bool operator<=(
        SetAsArray const &, SetAsArray const &);
    void Accept(Visitor<int> &visitor);

    Iter &NewIterator() { return *new Iter(array, universeSize); };
};

void SetAsArray::Accept(Visitor<int> &visitor)
{
    int i;
    visitor.VisitorReset();
    for (i = 0; i < universeSize && !visitor.IsDone(); i++)
    {
        if (array[i] == true)
        {
            visitor.Visit(i);
        }
    }
    std::cout << "Visitor ended a visit at index: " << i - 1 << std::endl;
}

void SetAsArray::MakeNull()
{
    count = 0;
    universeSize = 0;
}

bool SetAsArray::IsMember(int element) const
{
    return array[element];
}

void SetAsArray::Display()
{
    std::cout << "[ ";
    for (int i = 0; i < universeSize; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}

SetAsArray::SetAsArray(unsigned int n)
{
    array.resize(n);
    for (bool element : array)
    {
        element = false;
    }
    count = 0;
    universeSize = n;
}

void SetAsArray::Insert(int element)
{
    array[element] = true;
    count++;
}

void SetAsArray::Withdraw(int element)
{
    array[element] = false;
    count--;
}

SetAsArray operator+(SetAsArray const &s, SetAsArray const &t)
{
    if (s.universeSize == t.universeSize)
    {
        unsigned int size = t.universeSize;
        SetAsArray output_set(size);
        for (int i = 0; i < size; i++)
        {
            if (s.array[i] || t.array[i])
            {
                output_set.array[i] = true;
                output_set.count++;
            }
        }
        return output_set;
    }
}

SetAsArray operator*(SetAsArray const &s, SetAsArray const &t)
{
    if (s.universeSize == t.universeSize)
    {
        unsigned int size = t.universeSize;
        SetAsArray output_set(size);
        for (int i = 0; i < size; i++)
        {
            if (s.array[i] && t.array[i])
            {
                output_set.array[i] = true;
                output_set.count++;
            }
        }
        return output_set;
    }
}

SetAsArray operator-(SetAsArray const &s, SetAsArray const &t)
{
    if (s.universeSize == t.universeSize)
    {
        unsigned int size = t.universeSize;
        SetAsArray output_set(size);
        for (int i = 0; i < size; i++)
        {
            if (s.array[i] && !t.array[i])
            {
                output_set.array[i] = true;
                output_set.count++;
            }
        }
        return output_set;
    }
}

bool operator==(SetAsArray const &s, SetAsArray const &t)
{
    bool flag = false;
    if ((s.universeSize == t.universeSize) && (s.count == t.count))
    {
        int i = 0;
        while (s.array[i] == t.array[i] && i < s.universeSize)
        {
            i++;
        }
        // passed successfully through all elements
        if (s.universeSize == i)
        {
            flag = true;
        }
    }
    return flag;
}

bool operator<=(SetAsArray const &s, SetAsArray const &t)
{
    bool flag = false;
    if ((s.universeSize == t.universeSize) && (s.count <= t.count))
    {
        int i = 0;
        while ((!(s.array[i] && !t.array[i])) && i < t.universeSize)
        {
            i++;
        }
        // passed successfully through all elements
        if (s.universeSize == i)
        {
            flag = true;
        }
    }
    return flag;
}

#endif
