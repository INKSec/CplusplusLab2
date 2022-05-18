//
// Created by Micha on 08.05.2022.
//

#ifndef CLIONPROJEKT_KLASSEA_H
#define CLIONPROJEKT_KLASSEA_H


#define NULL nullptr


class A {
    int *sz, * ia;
public:
    // Konstruktor
    A(const int a);

    // Kopierkonstruktor
    A(A const&);

    // Destruktor
    ~A();

    // Ueberladung
    A& operator=(A const&);
    A& operator=(A&&);

    // Verschieber
    A(A&&);


    //getter
    int getsz();


private:
    int* _nptr{ NULL };
    int* _aptr{ NULL };

    int arr[5] {1,2,3,4,5};





};

#endif //CLIONPROJEKT_KLASSEA_H
