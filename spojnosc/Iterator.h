#pragma once

template <typename T>
class Iterator
{
public:
virtual ~Iterator (){;}
Iterator(){;}
virtual bool IsDone () = 0;
virtual T & operator * () = 0;
virtual void operator ++ () = 0;
};