//
// Created by Micha on 10.05.2022.
//

#include <memory>
#include "DishFactory.h"



std::unique_ptr<AbstractDish> DishFactory::CreateDish(const Meal& p) {
// switch
    std::unique_ptr<AbstractDish> dish;

    switch (p) {
        case Meal::VegetableSoup: {
            std::string b{"VegetableSoup"};
            dish = std::make_unique<VegetableSoup>(b);
            break;
        }
        case Meal::PizzaMargherita:
            std::string a{"PizzaMargherita"};
            dish = std::make_unique<PizzaMargherita>(a);
            break;
    }

    std::cout << dish->GetDishName() << std::endl;
    dish->prepare();
    return dish;
}


/*
    if(p == Meal::PizzaMargherita) {
        std::string a{"PizzaMargherita"};
        dish = std::make_unique<PizzaMargherita>(a);
    } else {
        std::string  b{"VegetableSoup"};
        dish = std::make_unique<VegetableSoup>(b);
    }
     */











