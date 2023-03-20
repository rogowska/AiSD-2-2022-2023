#ifndef ODDVISITOR_H
#define ODDINGVISITOR_H

#include "Visitor.h"

template <typename T>
class AddingVisitor : public virtual Visitor<T>
{
    bool odd;

public:
    void Visit(T &element);
    bool IsDone() const { return false; }
    T GetSum();
};

#endif