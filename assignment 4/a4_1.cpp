/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a4_1.cpp
    Peers cited: None

    Description: Prompts the user to input a hand of cards defined by a hand
    size, highest card value, and lowest card value, represented by numbers
    (no face card). The program then identifies the quality of the poker hand.
    
    Input: A hand of poker cards, represented by integers.
    Output: An identification of the poker hand.
*/

#include <iostream>
using namespace std;

const int HAND_SIZE = 5;
const int HIGHEST_NUM = 9;
const int LOWEST_NUM = 2;

void getCardsFromUser(int hand[]);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsFourOfaKind(const int hand[]);
bool checkNextFive(const int hand[], int start);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);


int main() {
    int hand[HAND_SIZE];
    getCardsFromUser(hand);
    if(containsFourOfaKind(hand))
        cout << "Four of a Kind!" << endl;
    else if(containsFullHouse(hand))
        cout << "Full house!" << endl;
    else if(containsStraight(hand))
         cout << "Straight!" << endl;
    else if(containsThreeOfaKind(hand))
        cout << "Three of a Kind!" << endl;
    else if(containsTwoPair(hand))
        cout << "Two Pair!" << endl;
    else if(containsPair(hand))
        cout << "Pair!" << endl;
    else
        cout << "High Card!" << endl;
    return 0;
}





/*
    Prompts the user to enter their cards as integers, then assigns the cards to
    the integer array parameter, called hand.
*/
void getCardsFromUser(int hand[]) {
    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. Use numbers " 
        << LOWEST_NUM << " - " << HIGHEST_NUM << "." << endl;
    for(int i = 0; i < HAND_SIZE; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i];
    }
}





/*
    Takes the parameters of an integer array that represents the hand and an
    integer that represents a card. Counts the number of times a card appears
    in a hand. 
*/
int countCard(const int hand[], int card) {
    int count = 0;
    for(int i = 0; i < HAND_SIZE; i++) {
        if(hand[i] == card)
            count++;
    }
    return count;
}





/*
    Takes an integer array hand as a paramter. Counts the number of pains that
    appear in the hand. 
*/
int countPairs(const int hand[]) {
    int count = 0;
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if(countCard(hand, i) == 2)
            count++;
    }
    return count;
}





/*
    Takes a integer array hand as a parameter. Returns true if the hand contains a pair
    and false otherwise.
*/
bool containsPair(const int hand[]) {
    return countPairs(hand) > 0;
}





/*
    Takes a integer array hand as a parameter. Returns true if the hand
    contains two pairs and false otherwise.
*/
bool containsTwoPair(const int hand[]) {
    return countPairs(hand) == 2;
}





/*
    Takes a integer array hand as a parameter. Returns true if the hand
    contains a three of a kind (three of the same card) and false otherwise.
*/
bool containsThreeOfaKind(const int hand[]) {
    int count = 0;
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if(countCard(hand, i) == 3)
            count++;
    }
    return count > 0;
}





/*
    Takes a integer array hand as a parameter. Returns true if the hand
    contains a four of a kind (four of the same card) and false otherwise.
*/
bool containsFourOfaKind(const int hand[]) {
    int count = 0;
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if(countCard(hand, i) >= 4)
            count++;
    }
    return count > 0;
}






/*
    Takes an integer array hand and a starting card as parameters. Returns true
    if the hand contains five consecutive card values starting with the
    startingCard and false otherwise.  
*/
bool checkNextFive(const int hand[], int startingCard) {
    int count = 0;
    for(int i = startingCard; i < startingCard + 5; i++) {
        if(countCard(hand, i) > 0)
            count++;
    }
    return count >= 5;
}





/*
    Takes an integer array hand as a parameter. Returns true if the hand
    contains five consecutive card values and false otherwise.
*/
bool containsStraight(const int hand[]) {
    bool flag = false;
    for(int i = LOWEST_NUM; i <= HIGHEST_NUM - 4; i++) { 
        if(checkNextFive(hand, i))
            flag = true;
    }
    return flag;
}





/*
    Takes an integer array hand as a parameter. Returns true if the hand
    contains a three of a kind and a pair and false otherwise.
*/
bool containsFullHouse(const int hand[]) {
    return containsThreeOfaKind(hand) && containsPair(hand);
}


/* OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 8
    Card 2: 7
    Card 3: 8
    Card 4: 2
    Card 5: 7
    Two Pair!

    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 8
    Card 2: 7
    Card 3: 4
    Card 4: 6
    Card 5: 5
    Straight!

    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 9
    Card 2: 2
    Card 3: 3
    Card 4: 4
    Card 5: 5
    High Card!

    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 3
    Card 2: 4
    Card 3: 3
    Card 4: 7
    Card 5: 8
    Pair!

    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 2
    Card 2: 2
    Card 3: 4
    Card 4: 4
    Card 5: 4
    Full house!

    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 5
    Card 2: 3
    Card 3: 5
    Card 4: 5
    Card 5: 5
    Four of a Kind!

    C:\Users\Niklas Leet\c++\cs-10b\assignment-4>.\a4_1.exe
    Enter 5 numeric cards, no face cards. Use numbers 2 - 9.
    Card 1: 5
    Card 2: 5
    Card 3: 5
    Card 4: 5
    Card 5: 5
    Four of a Kind!
*/