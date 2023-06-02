#include <vector>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "Iterator.h"
#include "CountingVisitor.h"

class GraphAsMatrix
{
    std::vector<Vertex *> vertices;
    std::vector<std::vector<Edge *>> adjacencyMatrix;
    bool isDirected;
    int numberOfVertices;
    int numberOfEdges = 0;

    class AllVerticesIter : public Iterator<Vertex>
    {
        GraphAsMatrix &owner;
        int current;

    public:
        AllVerticesIter(GraphAsMatrix &owner) : owner(owner)
        {
            current = 0;
            this->owner = owner;
        };
        bool IsDone()
        {
            if (current >= owner.vertices.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Vertex &operator*() { return *owner.vertices[current]; }
        void operator++() { current++; }
    };

    class AllEdgesIter : public Iterator<Edge>
    {
        GraphAsMatrix &owner;
        int row;
        int col;

    public:
        void next()
        {
            int width = owner.adjacencyMatrix.size();
            if (!this->IsDone())
            {
                col++;
                if (col >= width)
                {
                    row++;
                    col = 0;
                }
            }
            while (owner.adjacencyMatrix[col][row] == NULL && !this->IsDone())
            {
                col++;
                if (col >= width)
                {
                    row++;
                    col = 0;
                }
            }
        }
        AllEdgesIter(GraphAsMatrix &owner) : owner(owner)
        {
            this->owner = owner;
            row = 0;
            col = -1;
        }
        bool IsDone()
        {
            int width = owner.adjacencyMatrix.size();
            if (col >= width - 1 && row >= owner.adjacencyMatrix[width - 1].size() - 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Edge &operator*()
        {
            if (col < 0)
                next();
            return *owner.adjacencyMatrix[col][row];
        }
        void operator++() { next(); }
    };

    class EmanEdgesIter : public Iterator<Edge>
    {
        GraphAsMatrix &owner;
        int row;
        int col;

    public:
        void next()
        {
            col++;
            while (owner.adjacencyMatrix[col][row] == NULL && !this->IsDone())
            {
                col++;
            }
        }
        EmanEdgesIter(GraphAsMatrix &owner, int v) : owner(owner)
        {
            row = v;
            col = -1;
            this->owner = owner;
        }
        bool IsDone()
        {
            int value = owner.adjacencyMatrix.size();
            if (col >= (value - 1))
                return true;
            else
            {
                return false;
            }
        }
        Edge &operator*()
        {
            if (col < 0)
                next();
            return *owner.adjacencyMatrix[col][row];
        }
        void operator++() { next(); }
    };

    class InciEdgesIter : public Iterator<Edge>
    {
        GraphAsMatrix &owner;
        int row;
        int col;

    public:
        void next()
        {
            row++;
            while (owner.adjacencyMatrix[col][row] == NULL && !this->IsDone())
            {
                row++;
            }
        }
        InciEdgesIter(GraphAsMatrix &owner, int v) : owner(owner)
        {
            row = -1;
            col = v;
            this->owner = owner;
        }
        bool IsDone()
        {
            int value = owner.adjacencyMatrix[0].size();
            if (row >= (value - 1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Edge &operator*()
        {
            if (row < 0)
                next();
            return *owner.adjacencyMatrix[col][row];
        }
        void operator++() { next(); }
    };

public:
    bool IsConnected()
    {
        if (!IsDirected())
        {
            Vertex *v = vertices[0];
            CountingVisitor visitor;
            std::vector<bool> visited(vertices.size(), false);
            DFS_visitor(&visitor, v, visited);
            std::cout << std::endl;
            return (visitor.GetNumber() == vertices.size());
        }
        if (IsDirected())
        {
            Vertex *v;
            int min = vertices.size();
            for (int i = 0; i < vertices.size(); i++)
            {
                v = vertices[i];
                CountingVisitor visitor;
                std::vector<bool> visited(vertices.size(), false);
                DFS_visitor(&visitor, v, visited);
                if (visitor.GetNumber() < min)
                {
                    return false;
                }
            }
            return true;
        }
    }

    void DFS(Vertex *v)
    {
        int number = 1;
        CountingVisitor visitor;
        std::vector<bool> visited(vertices.size(), false);
        DFS_visitor(&visitor, v, visited);
        AllVerticesIter iter(*this);
        while (!iter.IsDone())
        {
            ++iter;
            Vertex *x = &(*iter);
            if (!iter.IsDone())
            {
                if (visited[x->Number()] == false)
                {
                    number++;
                    DFS_visitor(&visitor, &(*iter), visited);
                }
            }
        }
        std::cout<<"Liczba skarbonek do zniszczenia: "<<number<<std::endl;
    }

    void DFS_visitor(CountingVisitor *visitor, Vertex *v, std::vector<bool> &visited)
    {
        int row = v->Number();
        int last_col = adjacencyMatrix.size()-1;
        visitor->Visit(*v);
        visited[v->Number()] = true;
        EmanEdgesIter emanIter(*this, row);
        while (!emanIter.IsDone())
        {
            ++emanIter;
            if (!emanIter.IsDone() || (emanIter.IsDone() && adjacencyMatrix[last_col][row] != nullptr))
            {
                Edge vEdge = *emanIter;
                Vertex *u = vEdge.Mate(v);
                if (visited[u->Number()] == false)
                {
                    DFS_visitor(visitor, u, visited);
                }
            }
        }
    }

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
            Vertex *v = new Vertex(i);
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
        else if (adjacencyMatrix[u][v] != NULL)
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
            Edge *edge = new Edge(vertices[u], vertices[v]);
            adjacencyMatrix[u][v] = edge;
            numberOfEdges++;
            if (!isDirected)
            {
                adjacencyMatrix[v][u] = edge;
            }
        }
    }

    Edge *SelectEdge(int u, int v)
    {
        if (IsEdge(u, v))
            return adjacencyMatrix[u][v];
    }

    Vertex *SelectVertex(int v)
    {
        return vertices[v];
    }

    Iterator<Vertex> &VerticesIter()
    {
        return *new AllVerticesIter(*this);
    }
    Iterator<Edge> &EdgesIter()
    {
        return *new AllEdgesIter(*this);
    }
    Iterator<Edge> &EmanatingEdgesIter(int v)
    {
        return *new EmanEdgesIter(*this, v);
    }
    Iterator<Edge> &IncidentEdgesIter(int v)
    {
        return *new InciEdgesIter(*this, v);
    }
};