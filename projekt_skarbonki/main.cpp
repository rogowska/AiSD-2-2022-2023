#include <iostream>
#include "GraphAsMatrix.h"

int main()
{
    int n;

    std::cout << "podaj liczbe skarbonek: ";
    std::cin >> n;

    GraphAsMatrix graph(n, true);
    for (int i = 0; i < n; i++)
    {
        std::cin >> n;
        graph.AddEdge(i+1, n);
    }

    graph.DFS(graph.SelectVertex(0));
}