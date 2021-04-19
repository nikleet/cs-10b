/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a2_1.cpp
    Peers cited: Nikolas Brandt; provided advice on how to seed the rand() method.

    Description: Utilizes loops to create a game of blackjack. The user is dealt
    two cards with values 0-10 and is then asked if they would like another card.
    If the total of all their cards exceeds 21, they bust and lose the game. If
    their cards add perfectly to 21, they win the game. Any time a game ends
    or is terminated, the user is asked if they would like to play again.   
    
    Input: 'y' or 'n' to prompts of whether or not the user would like to 
    continue
    Output: the card(s), the total value, and the result of the game
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
  
    char play_again; 

    do {
        int card1 = rand() % 11 + 1;
        int card2 = rand() % 11 + 1;
        cout << "First cards: " << card1 << ", " << card2 << endl;
        int total = card1 + card2;
        cout << "Total: " << total << endl;
        
        cout << "Do you want another card? (y/n): ";
        char another_card;
        cin >> another_card;   
        while(another_card == 'y') {
            int card = rand() % 11 + 1;
            cout << "Card: " << card << endl;
            total += card;
            cout << "Total: " << total << endl;
            if(total >= 22) {
                cout << "Bust." << endl;
                another_card = 'n';
            }
            else if(total == 21) {
                cout << "Congratulations!" << endl;
                another_card = 'n';
            }
            else {
                cout << "Do you want another card? (y/n): ";
                cin >> another_card;
            }  
        }

        cout << "Would you like to play again (y/n): ";
        cin >> play_again;
        if(play_again == 'y') {
            cout << endl;
        } 
    } while(play_again == 'y');

    return 0;
}

/* Output:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-2.1>.\a.exe
    First cards: 9, 6
    Total: 15
    Do you want another card? (y/n): y
    Card: 1
    Total: 16
    Do you want another card? (y/n): y
    Card: 4
    Total: 20
    Do you want another card? (y/n): n
    Would you like to play again (y/n): y  

    First cards: 6, 4
    Total: 10
    Do you want another card? (y/n): y
    Card: 11
    Total: 21
    Congratulations!
    Would you like to play again (y/n): y

    First cards: 5, 1
    Total: 6
    Do you want another card? (y/n): y
    Card: 2
    Total: 8
    Do you want another card? (y/n): y
    Card: 8
    Total: 16
    Do you want another card? (y/n): y
    Card: 11
    Total: 27
    Bust.
    Would you like to play again (y/n): n
*/