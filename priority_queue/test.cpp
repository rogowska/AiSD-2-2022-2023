#include "BinaryHeap.h"

void test(BinaryHeap<int> heap){
std::cout <<"IsEmpty: "<< heap.IsEmpty() << std::endl;
heap.Enqueue(5);
std::cout <<"IsEmpty: "<< heap.IsEmpty() << std::endl;
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.Enqueue(6);
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.Enqueue(8);
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.Enqueue(3);
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.Enqueue(9);
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.Enqueue(2);
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.Enqueue(1);
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
std::cout << "Minimum dequeued: ";
heap.DequeueMin();
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
std::cout << "Minimum dequeued: ";
heap.DequeueMin();
heap.Print();
std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
heap.MakeNull();
std::cout <<"IsEmpty: "<< heap.IsEmpty() << std::endl;
}

int main(){
BinaryHeap<int> heap(10);
BinaryHeap<int> heap2(2);
test(heap);
std::cout<<std::endl;
test(heap2);
}