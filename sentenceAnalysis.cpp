#include "sentenceAnalysis.h"
#include <cstring>
#include <cctype>

int numPunctMarks(char sentence[]) {
    int punctMarks = 0;
    
    for(int i = 0; i < strlen(sentence); i++) {
        if(ispunct(sentence[i])) 
            punctMarks++;
    }
    return punctMarks;
}

int numVowels(char sentence[]) {
    int vowels = 0;
    
    for(int i = 0; i < strlen(sentence); i++) {
        char entrdSent = sentence[i];
        if(isalpha(entrdSent)) {
            entrdSent = tolower(entrdSent);
            if(entrdSent == 'a' || entrdSent == 'e' || 
               entrdSent == 'i' || entrdSent == 'o' || entrdSent == 'u')
                vowels++;
        }
    }
    return vowels;
}
