// Niklas Leet

#ifndef HUMAN_H
#define HUMAN_H
#include "creature.h"
#include <string>

namespace cs_creature {
    class Human: public Creature {
        public:
            Human();
            Human(int newStrength, int newHitpoints);
            std::string getSpecies() const;
    };
}

#endif