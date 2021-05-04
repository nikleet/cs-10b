// Niklas Leet

#ifndef ELF_H
#define ELF_H
#include "creature.h"
#include <string>

namespace cs_creature {
    class Elf: public Creature {
        public:
            Elf();
            Elf(int newStrength, int newHitpoints);
            int getDamage() const;
            std::string getSpecies() const;
    };
}

#endif