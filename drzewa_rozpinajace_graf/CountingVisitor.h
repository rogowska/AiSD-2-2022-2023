#ifndef COUNTINGVISITOR_H
#define COUNTINGVISITOR_H

#include "Visitor.h"

class CountingVisitor : public virtual Visitor<Vertex>
{
    int number;

public:
    CountingVisitor(): number(0){};
    void Visit(Vertex &element);
    bool IsDone() const { return false; }
    int GetNumber();
    void VisitorReset() {number=0;}
};

void CountingVisitor::Visit(Vertex &element)
{
    number++;
}

int CountingVisitor::GetNumber(){
    return number;
}
#endif