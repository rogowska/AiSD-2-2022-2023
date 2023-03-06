#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Container.h"

template <typename T>
class PriorityQueue : public Container{
public:
virtual void Enqueue (T element) = 0;virtual T FindMin () const = 0;
virtual T DequeueMin () = 0;
};

#endif