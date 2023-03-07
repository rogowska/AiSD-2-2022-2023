#include "BinaryHeap.h"

int main(){
BinaryHeap<int> heap(10);
std::cout << heap.IsEmpty() << std::endl;
heap.Enqueue(5);
std::cout << heap.IsEmpty() << std::endl;
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.Enqueue(6);
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.Enqueue(8);
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.Enqueue(3);
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.Enqueue(9);
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.Enqueue(2);
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.Enqueue(1);
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.DequeueMin();
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.DequeueMin();
heap.Print();
std::cout << heap.FindMin() << std::endl;
heap.MakeNull();
std::cout << heap.IsEmpty() << std::endl;
}