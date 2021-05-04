// Niklas Leet

#include "balrog.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

namespace cs_creature {
    Balrog::Balrog() {}

    Balrog::Balrog(int newStrength, int newHitpoints) 
        : Demon(newStrength, newHitpoints) {}

    int Balrog::getDamage() const{
        int damage1 = Demon::getDamage();
        cout << endl;

        int damage2 = rand() % getStrength() + 1;
        cout << getSpecies() << " speed attack inflicts " 
            << damage2 << " additional damage points!" << endl;

        return damage1 + damage2;
    }

    std::string Balrog::getSpecies() const {
        return "Balrog";
    }
}