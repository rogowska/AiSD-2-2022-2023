#include "SetAsArray.h"
#include "AddingVisitor.h"
#include "OddVisitor.h"

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

    // adding visitor
    A.Insert(5);
    AddingVisitor<int> av_A;
    A.Accept(av_A);
    std::cout << "Sum in A set: " << av_A.GetSum() << std::endl;
    SetAsArray E(10);
    E = A * B;
    AddingVisitor<int> av_E;
    E.Accept(av_E);
    std::cout << "Sum in E set: " << av_E.GetSum() << std::endl;
    E.Withdraw(1);
    E.Accept(av_E);
    std::cout << "Sum in E set after withdraw: " << av_E.GetSum() << std::endl;

    // odd visitor
    OddVisitor<int> ov_A;
    OddVisitor<int> ov_B;
    B.Accept(ov_B);
    std::cout << "Odd number found B set: " << ov_B.IsOdd() << std::endl;
    A.Accept(ov_A);
    std::cout << "Odd number found A set: " << ov_A.IsOdd() << std::endl;
    A.Withdraw(1);
    A.Withdraw(5);
    A.Accept(ov_A);
    std::cout << "Odd number found A set after withdraw: " << ov_A.IsOdd() << std::endl;

    /*Wypisz elementy zbioru A korzystając z iteratora

    Wypisz elementy zbioru B korzystając z iteratora*/
}