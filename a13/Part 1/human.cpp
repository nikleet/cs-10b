// Niklas Leet

#include "human.h"
#include <string>
#include <iostream>

using namespace std;

namespace cs_creature {
    Human::Human() {}

    Human::Human(int newStrength, int newHitpoints) 
        : Creature(newStrength, newHitpoints) {}

    int Human::getDamage() const {
        int damage = Creature::getDamage();
        cout << "The " << getSpecies() << " attacks for " 
            << damage << " points!" << endl;
        return damage;
    }

    std::string Human::getSpecies() const {
        return "Human";
    }
}