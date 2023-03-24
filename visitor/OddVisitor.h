#ifndef ODDVISITOR_H
#define ODDINGVISITOR_H

#include "Visitor.h"

template <typename T>
class OddVisitor : public virtual Visitor<T>
{
    bool isOdd;

public:
    OddVisitor(): isOdd(false){};
    void Visit(int &element)
    {
        if (element % 2 == 1)
            isOdd = true;
    }
    bool IsDone() const { return isOdd; }
    bool IsOdd() { return isOdd; }
};

#endif