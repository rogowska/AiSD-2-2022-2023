#include <vector>
#include "Vertex.h"
#include "Edge.h"

class GraphAsMatrix
{
    std::vector<Vertex *> vertices;
    std::vector<std::vector<Edge *>> adjacencyMatrix;
    bool isDirected;
    int numberOfVertices;
    int numberOfEdges = 0;

    /* class AllVerticesIter: public Iterator<Vertex>
     {
     GraphAsMatrix & owner;
     int current;
     public:
     AllVerticesIter(GraphAsMatrix &owner)
     bool IsDone();
     Vertex & operator*();
     void operator++();
    };
     class AllEdgesIter: public Iterator<Edge>
     {
     GraphAsMatrix & owner;
     int row;
     int col;
     public:
     void next()
     AllEdgesIter(GraphAsMatrix &owner);
     bool IsDone();
     Edge & operator*();
     void operator++(){next();}
     };
    class EmanEdgesIter: public Iterator<Edge>
     {
     GraphAsMatrix & owner;
     int row;
     int col;
     public:
     void next()
     EmanEdgesIter(GraphAsMatrix &owner,int v);
     bool IsDone();
     Edge & operator*();
     void operator++(){next();}
    };
    class InciEdgesIter: public Iterator<Edge>
     {
     GraphAsMatrix & owner;
     int row;
     int col;
     public:
    2
     void next()
     InciEdgesIter(GraphAsMatrix &owner,int v);
     bool IsDone();
     Edge & operator*();
     void operator++(){next();}
    };*/

public:
    GraphAsMatrix(int n, bool b){
        isDirected = b;
        numberOfVertices = n;
        for(int i = 0; i < n; i++){
            Vertex v(i);
            vertices.push_back(&v);
        }
        //tworzenie macierzy sasiedztwa nxn i wypelnienie nullami
        std::vector<Edge *> column(n, nullptr);
        for(int i = 0; i < n; i++){
            adjacencyMatrix.push_back(column);
        }
    }
    int NumberOfVertices();
    bool IsDirected()
    {
        return isDirected;
    }
    int NumberOfEdges();
    bool IsEdge(int u, int v);
    void MakeNull();
    void AddEdge(int u, int v);
    Edge *SelectEdge(int u, int v);
    Vertex *SelectVertex(int v);

    /*Iterator<Vertex> &VerticesIter();
    Iterator<Edge> &EdgesIter();
    Iterator<Edge> &EmanatingEdgesIter(int v);
    Iterator<Edge> &IncidentEdgesIter(int v);*/
};