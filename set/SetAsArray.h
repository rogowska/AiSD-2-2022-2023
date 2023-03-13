#ifndef SETASARRAY_H
#define SETASARRAY_H

#include <vector>
#include "Set.h"

class SetAsArray : public Set<int>
{
    std::vector<bool> array;

public:
    SetAsArray(unsigned int n);
    void MakeNull(); // metody z containera
    bool IsFull() const { return (Count() == UniverseSize()); };
    void Insert(int element);
    bool IsMember(int element) const;
    void Withdraw(int element);

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

SetAsArray SetAsArray::operator+(SetAsArray const & s, SetAsArray const & t) {
    SetAsArray newArray = SetAsArray(s.UniverseSize());
    for(int i = 0; i<UniverseSize(); i++){
        if((s[i]==true) || (t[i]==true)){
            newArray[i] = true;
            newArray.count++;
        }
    }
    return newArray;
}

#endif
