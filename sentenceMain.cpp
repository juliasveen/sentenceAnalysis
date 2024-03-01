#include <iostream>
#include <cstring>
#include <cctype>
#include "sentenceAnalysis.h" // Include your header file

using namespace std;

// Remove function declarations

int main() {
    // string defs    //extra 1 for null char
    char sentence[101], word[21], entry[101];

    int numWords = 0, numSpaces = 0, wordAmt = 0;
    // array def
    int wordLengths[21] = {0}; 
    // pointer def
    char *strPtr = nullptr;
    
    do
    {   // initialize to 0 at start of each loop 
        numWords = 0, numSpaces = 0, wordAmt = 0;
        strPtr = nullptr;
        
        cout << "Enter a sentence: ";
        cin.getline(sentence, 101);
    
        cout << "Enter a word: ";
        cin.getline(word, 21); 
        
        // calc num of words   
                        // strlen for c-strings
        for(int i = 0; i < strlen(sentence); i++)
        {
            if(isspace(sentence[i]))
            {
                numSpaces++;
                numWords = numSpaces + 1;
            } // 1 more word than spaces  
        }
        
        // word length table 
        for(int i = 0; i < 21; i++)
        {
            wordLengths[i] = 0; 
            wordAmt = 0;
        }
        for(int i = 0; i < strlen(sentence); i++)
        {
            if(!isspace(sentence[i]))
                wordAmt++;
            else
            {
                wordLengths[wordAmt]++;
                wordAmt = 0;
            }
            
        } // accts for last word
        wordLengths[wordAmt]++;
        
        cout << "\nSENTENCE ANALYSIS:" << "\n\n"; // func calls
        cout << "Punctuation Characters: " << numPunctMarks(sentence) << "\n";
        cout << "Vowels: " << numVowels(sentence) << "\n";
        cout << "Words: " << numWords << "\n";
        
        cout << "\nWord Lengths:" << "\n";
        // print out for word length table
        for(int i = 0; i < 21; i++)
        {   
            if(i == 1)
            {   // if one word char
                if(wordLengths[i] > 1)                          // if more than one word
                    cout << i << " character long: " << wordLengths[i] << " words.\n";
                if(wordLengths[i] == 1)
                    cout << i << " character long: " << wordLengths[i] << " word.\n";
            }                                                   // if just one word
            else if(i > 1)
            {   // if more than one char
                if(wordLengths[i] > 1)
                    cout << i << " characters long: " << wordLengths[i] << " words.\n";
                if(wordLengths[i] == 1)
                    cout << i << " characters long: " << wordLengths[i] << " word.\n";
            }
        }
        // verifying if word is in sentence
        // from pearson book
        strPtr = strstr(sentence, word); 
        
        for(int i = 0; i < strlen(sentence); i++)
        {
            strPtr = strstr(sentence, word);
            
            if(strPtr != nullptr)
                break;
        }
        
        if(strPtr != nullptr)
            cout << "\nThe word: \"" << word << "\" IS a part of the sentence you entered.\n";
        else
            cout << "\nThe word: \"" << word << "\" IS NOT part of the sentence you entered.\n";
        
        cout << "\nEnter another sentence/word for analysis (yes/no): ";
        cin >> entry;
        cin.ignore();
        cout << "\n";
        
        for(int i = 0; i < 4; i++) // accts for 4 chars 
        {              // makes entry all lowercase
            entry[i] = tolower(entry[i]); 
        }
        while(strcmp(entry, "yes") != 0 && strcmp(entry, "no") != 0)
        {    // strcmp to compare for c-strings
            cout << "Enter yes or no: ";
            cin.getline(entry, 101);
            
            for(int i = 0; i < 4; i++)
            {
                entry[i] = tolower(entry[i]);
            }
        }
    }while(strcmp(entry, "yes") == 0);
    
    if(strcmp(entry, "no") == 0)
        exit(0);
    
    return 0;
}

