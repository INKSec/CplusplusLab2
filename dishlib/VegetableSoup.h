//
// Created by Micha on 10.05.2022.
//

#ifndef LABOR2_2_VEGETABLESOUP_H
#define LABOR2_2_VEGETABLESOUP_H
#include "AbstractDish.h"

class VegetableSoup : public AbstractDish{
public:
    void prepare() override;
    explicit VegetableSoup(std::string&);
};


#endif //LABOR2_2_VEGETABLESOUP_H
