//
// Created by Micha on 10.05.2022.
//

#ifndef LABOR2_2_DISHFACTORY_H
#define LABOR2_2_DISHFACTORY_H
#include <iostream>
#include "AbstractDish.h"
#include "PizzaMargherita.h"
#include "VegetableSoup.h"
#include <memory>
// anforderung 3

    enum class Meal {
        PizzaMargherita, VegetableSoup
    };


    class DishFactory {
    public:

        std::unique_ptr<AbstractDish> CreateDish(const Meal &); // static

    };


#endif //LABOR2_2_DISHFACTORY_H
