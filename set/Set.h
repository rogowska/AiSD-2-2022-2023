#ifndef SET_H
#define SET_H

#include "Container.h"

template <typename T>
class Set : public virtual Container
{
protected:
 int count;
 int universeSize;
public:
 Set (int n) : universeSize (n) {}
 int UniverseSize() const {return universeSize;}
 int Count() const {return count;};
 virtual void Insert (T element)=0;
 virtual bool IsMember (T element) const=0;
 virtual void Withdraw (T element)=0;}; 

 #endif