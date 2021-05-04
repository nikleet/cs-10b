// Niklas Leet

#include "human.h"
#include <string>
#include <iostream>

using namespace std;

namespace cs_creature {
    Human::Human() {}

    Human::Human(int newStrength, int newHitpoints) 
        : Creature(newStrength, newHitpoints) {}

    std::string Human::getSpecies() const {
        return "Human";
    }
}