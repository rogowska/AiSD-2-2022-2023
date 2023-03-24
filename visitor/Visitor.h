#ifndef VISITOR_H
#define VISITOR_H

template <typename T>
class Visitor
{
public:
virtual void Visit (T& element) = 0;
virtual bool IsDone () const{ return false; }
virtual void VisitorReset() = 0;
};

#endif