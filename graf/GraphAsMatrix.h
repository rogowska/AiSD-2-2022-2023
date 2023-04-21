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
    void createAdjacencyMatrix(int n)
    {
        std::vector<Edge *> column(n, nullptr);
        for (int i = 0; i < n; i++)
        {
            adjacencyMatrix.push_back(column);
        }
    }
    GraphAsMatrix(int n, bool b)
    {
        isDirected = b;
        numberOfVertices = n;
        for (int i = 0; i < n; i++)
        {
            Vertex *v = new Vertex(i+1);
            vertices.push_back(v);
        }
        createAdjacencyMatrix(n);
    }

    int NumberOfVertices()
    {
        return numberOfVertices;
    }

    bool IsDirected()
    {
        return isDirected;
    }

    int NumberOfEdges()
    {
        return numberOfEdges;
    }

    bool IsEdge(int u, int v)
    {
        bool ifEdgeExists = false;
        if (u && v > numberOfVertices)
        {
        }
        else if (adjacencyMatrix[u-1][v-1] != NULL)
        {
            ifEdgeExists = true;
        }
        return ifEdgeExists;
    }

    void MakeNull()
    {
        for (int i = 0; i < numberOfVertices; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
                adjacencyMatrix[i][j] = NULL;
        }
        numberOfEdges = 0;
    }

    void AddEdge(int u, int v)
    {
        if (!IsEdge(u, v))
        {
            Edge *edge = new Edge(vertices[u-1], vertices[v-1]);
            adjacencyMatrix[u-1][v-1] = edge;
            numberOfEdges++;
            if(!isDirected){
                adjacencyMatrix[v-1][u-1] = edge;
            }
        }
    }

    Edge *SelectEdge(int u, int v)
    {
        if (IsEdge(u, v))
            return adjacencyMatrix[u-1][v-1];
    }

    Vertex *SelectVertex(int v)
    {
        return vertices[v-1];
    }

    /*Iterator<Vertex> &VerticesIter();
    Iterator<Edge> &EdgesIter();
    Iterator<Edge> &EmanatingEdgesIter(int v);
    Iterator<Edge> &IncidentEdgesIter(int v);*/
};