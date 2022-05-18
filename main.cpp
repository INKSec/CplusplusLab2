#include <iostream>
#include <vector>
#include <algorithm>
#include "dishlib/AbstractDish.h"
#include "dishlib/DishFactory.h"
#include "dishlib/Customer.h"


using namespace std;

int main()
{
/*
    // TEIL A.1 ----------------------------

    A e(3);

    // TEIL A.2 ----------------------------

    A a1{3};
    A a2{a1};
    A a3{A{4}};
    //std::cout << a3.getsz() << std::endl;


    // TEIL A.3 ----------------------------

    vector<A> v;
    v.push_back(std::move(A{5}));
    std::cout << v[0].getsz() << std::endl;

    // TEIL A.4 ----------------------------

    A a5{7};
    A a6{8};
    a6 = a5;

    // TEIL A.5 -----------------------------

    A a7{9};
    a7 = A{10};

    // TEIL A.6 -----------------------------

    A a8{11};
    A a9{move(a8)};
    */

// Fragen
// Warum wird bei “A a3{A{4}};“ in Teil A.2 kein Kopierkonstruktor aufgerufen?
// Weil es sich um eine Initialisierung handelt. Objekt a3 wird mit Objekt A{4} (Temporaer)initialisiert

// Warum wird in Teil A.3 “class A destructor: nullptr” ausgegeben?
// Weil der Zeiger verschoben/getauscht wurde und somit auf nichts zeigt. Es ist keine Kopie

// Warum wird in Teil A.5 “class A destructor: 9” ausgegeben?
// Weil die Zeiger verschoben worden sind, das Objekt jedoch weiterhin existiert.
// Das passiert auch im zweiten Teil mit den Objekten im vector, nachdem sie verschoben worden sind.

// Inwiefern verhält sich Teil A.6 anders als Teil A.2?
// Die move semantik wird explizit gecastet


// Aufgabe 5

    Meal M = Meal::PizzaMargherita;
    Meal V = Meal::VegetableSoup;
    DishFactory h;

    Customer aa("Herbert");

    // Teil 8&9 ----------------------------------------------
    std::vector<std::unique_ptr<AbstractDish>> vDishes;
    for(size_t i = 1; i<=1; i++) {
        std::cout << "Erzeuge Gericht " << i << " und " << (i+1) << std::endl;
        vDishes.push_back( std::move(h.CreateDish(V)));
        vDishes.push_back( std::move(h.CreateDish(M)));

    }



    // Teil 10 -------------------------------------------------
    std::sort(vDishes.begin(), vDishes.end(), [](std::unique_ptr<AbstractDish> &x, std::unique_ptr<AbstractDish> &y)
    {
        return  x->GetNumberIngridents() > y->GetNumberIngridents();
    });

    // Teil 11 --------------------------------------------------
    std::cout << "\nEs wurden folgende " << vDishes.size() << " Gerichte erstellt:" << std::endl;
    for(const auto &s : vDishes) {
        std::cout << s->GetDishName() << " mit " << s->GetNumberIngridents() << " Zutaten" <<  std::endl;

    }

    // Teil 12
    std::vector<std::unique_ptr<Customer>> Kunden;
    std::unique_ptr<Customer> kunde;

    kunde = std::make_unique<Customer>("Herbert");
    Kunden.push_back(std::move(kunde));
    kunde = std::make_unique<Customer>("Mark");
    Kunden.push_back(std::move(kunde));


    // Teil 13
    /*
     * Warum geht das nicht?
    for(auto &d : Kunden) {
        size_t i {0};
        d->ServeDish(std::move(vDishes[i]));
        i++;
    }
     */

    for (size_t i = 0; i < vDishes.size(); i++) {
        Kunden[i]->ServeDish(std::move(vDishes[i]));
        // vDishes.erase((vDishes.begin() + i)); Warum geht das nicht? Weil .size() sich veraendert durch das loeschen

    }


    vDishes.erase((vDishes.begin() + 0));
    vDishes.erase((vDishes.begin() + 1));


    // Teil 14 --------------------------------------------------
    std::cout << "\nJetzt wird gegessen" << std::endl;
    for(auto &d : Kunden ) {
        d->EatDish();
    }

    return 0;
}