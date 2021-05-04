// Niklas Leet

#include "creature.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace cs_creature {
    Creature::Creature() {
        strength = 10;
        hitpoints = 10;
    }

    Creature::Creature(int newStrength, int newHitpoints) {
        strength = newStrength;
        hitpoints = newHitpoints;
    }

    int Creature::getStrength() const {
        return strength;
    }

    int Creature::getHitpoints() const {
        return hitpoints;
    }

    void Creature::setStrength(int newStrength) {
        strength = newStrength;
    }

    void Creature::setHitpoints(int newHitpoints) {
        hitpoints = newHitpoints;
    }

    int Creature::getDamage() const{
        return rand() % (strength + 1) + 1;
    }

    std::string Creature::getSpecies() const {
        return "Creature";
    }
}