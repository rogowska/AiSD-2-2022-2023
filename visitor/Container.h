#ifndef CONTAINER_H
#define CONTAINER_H

template<typename T>
class Container
{
protected:
    Container(){};

public:
    virtual unsigned int Count() const = 0;
    virtual bool IsEmpty() const { return Count() == 0; };
    virtual bool IsFull() const = 0;
    virtual void MakeNull() = 0;
    virtual void Accept(Visitor<T> &v) =0;
};

#endif