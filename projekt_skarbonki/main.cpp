#include <iostream>
#include "GraphAsMatrix.h"

int main()
{
    int n, j;

    std::cout << "podaj liczbe skarbonek: ";
    std::cin >> n;

    GraphAsMatrix graph(n, true);
    for (int i = 0; i < n; i++)
    {
        std::cin >> j;
        graph.AddEdge(i, j-1);
    }

    graph.DFS(graph.SelectVertex(0));
}