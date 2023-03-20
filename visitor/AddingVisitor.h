#ifndef ADDINGVISITOR_H
#define ADDINGVISITOR_H

#include "Visitor.h"

template <typename T>
class AddingVisitor : public virtual Visitor<T>
{
    T sum;

public:
    void Visit(T &element);
    bool IsDone() const { return false; }
    T GetSum();
};

template <typename T>
void AddingVisitor<T>::Visit(T &element)
{
    sum = +element;
}

template <typename T>
T AddingVisitor<T>::GetSum(){
    return sum;
}
#endif