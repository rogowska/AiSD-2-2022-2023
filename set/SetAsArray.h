#ifndef SETASARRAY_H
#define SETASARRAY_H

#include <vector>
#include <iostream>
#include "Set.h"

class SetAsArray : public Set<int>
{
    std::vector<bool> array;

public:
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
    // void Accept (Visitor&) const{};
    // o metodzie Accept powiemy na następnych zajęciach
};

void SetAsArray::MakeNull(){}


bool SetAsArray::IsMember(int element) const {
   return array[element];
}

void SetAsArray::Display()
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "[ ";
        std::cout << array[i] << " " << std::endl;
        std::cout << "]";
    }
}

SetAsArray::SetAsArray(unsigned int n)
{
    std::vector<bool> array(n);
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
        for (int i; i < size; i++)
        {
            if (s.array[i] || t.array[i])
            {
                output_set.array[i] = true;
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
        for (int i; i < size; i++)
        {
            if (s.array[i] && t.array[i])
            {
                output_set.array[i] = true;
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
        for (int i; i < size; i++)
        {
            if (s.array[i] && !t.array[i])
            {
                output_set.array[i] = true;
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
        while (s.array[i] == t.array[i])
        {
            i++;
        }
        // passed successfully through all elements
        if (s.count == (i + 1))
        {
            flag = true;
        }
    }
    else
    {
        return flag;
    }
}

bool operator<=(SetAsArray const &s, SetAsArray const &t)
{
    bool flag = false;
    if ((s.universeSize == t.universeSize) && (s.count == t.count))
    {
        int i = 0;
        while (!(s.array[i] || !t.array[i]))
        {
            i++;
        }
        // passed successfully through all elements
        if (s.count == (i + 1))
        {
            flag = true;
        }
    }
    else
    {
        return flag;
    }
}

#endif
