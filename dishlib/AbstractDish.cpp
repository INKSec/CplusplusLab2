//
// Created by Micha on 10.05.2022.
//

#include "AbstractDish.h"
#include <iostream>
#include <utility>

std::string AbstractDish::GetDishName() {
    return dishName;
}

AbstractDish::AbstractDish(std::string  name) : dishName(std::move(name)){

}


void AbstractDish::AddIngridents() {
    std::string ingrident;
    std::cout << "End with 0" << std::endl;
    while(ingrident != "0") {

        std::cout << "Enter ingrident: " << std::endl;
        std::cin >> ingrident;

        if("0" != ingrident ) {
            vIngridents.push_back(ingrident);
        }
    }

}

std::vector<std::string> AbstractDish::Getingridents() const {
    return vIngridents;
}

unsigned AbstractDish::GetNumberIngridents() const {

    return vIngridents.size();
}
