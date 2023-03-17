#include <SetAsArray.h>

int main()
{
    SetAsArray A(10);
    SetAsArray B(10);
    SetAsArray C(10);
    SetAsArray D(10);

    for (int i = 0; i < A.UniverseSize(); i++)
    {
        if (!(i % 2))
        {
            A.Insert(i);
        }
    }

    for (int i = 0; i < B.UniverseSize(); i++)
    {
        if ((i % 2))
        {
            B.Insert(i);
        }
    }

    C = A + B;
    D = C - B;

    
}