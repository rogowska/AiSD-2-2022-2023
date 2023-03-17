#include "SetAsArray.h"

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

    A.Display();
    B.Display();
    C.Display();
    D.Display();

    std::cout << (D == A) << std::endl;
    std::cout << (D <= A) << std::endl;
    std::cout << (C == B) << std::endl;
    std::cout << (B <= C) << std::endl;

    A.Insert(1);
    std::cout << (D == A) << std::endl;
    std::cout << (D <= A) << std::endl;
}