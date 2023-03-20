#include "SetAsArray.h"
#include "AddingVisitor.h"

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

    std::cout << "A: ";
    A.Display();
    std::cout << "B: ";
    B.Display();
    std::cout << "C: ";
    C.Display();
    std::cout << "D: ";
    D.Display();

    std::cout << "D == A: " << (D == A) << std::endl;
    std::cout << "D <= A: " << (D <= A) << std::endl;
    std::cout << "C == B: " << (C == B) << std::endl;
    std::cout << "B <= C: " << (B <= C) << std::endl;

    A.Insert(1);

    std::cout << "D == A: " << (D == A) << std::endl;
    std::cout << "D <= A: " << (D <= A) << std::endl;

    //adding visitor
    A.Insert(5);
    AddingVisitor<int> v_A;
    A.Accept(v_A);
    std::cout << v_A.GetSum() << std::endl;
    SetAsArray E(10);
    E = A * B;
    AddingVisitor<int> v_E;
    E.Accept(v_E);
    std::cout << v_E.GetSum() << std::endl;
    E.Withdraw(1);
    E.Accept(v_E);

    //odd visitor
    //Sprawdzenie czy w zbiorze B jest liczba nieparzysta (korzystając z wizytatora)
    //Sprawdzenie czy w zbiorze A jest liczba nieparzysta (korzystając z wizytatora)
    A.Withdraw(1);
    A.Withdraw(5);
    //Sprawdzenie czy w zbiorze A jest liczba nieparzysta (korzystając z wizytatora)
    //Proszę na potrzeby sprawdzenia, czy działa IsDone(), wypisać na której komórce funkcja
    //Accept() zakończyła przeglądanie
}