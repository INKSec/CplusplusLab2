//
// Created by Micha on 10.05.2022.
//

#ifndef LABOR2_2_CUSTOMER_H
#define LABOR2_2_CUSTOMER_H
#include <memory>
#include <iostream>
#include "DishFactory.h"

class Customer {
public:
    void ServeDish(std::unique_ptr<AbstractDish>);
    void EatDish();
    std::string getName();

    Customer() = delete;
    Customer(const std::string&);
private:

    std::unique_ptr<AbstractDish> customerDish;
    std::string customerName;




};


#endif //LABOR2_2_CUSTOMER_H
