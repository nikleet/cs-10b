// Niklas Leet

#include "demon.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

namespace cs_creature {
    Demon::Demon() {}

    Demon::Demon(int newStrength, int newHitpoints) 
        : Creature(newStrength, newHitpoints) {}

    int Demon::getDamage() const{
        int damage1 = Creature::getDamage();
        
        int damage2 = 0;
        if(rand() % 100 < 25) {
            damage1 += 50;
            cout << "Demonic attack inflicts 50 additional damage points!" 
                << endl;
        }

        return damage1 + damage2;
    }

    std::string Demon::getSpecies() const {
        return "Demon";
    }
}