//
// Created by Micha on 10.05.2022.
//

#ifndef LABOR2_2_ABSTRACTDISH_H
#define LABOR2_2_ABSTRACTDISH_H
#include <iostream>
#include <vector>
class AbstractDish {
public:
    virtual void prepare() = 0;
    std::string GetDishName();
    [[nodiscard]] std::vector<std::string> Getingridents() const;
    [[nodiscard]] unsigned GetNumberIngridents() const;
    AbstractDish() = delete;
    explicit AbstractDish(std::string );

protected:
    void AddIngridents();
    std::string dishName;
    std::vector<std::string> vIngridents;
};


#endif //LABOR2_2_ABSTRACTDISH_H
