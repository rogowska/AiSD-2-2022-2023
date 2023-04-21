#include "GraphAsMatrix.h"
#include <iostream>

int main()
{
    // Utwórz graf skierowany złożony z 10 wierzchołków
    GraphAsMatrix graph(20, true);

    // Wypisz, ile jest wierzchołków
    std::cout << "Number of vertices: " << graph.NumberOfVertices() << std::endl;

    // Wypisz, ile jest krawędzi
    std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl;

    Vertex *v = graph.SelectVertex(2);

    // Wypisz unikalny numer v
    std::cout << "V number: " << v->Number() << std::endl;

    // Nadaj v wagę unikalnyNumer*uniklanyNumer
    // Wypisz wagę v
    v->weight = v->Number() * v->Number();
    std::cout << "V weight: " << v->weight << std::endl;

    graph.AddEdge(1, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(9, 9);

    // Wypisz, ile jest wierzchołków
    std::cout << "Number of vertices: " << graph.NumberOfVertices() << std::endl;

    // Wypisz, ile jest krawędzi
    std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl;

    // Wypisz, czy istnieje krawędź (1,1)
    // Wypisz, czy istnieje krawędź (1,2)
    // Wypisz, czy istnieje krawędź (2,1)
    std::cout << "If edge (1,1) exists: " << graph.IsEdge(1, 1) << std::endl;
    std::cout << "If edge (1,2) exists: " << graph.IsEdge(1, 2) << std::endl;
    std::cout << "If edge (2,1) exists: " << graph.IsEdge(2, 1) << std::endl;

    Edge *e = graph.SelectEdge(1, 2);
            
    //Wypisz V0 dla e
    //Wypisz V1 dla e
    std::cout<<"V0 of e: "<<e->V0()<<std::endl;
    std::cout<<"V1 of e: "<<e->V1()<<std::endl;

    //Wypisz sąsiada(V0) dla e // test metody Mate
    //Wypisz sąsiada(V1) dla e // test metody Mate
    std::cout<<"Neighbor of V0 for e: "<<e->Mate(e->V0())<<std::endl; 
    std::cout<<"Neighbor of V1 for e: "<<e->Mate(e->V1())<<std::endl;           
                            
    //Nadaj krawędzi e wagę V0 + V1
    //Wypisz wagę krawędzi e
    e->weight = e->V0()->Number() + e->V1()->Number();

    //Dla kolejnych krawędzi grafu powtórz ostatnie 7 kroków(e = SelectEdge(2, 3),…)
                    Testy proszę powtórzyć tworząc graf nieskierowany
}