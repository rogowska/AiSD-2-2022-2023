#include "Vertex.h"

class Edge
{
protected:
    Vertex *v0;
    Vertex *v1;

public:
    int weight;
    std::string label;
    Edge(Vertex *V0, Vertex *V1)
    {
        v0 = V0;
        v1 = V1;
    }
    Vertex *V0() { return v0; };
    Vertex *V1() { return v1; };
    Vertex *Mate(Vertex *v)
    {
        if (v == v0)
            return v1;
        if (v == v1)
            return v0;
        return nullptr;
    }
};