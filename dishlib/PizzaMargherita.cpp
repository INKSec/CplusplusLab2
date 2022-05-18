//
// Created by Micha on 10.05.2022.
//

#include "PizzaMargherita.h"
#include <random>

void PizzaMargherita::prepare() {
    AddIngridents();
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> distribution(0,4);

    for(auto &d: vIngridents) {

        switch(distribution(engine)) {
            case 0:
                std::cout << d << " wird geschitten" << std::endl;
                break;
            case 1:
                std::cout << d << " wird verruehrt" << std::endl;
                break;
            case 2:
                std::cout << d << " wird gestampft" << std::endl;
                break;
            case 3:
                std::cout << d << " wird draufgestreut" << std::endl;
                break;
            case 4:
                std::cout << d << " wird gemahlen" << std::endl;
                break;
        };


    }

}



PizzaMargherita::PizzaMargherita(std::string & name) : AbstractDish(name) {}




