/*
    Name: Niklas Leet
    Class: CS 10B
    Instructor: Dave Harden
    Name of file: a3_1.cpp
    Peers cited: Nikolas Brandt; provided advice on function organization

    Description: A guessing game in which the user thinks of a number
    between the upper and lower bounds (1 and 100) and the computer
    attempts to guess the number.
    
    Input: The user's decision to begin a new round or whether the number
    is higher, lower, or correct.
    Output: Prompts to ask the user about the accuracy of the guess or
    whether they would like to start a new game. 
*/

#include <iostream>

using namespace std;

const int LOWER_BOUND = 1;
const int UPPER_BOUND = 100;
void playOneGame();
void getUserResponseToGuess(int guess, char& result);
int getMidpoint(int low, int high);

int main() {
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
    return 0;
}






/*  
    Plays one round of the guessing game. Uses prompts and retrieves user input
    from getUserResponseToGuess() to move the upper and lower limits and 
    calculate the next guess. 
*/
void playOneGame() {
    cout << "Think of a number between " << UPPER_BOUND << " and " << LOWER_BOUND << ". I will try to guess it." << endl;
    
    char result;
    int guess = getMidpoint(LOWER_BOUND, UPPER_BOUND);
    int lowerLimit = LOWER_BOUND;
    int upperLimit = UPPER_BOUND;
    
    getUserResponseToGuess(guess, result);
    
     do {
        if (result == 'h') {
            lowerLimit = guess + 1;
        }  
        if (result == 'l') {
            upperLimit = guess - 1;
        }
        guess = getMidpoint(lowerLimit, upperLimit);
        getUserResponseToGuess(guess, result);
    } while(result != 'c');
}






/*
    Calculates the midpoint between the two numbers represented by the parameters,
    int low and int high.
*/
int getMidpoint(int low, int high) {
    return (high - low) / 2 + low;
}






/*
    Uses int guess to prompt the user with the guess and asks whether their number,
    is higher or lower. Stores their response in char& result. 
*/
void getUserResponseToGuess(int guess, char& result) {
    cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
    cin >> result;
    cout << endl;
}


/* OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-3.1>.\a.exe
    Ready to play (y/n)? y
    Think of a number between 100 and 1. I will try to guess it.
    My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 75. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 88. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l

    My guess is 81. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 84. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 86. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l

    My guess is 85. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c

    Great! Do you want to play again (y/n)? y
    Think of a number between 100 and 1. I will try to guess it.
    My guess is 50. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l

    My guess is 25. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 37. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 43. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: h

    My guess is 46. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: l

    My guess is 44. Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: c

    Great! Do you want to play again (y/n)? n
*/
