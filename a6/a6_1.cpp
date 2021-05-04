#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>

using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
void toupper(char* inString);
int numLetters(const char* inString);
bool isPalindrome(const char* inString);


int main() {
    char result;

    cout << "Testing lastIndexOf()..." << endl;
    
    // tests for no target
    char lioSample1[] = "alphabet";
    char target = 'z';
    int lioOutput = lastIndexOf(lioSample1, target);
    if(lioOutput == -1)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "lastIndexOf() returns -1 when the target is not present in the c-string" 
        << "\n\tTarget: " << target << "\n\tOriginal string: " << lioSample1 
        << "\n\tOutput: " << lioOutput << endl;

    // tests for one target
    target = 'l';
    lioOutput = lastIndexOf(lioSample1, target);
    if(lioOutput == 1)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "lastIndexOf() returns 1 when the target appears once in the c-string"
        << "\n\tTarget: " << target << "\n\tOriginal string: " << lioSample1 
        << "\n\tOutput: " << lioOutput << endl;

    // tests for two targets
    target = 'a';
    lioOutput = lastIndexOf(lioSample1, target);
    if(lioOutput >= 2)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "lastIndexOf() returns an int greater than 1 when the target is present multiple times in the c-string" 
        << "\n\tTarget: " << target << "\n\tOriginal string: " << lioSample1 
        << "\n\tOutput: " << lioOutput << endl;


    cout << endl << "Testing reverse()..." << endl;
    
    // tests an even-length string
    char reverseSample1[] = "flower";
    char reverseAnswer1[] = "rewolf";
    char reverseOutput1[strlen(reverseSample1)];
    strcpy(reverseOutput1, reverseSample1);
    reverse(reverseOutput1);
    if(strcmp(reverseOutput1, reverseAnswer1) == 0)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "reverse() reverses a c-string with an even number of characters" 
        << "\n\tOriginal string: " << reverseSample1 << "\n\tResult: " 
        << reverseOutput1 << endl;

    // tests an odd-length string
    char reverseSample2[] = "galleon";
    char reverseAnswer2[] = "noellag";
    char reverseOutput2[strlen(reverseSample2)];
    strcpy(reverseOutput2, reverseSample2);
    reverse(reverseOutput2);
    if(strcmp(reverseOutput2, reverseAnswer2) == 0)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "reverse() reverses a c-string with an odd number of characters" 
        << "\n\tOriginal string: " << reverseSample2 << "\n\tResult: " 
        << reverseOutput2 << endl;

   
    cout << endl << "Testing replace()..." << endl;
    
    // replaces alpha chars in a string
    char replaceSample1[] = "Lo and behold";
    target = 'o';
    char replacementChar = 'e';
    char replaceAnswer1[] = "Le and beheld";
    char replaceOutput1[strlen(replaceSample1)];
    strcpy(replaceOutput1, replaceSample1);
    int numReplacements1 = replace(replaceOutput1, target, replacementChar);
    if(strcmp(replaceOutput1, replaceAnswer1) == 0)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "replace() replaces a target alpha char with a replacement alpha char" 
        << "\n\tTarget char: '" << target << "'\n\tReplacement char: '" 
        << replacementChar << "'\n\tOriginal string: " << replaceSample1 
        << "\n\tResult: " << replaceOutput1
        << "\n\tReplacements: " << numReplacements1 << endl;

    // replaces symbol chars in a string
    char replaceSample2[] = "Take away the space";
    target = ' ';
    replacementChar = '-';
    char replaceAnswer2[] = "Take-away-the-space";
    char replaceOutput2[strlen(replaceSample2)];
    strcpy(replaceOutput2, replaceSample2);
    int numReplacements2 = replace(replaceOutput2, target, replacementChar);
    if(strcmp(replaceOutput2, replaceAnswer2) == 0)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "replace() replaces a target space char with a replacement symbol char" 
        << "\n\tTarget char: '" << target << "'\n\tReplacement char: '" 
        << replacementChar << "'\n\tOriginal string: " << replaceSample2 
        << "\n\tResult: " << replaceOutput2
        << "\n\tReplacements: " << numReplacements2 << endl;


    cout << endl << "Testing isPalindrome()..." << endl;
    
    // tests an even-length palindrome
    char palindromeSample1[] = "abba";
    if(isPalindrome(palindromeSample1))
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "palindrome() checks an even-length palindrome" 
        << "\n\tOriginal string: " << palindromeSample1 << endl;

    // tests an odd-length palindrome
    char palindromeSample2[] = "racecar";
    if(isPalindrome(palindromeSample2))
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "palindrome() checks an odd-length palindrome" 
        << "\n\tOriginal string: " << palindromeSample2 << endl;

    // tests a palindrome with punctuation and spaces
    char palindromeSample3[] = "? ! . , , . ! ?";
    if(isPalindrome(palindromeSample2))
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "palindrome() checks a palindrome with punctuation and spaces" 
        << "\n\tOriginal string: " << palindromeSample3 << endl;

    // tests a palindrome with capitalization
    char palindromeSample4[] = "RePaper";
    if(isPalindrome(palindromeSample4))
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "palindrome() ignores capitalization in a palindrome" 
        << "\n\tOriginal string: " << palindromeSample4 << endl;

    // tests for a negative case
    char palindromeSample5[] = "Tubular";
    if(!isPalindrome(palindromeSample5))
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "palindrome() returns false for a string that is not a palindrome" 
        << "\n\tOriginal string: " << palindromeSample5 << endl;

    cout << endl << "Testing toupper()..." << endl;
    
    // tests an alpha-only string 
    char toUpperSample1[] = "anger";
    char toUpperAnswer1[] = "ANGER";
    char toUpperOutput1[strlen(toUpperSample1)];
    strcpy(toUpperOutput1, toUpperSample1);
    toupper(toUpperOutput1);
    if(strcmp(toUpperOutput1, toUpperAnswer1) == 0)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "toupper() converts an alpha-only c-string to uppercase" 
        << "\n\tOriginal string: " << toUpperSample1 << "\n\tResult: " 
        << toUpperOutput1 << endl;

    // tests string with symbols and spaces 
    char toUpperSample2[] = "I'm not angry at all, what do you mean?";
    char toUpperAnswer2[] = "I'M NOT ANGRY AT ALL, WHAT DO YOU MEAN?";
    char toUpperOutput2[strlen(toUpperSample2)];
    strcpy(toUpperOutput2, toUpperSample2);
    toupper(toUpperOutput2);
    if(strcmp(toUpperOutput2, toUpperAnswer2) == 0)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "toupper() converts the alpha characters in a c-string with symbols and spaces to uppercase" 
        << "\n\tOriginal string: " << toUpperSample2 << "\n\tResult: " 
        << toUpperOutput2 << endl;


    cout << "\nTesting numLetters()..." << endl;
    
    // counts letters in a string with spaces
    char numLetSample1[] = "There are twenty five letters";
    int numLetAnswer1 = 25;
    int numLettersOutput = numLetters(numLetSample1);
    if(numLettersOutput == numLetAnswer1)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "numLetters() counts the number of letters in a string with spaces" 
        << "\n\tOriginal string: " << numLetSample1 << "\n\tAnswer: " << numLetAnswer1
        << "\n\tOutput: " << numLettersOutput << endl;

    // counts letters in a string with symbols and numbers
    char numLetSample2[] = "A123-*++B,,.CD";
    int numLetAnswer2 = 4;
    numLettersOutput = numLetters(numLetSample2);
    if(numLettersOutput == numLetAnswer2)
        result = 'Y';
    else result = 'N';
    cout << "[ " << result << " ] " << "numLetters() counts the number of letters in a string with symbols and numbers" 
        << "\n\tOriginal string: " << numLetSample2 << "\n\tAnswer: " << numLetAnswer2
        << "\n\tOutput: " << numLettersOutput << endl;

    return 0;
}






// returns the last index where a char, target, can be found in a c-string, inString 
int lastIndexOf(const char* inString, char target) {
    int i = 0;
    int targetIndex = -1;
    while(inString[i] != '\0') {
        if(inString[i] == target)
            targetIndex = i;
        i++;
    }
    return targetIndex;
}






// reverses the characters in the string, inString
void reverse(char* inString) {
    int strLength = strlen(inString);
    for(int i = 0; i < strLength / 2; i++) {
        swap(inString[i], inString[strLength - 1 - i]);
    }
}





/*
    Replaces all instances of the target character, target, in a string, 
    inString, with a replacement character, replacement char and returns
    the number of times the method replaced a character
*/
int replace(char* inString, char target, char replacementChar) {
    int i = 0;
    int replacements = 0;
    while(inString[i] != '\0') {
        if(inString[i] == target) {
            inString[i] = replacementChar;
            replacements++;
        }
        i++;
    }
    return replacements;
}






// changes all letters in the string, inString, to uppercase
void toupper(char* inString) {
    int i = 0;
    while(inString[i] != '\0') {
        if(isalpha(inString[i]))
            inString[i] = toupper(inString[i]);
        i++;
    }
}






// returns the number of letters in a string, inString
int numLetters(const char* inString) {
    int i = 0;
    int count = 0;
    while(inString[i] != '\0') {
        if(isalpha(inString[i]))
            count++;
        i++;
    }
    return count;
}






// checks if the string, inString, is a palindrome, ignoring character case
bool isPalindrome(const char* inString) {
    int strLength = strlen(inString);
    bool isPalindrome = true;
    for(int i = 0; i < strLength / 2; i++) {
        if(tolower(inString[i]) != tolower(inString[strLength - 1 - i]))
            isPalindrome = false; 
    }
    return isPalindrome;
}

/* OUTPUT:
    C:\Users\Niklas Leet\c++\cs-10b\assignment-6>.\a6_1.exe
    Testing lastIndexOf()...
    [ Y ] lastIndexOf() returns -1 when the target is not present in the c-string
            Target: z
            Original string: alphabet
            Output: -1
    [ Y ] lastIndexOf() returns 1 when the target appears once in the c-string
            Target: l
            Original string: alphabet
            Output: 1
    [ Y ] lastIndexOf() returns an int greater than 1 when the target is present multiple times in the c-string
            Target: a
            Original string: alphabet
            Output: 4

    Testing reverse()...
    [ Y ] reverse() reverses a c-string with an even number of characters
            Original string: flower
            Result: rewolf
    [ Y ] reverse() reverses a c-string with an odd number of characters
            Original string: galleon
            Result: noellag

    Testing replace()...
    [ Y ] replace() replaces a target alpha char with a replacement alpha char
            Target char: 'o'
            Replacement char: 'e'
            Original string: Lo and behold
            Result: Le and beheld
            Replacements: 2
    [ Y ] replace() replaces a target space char with a replacement symbol char
            Target char: ' '
            Replacement char: '-'
            Original string: Take away the space
            Result: Take-away-the-space
            Replacements: 3

    Testing isPalindrome()...
    [ Y ] palindrome() checks an even-length palindrome
            Original string: abba
    [ Y ] palindrome() checks an odd-length palindrome
            Original string: racecar
    [ Y ] palindrome() checks a palindrome with punctuation and spaces
            Original string: ? ! . , , . ! ?
    [ Y ] palindrome() ignores capitalization in a palindrome
            Original string: RePaper
    [ Y ] palindrome() returns false for a string that is not a palindrome
            Original string: Tubular

    Testing toupper()...
    [ Y ] toupper() converts an alpha-only c-string to uppercase
            Original string: anger
            Result: ANGER
    [ Y ] toupper() converts the alpha characters in a c-string with symbols and spaces to uppercase
            Original string: I'm not angry at all, what do you mean?
            Result: I'M NOT ANGRY AT ALL, WHAT DO YOU MEAN?

    Testing numLetters()...
    [ Y ] numLetters() counts the number of letters in a string with spaces
            Original string: There are twenty five letters
            Answer: 25
            Output: 25
    [ Y ] numLetters() counts the number of letters in a string with symbols and numbers
            Original string: A123-*++B,,.CD
            Answer: 4
            Output: 4
*/