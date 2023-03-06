#include "Lab6Example.h"
#include <iostream>

//Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з елементами даних класів у кожному класі.
//Схема успадкування на рисунку за варіантами.
//Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням.
//Вивести розміри об’єктів даних класів.
//Без віртуального успадкування

namespace SpaceExample1 {
    class A
    {
    protected:
        int a1;
    public:
        A() : a1(1) {}
        A(int a) : a1(a) {}
    };
  
    class B : protected A
    {
    protected:
        int b1;
    public:
        B() : b1(1) {}
        B(int b) : b1(b) {}
        B(int b, int a) : A(a), b1(b) {}
    };

    class C : protected A, protected B
    {
    protected:
        int c1;
    public:
        C() : c1(1) {}
        C(int c) : c1(c) {}
        C(int a, int a1, int b1, int c) : A(a), B(a1, b1), c1(c) {}
    };

    class D : protected B
    {
    protected:
        int d1;
    public:
        D() : d1(1) {}
        D(int d) : d1(d) {}
        D(int a, int b, int d) : B(a, b), d1(d) {}
    };

    class E : protected C, protected D
    {
    protected:
        int e1;
    public:
        E() : e1(1) {}
        E(int e) : e1(e) {}
        E(int a, int b, int c, int d, int a1, int b1, int c1, int e) : C(a, b, c, d), D(a1, b1, c1), e1(e) {}

    };

 //З віртуальним успадкуванням
    class BV : protected virtual A
    {
    protected:
        int b1;
    public:
        BV() : b1(1) {}
        BV(int b) : b1(b) {}
        BV(int b, int a) : A(a), b1(b) {}
    };

    class CV : protected virtual A, protected virtual BV
    {
    protected:
        int c1;
    public:
        CV() : c1(1) {}
        CV(int c) : c1(c) {}
        CV(int a, int a1, int b1, int c) : A(a), BV(a1, b1), c1(c) {}
    };

    class DV : protected virtual BV
    {
    protected:
        int d1;
    public:
        DV() : d1(1) {}
        DV(int d) : d1(d) {}
        DV(int a, int b, int d) : BV(a, b), d1(d) {}
    };

    class EV : protected virtual CV, protected virtual DV
    {
    protected:
        int e1;
    public:
        EV() : e1(1) {}
        EV(int e) : e1(e) {}
        EV(int a, int b, int c, int d, int a1, int b1, int c1, int e) : CV(a, b, c, d), DV(a1, b1, c1), e1(e) {}

    };

    int mainExample1()
    {
        std::cout << " Example1  \n";
        E a, b(1, 2, 3, 4, 5, 6, 7 , 8);
        EV av, bv(11, 22, 33, 44, 55, 66, 77, 88);

        std::cout << "Test no virtual !\n";
        std::cout << "Size for A " << sizeof(A) << std::endl;
        std::cout << "Size for B " << sizeof(B) << std::endl;
        std::cout << "Size for C " << sizeof(C) << std::endl;
        std::cout << "Size for D " << sizeof(D) << std::endl;
        std::cout << "Size for E " << sizeof(E) << std::endl;
        std::cout << "Virtual " << std::endl;
        std::cout << "Size for A " << sizeof(A) << std::endl;
        std::cout << "Size for BV " << sizeof(BV) << std::endl;
        std::cout << "Size for CV " << sizeof(CV) << std::endl;
        std::cout << "Size for DV " << sizeof(DV) << std::endl;
        std::cout << "Size for EV " << sizeof(EV) << std::endl;

        return 0;
    }
}