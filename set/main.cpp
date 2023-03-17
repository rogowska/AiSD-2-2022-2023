#include "SetAsArray.h"

int main()
{
    SetAsArray A(10);
    SetAsArray B(10);
    SetAsArray C(10);
    SetAsArray D(10);

    for (int i = 0; i < A.UniverseSize(); i++)
    {
        if (!(i % 2) || i == 0)
        {
            A.Insert(i);
        }
    }

    for (int i = 0; i < B.UniverseSize(); i++)
    {
        if ((i % 2) && i != 0)
        {
            B.Insert(i);
        }
    }

    C = A + B;
    D = C - B;

    std::cout<< "A: ";
    A.Display();
    std::cout<< "B: ";
    B.Display();
    std::cout<< "C: ";
    C.Display();
    std::cout<< "D: ";
    D.Display();

    std::cout << "D == A: " << (D == A) << std::endl;
    std::cout << "D <= A: " << (D <= A) << std::endl;
    std::cout << "C == B: " << (C == B) << std::endl;
    std::cout << "B <= C: " << (B <= C) << std::endl;

    A.Insert(1);

    std::cout << "D == A: " << (D == A) << std::endl;
    std::cout << "D <= A: " << (D <= A) << std::endl;
}