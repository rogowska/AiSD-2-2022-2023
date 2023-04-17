#include <string>

class Vertex
{
    int number;

public:
    int weight;
    std::string label;
    Vertex(int n){
        number = n;
    }
    int Number() const
    {
        return number;
    }
};