// Niklas Leet

#include "cyberdemon.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

namespace cs_creature {
    Cyberdemon::Cyberdemon() {}

    Cyberdemon::Cyberdemon(int newStrength, int newHitpoints) 
        : Demon(newStrength, newHitpoints) {}

    int Cyberdemon::getDamage() const{
        cout << "The Cyberdemon";
        int damage1 = Demon::getDamage();
        cout << endl;
        return damage1;
    }

    std::string Cyberdemon::getSpecies() const {
        return "Cyberdemon";
    }
}