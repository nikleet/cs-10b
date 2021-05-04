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

    std::string Cyberdemon::getSpecies() const {
        return "Cyberdemon";
    }
}