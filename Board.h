#include <string>
#include <vector>
#include <iostream>
#include "Dictionary.h"


class Board{
    private:

        // std::vector<char> boardLetters[5][5];
        // std::vector<std::string> solutions;
        // int keywordsRemaining = 5;
        // int pointTotal = 0;


        void generateKeywords() {
            int numberOfFiveLetterWords = dictionary.fiveLetterWords.size();
            std::vector<int> numbers(numberOfFiveLetterWords);
            
            // build a basic random number generator
            for (int i=0;i<numberOfFiveLetterWords;++i) {
                numbers[i] = i;
            }
            std::random_shuffle(numbers.begin(), numbers.end());
            for (int i=0;i<5;++i) {
                int randomNumber = numbers[i];
                keywords.push_back(dictionary.fiveLetterWords[numbers[i]]);
            }
        }
        
        void findAllSolutions() {
            // Iterate over the Dictionary and build a trie data structure
        }
        // void scrambleLetters(std::vector<std::string> keywords) {
        //     // Take all of the keywords and randomly assign all letters 
        //     // to the 5x5 array boardLetters
        // }
    public:
        Dictionary dictionary;
        std::vector<std::string> keywords;
        void drawBoard() {
            // Write the boardArray letters to stdout
        }
        Board(Dictionary dict) {
            dictionary = dict;
            generateKeywords();
        }
};