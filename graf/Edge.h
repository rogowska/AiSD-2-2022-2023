#include "Vertex.h"

class Edge
{
protected:
Vertex* v0;
Vertex* v1;
public:
int weight;
std::string label;
Edge (Vertex *V0, Vertex* V1);
Vertex* V0 (){return v0;};
Vertex* V1 (){return v1;};
Vertex* Mate (Vertex *v);
};