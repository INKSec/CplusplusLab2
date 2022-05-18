//
// Created by Micha on 10.05.2022.
//

#ifndef LABOR2_2_PIZZAMARGHERITA_H
#define LABOR2_2_PIZZAMARGHERITA_H
#include "AbstractDish.h"

class PizzaMargherita : public AbstractDish{
public:
    void prepare() override;



    PizzaMargherita() = delete;
    explicit PizzaMargherita(std::string &);




};


#endif //LABOR2_2_PIZZAMARGHERITA_H
