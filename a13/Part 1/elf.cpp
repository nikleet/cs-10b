// Niklas Leet

#include "elf.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

namespace cs_creature {
    Elf::Elf() {}

    Elf::Elf(int newStrength, int newHitpoints) 
        : Creature(newStrength, newHitpoints) {}

    int Elf::getDamage() const{
        int damage1 = Creature::getDamage();
        cout << "The " << getSpecies() << " attacks for " 
            << damage1 << " points!" << endl;
        int damage2 = 0;
        if(rand() % 100 < 50) {
            damage2 = damage1;
            cout << "Magical attack inflicts " 
                << damage2 << " additional damage points!" << endl;  
        }
        return damage1 + damage2;
    }

    std::string Elf::getSpecies() const {
        return "Elf";
    }
}