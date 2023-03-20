#ifndef ADDINGVISITOR_H
#define ADDINGVISITOR_H

#include "Visitor.h"

template <typename T>
class AddingVisitor : public Visitor<T>
{
    T sum;

public:
    void Visit(T &element);
    bool IsDone() const { return false; }
};

void AddingVisitor<T>::Visit(T &element)
{
    sum = +element;
}

#endif