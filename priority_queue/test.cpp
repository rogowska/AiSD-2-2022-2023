#include "BinaryHeap.h"

int main(){
BinaryHeap<int> heap(10);
heap.Enqueue(4);
heap.Enqueue(5);
heap.Enqueue(10);
heap.Enqueue(9);
heap.Enqueue(1);
heap.Print();

}