//
// Created by Micha on 08.05.2022.
//
#include "KlasseA.h"
#include <iostream>

// TEIL A.1
// Konstruktor
//Tester
int A::getsz() {
    return ia[0];
}
// sz(new int{a}) alloziert den int auf dem Heap. Muss im Constructor erfolgen
// TEIL A.1-------------------------------------------------
A::A(int a) : sz(new int{ a }), ia{ new int[5] }
{
    std::cerr << "class A constructor: " << *sz << std::endl;
    _nptr = sz;
    _aptr = ia;
    for(size_t i{0}; i<5; i++) {
        _aptr[i] = 42;
    }

};
// TEIL A.2 -------------------------------------------------
// Kopierkonstruktor
A::A(A const& orig)
{
    sz = new int{*orig.sz};
    ia = new int[5];

    _nptr = sz;
    _aptr = this->ia;
    for (size_t i{ 0 }; i < *sz; i++) {
        ia[i] = orig.ia[i];
    }

    std::cerr << "class A copy constructor: " << *sz << std::endl;

}
// TEIL A.3 ----------------------------------------------------
// Verschiebekonstruktor

A::A(A&& orig) : sz(orig.sz){


    std::cerr << "class A move constructor: " << *orig.sz << std::endl;
    std::swap(orig._nptr, _nptr);
    std::swap(orig._aptr, _aptr);
    }


// TEIL A.4 ------------------------------------------------------

// Kopierzuweisungsoperator
A& A::operator=(A const& orig)
{
    if (this != &orig) {
        std::cerr << "class A copy assignment operator: " << *orig.sz << std::endl;
        delete ia;
        delete sz;
        sz = new int{*orig.sz};
        ia = new int[*sz];
        for (size_t i{0}; i < *sz; i++) {
            ia[i] = orig.ia[i];
        }
    } else {
        std::cout << "Das kann man sich auch sparen" << std::endl;
    }


    return *this;
}

// TEIL A.5 ----------------------------------------------------------
// Verschiebezuweisungsoperator
A& A::operator=(A&& orig) {


        std::cerr << "class A move assignment operator: " << *orig.sz << std::endl;
        std::swap(sz, orig.sz);
        std::swap(ia, orig.ia);
        std::swap(orig._nptr, _nptr);
        std::swap(orig._aptr, _aptr);

        return *this;


}

// Destruktor
A::~A()
{
    if (nullptr == _nptr)
    {
        std::cerr << "class A destructor: nullptr" << std::endl;
    } else {
        std::cerr << "class A destructor: " << *sz << std::endl;
    }

    delete[] _nptr;
    delete[] _aptr;


}



