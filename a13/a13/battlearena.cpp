/*
    Name: Niklas Leet
    Class: CS 10B
    Date: 5/3/2021
    Instructor: Dave Harden
    Archive: "a13.zip"
    Assignment 13, Part 2
*/

#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "balrog.h"
#include "elf.h"
#include "human.h"
#include "cyberdemon.h"

using namespace cs_creature;
using namespace std;

void battleArena(Creature& Creature1, Creature& Creature2);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    Human h(50,50);
    Elf e(50,50);
    Cyberdemon c(50,50);
    Balrog b(50,50);

    // Human v. Elf
    battleArena(h, e);
    h.setHitpoints(50);
    e.setHitpoints(50);

    // Human v. Cyberdemon
    battleArena(h, c);
    h.setHitpoints(50);
    c.setHitpoints(50);

    // Human v. Balrog
    battleArena(h, b);
    h.setHitpoints(50);
    b.setHitpoints(50);

    // Elf v. Cyberdemon
    battleArena(e, c);
    e.setHitpoints(50);
    c.setHitpoints(50);

    // Elf v. Balrog
    battleArena(e, b);
    e.setHitpoints(50);
    b.setHitpoints(50);

    // Cyberdemon v. Balrog
    battleArena(c, b);
    c.setHitpoints(50);
    b.setHitpoints(50);
}

void battleArena(Creature& Creature1, Creature& Creature2) {
    cout << "---------------------------------------------------------------\n" 
        << endl;
    cout << Creature1.getSpecies() << " vs. " << Creature2.getSpecies() 
        << "... FIGHT!" << endl;
    int c1HP = Creature1.getHitpoints();
    int c2HP = Creature2.getHitpoints();
    while(c1HP > 0 && c2HP > 0) {
        cout << "\n";
        Creature1.setHitpoints(c1HP - Creature2.getDamage());
        c1HP = Creature1.getHitpoints();
        cout << "Result: " << Creature1.getSpecies() << " has " << c1HP 
            << " hitpoints!" << endl;
        
        Creature2.setHitpoints(c2HP - Creature1.getDamage());
        c2HP = Creature2.getHitpoints();
        cout << "Result: " << Creature2.getSpecies() << " has " << c2HP 
            << " hitpoints!" << endl;
    }

    if(c1HP > 0 && c2HP <= 0)
        cout << "\n" << Creature1.getSpecies() << " wins!\n" << endl;
    else if(c2HP > 0 && c1HP <= 0)
        cout << "\n" << Creature2.getSpecies() << " wins!\n" << endl;
    else if(c1HP <= 0 && c2HP <= 0)
        cout << "\nIt was a tie!\n" << endl;
}

/* OUTPUT
    C:\Users\Niklas Leet\c++\cs-10b\a13\Part 2>.\battlearena.exe
    ---------------------------------------------------------------

    Human vs. Elf... FIGHT!

    The Elf attacks for 48 points!
    Result: Human has 2 hitpoints!
    The Human attacks for 16 points!
    Result: Elf has 34 hitpoints!

    The Elf attacks for 1 points!
    Magical attack inflicts 1 additional damage points!
    Result: Human has 0 hitpoints!
    The Human attacks for 12 points!
    Result: Elf has 22 hitpoints!

    Elf wins!

    ---------------------------------------------------------------

    Human vs. Cyberdemon... FIGHT!

    The Cyberdemon attacks for 40 points!
    Result: Human has 10 hitpoints!
    The Human attacks for 28 points!
    Result: Cyberdemon has 22 hitpoints!

    The Cyberdemon attacks for 48 points!
    Demonic attack inflicts 50 additional damage points!
    Result: Human has -88 hitpoints!
    The Human attacks for 27 points!
    Result: Cyberdemon has -5 hitpoints!

    It was a tie!

    ---------------------------------------------------------------

    Human vs. Balrog... FIGHT!

    The Balrog attacks for 33 points!
    Demonic attack inflicts 50 additional damage points!

    Balrog speed attack inflicts 32 additional damage points!      
    Result: Human has -65 hitpoints!
    The Human attacks for 3 points!
    Result: Balrog has 47 hitpoints!

    Balrog wins!

    ---------------------------------------------------------------

    Elf vs. Cyberdemon... FIGHT!

    The Cyberdemon attacks for 18 points!
    Result: Elf has 32 hitpoints!
    The Elf attacks for 28 points!
    Magical attack inflicts 28 additional damage points!
    Result: Cyberdemon has -6 hitpoints!

    Elf wins!

    ---------------------------------------------------------------

    Elf vs. Balrog... FIGHT!

    The Balrog attacks for 48 points!

    Balrog speed attack inflicts 20 additional damage points!
    Result: Elf has -18 hitpoints!
    The Elf attacks for 11 points!
    Magical attack inflicts 11 additional damage points!
    Result: Balrog has 28 hitpoints!

    Balrog wins!

    ---------------------------------------------------------------

    Cyberdemon vs. Balrog... FIGHT!

    The Balrog attacks for 37 points!

    Balrog speed attack inflicts 38 additional damage points!
    Result: Cyberdemon has -25 hitpoints!
    The Cyberdemon attacks for 22 points!
    Result: Balrog has 28 hitpoints!

    Balrog wins!


    C:\Users\Niklas Leet\c++\cs-10b\a13\Part 2>.\battlearena.exe
    ---------------------------------------------------------------

    Human vs. Elf... FIGHT!

    The Elf attacks for 51 points!
    Magical attack inflicts 51 additional damage points!
    Result: Human has -52 hitpoints!
    The Human attacks for 5 points!
    Result: Elf has 45 hitpoints!

    Elf wins!

    ---------------------------------------------------------------

    Human vs. Cyberdemon... FIGHT!

    The Cyberdemon attacks for 18 points!
    Result: Human has 32 hitpoints!
    The Human attacks for 12 points!
    Result: Cyberdemon has 38 hitpoints!

    The Cyberdemon attacks for 41 points!
    Result: Human has -9 hitpoints!
    The Human attacks for 41 points!
    Result: Cyberdemon has -3 hitpoints!

    It was a tie!

    ---------------------------------------------------------------

    Human vs. Balrog... FIGHT!

    The Balrog attacks for 20 points!

    Balrog speed attack inflicts 32 additional damage points!
    Result: Human has -2 hitpoints!
    The Human attacks for 12 points!
    Result: Balrog has 38 hitpoints!

    Balrog wins!

    ---------------------------------------------------------------

    Elf vs. Cyberdemon... FIGHT!

    The Cyberdemon attacks for 50 points!
    Demonic attack inflicts 50 additional damage points!
    Result: Elf has -50 hitpoints!
    The Elf attacks for 26 points!
    Magical attack inflicts 26 additional damage points!
    Result: Cyberdemon has -2 hitpoints!

    It was a tie!

    ---------------------------------------------------------------

    Elf vs. Balrog... FIGHT!

    The Balrog attacks for 22 points!

    Balrog speed attack inflicts 41 additional damage points!
    Result: Elf has -13 hitpoints!
    The Elf attacks for 40 points!
    Magical attack inflicts 40 additional damage points!
    Result: Balrog has -30 hitpoints!

    It was a tie!

    ---------------------------------------------------------------

    Cyberdemon vs. Balrog... FIGHT!

    The Balrog attacks for 14 points!

    Balrog speed attack inflicts 41 additional damage points!
    Result: Cyberdemon has -5 hitpoints!
    The Cyberdemon attacks for 29 points!
    Demonic attack inflicts 50 additional damage points!
    Result: Balrog has -29 hitpoints!

    It was a tie!
*/