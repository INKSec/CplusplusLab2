//
// Created by Micha on 10.05.2022.
//

#include "Customer.h"

Customer::Customer(const std::string &name) : customerName(name) {

}

void Customer::ServeDish(std::unique_ptr<AbstractDish> dish) {
    customerDish = std::move( dish);
}

std::string Customer::getName() {
    return customerName;
}

void Customer::EatDish() {
    std::cout << customerName << " verspeist " << customerDish->GetDishName() << std::endl;
    customerDish.reset(nullptr);

}
