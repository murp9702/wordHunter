#include <string>
#include <vector>
#include <iostream>
#include "Dictionary.h"
#include <algorithm>
#include <random>
#include <iostream>


class Board{
    private:
         char boardLetters[5][5];
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
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(numbers.begin(), numbers.end(), g);
            for (int i=0;i<5;++i) {
                keywords.push_back(dictionary.fiveLetterWords[numbers[i]]);
            }
        }
        void scrambleLetters() {
            // Take all the keywords and randomly assign all letters
            // to the 5x5 array boardLetters
            std::string concatString;
            for (const std::string& str : keywords) {
                concatString += str;
            }
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(concatString.begin(), concatString.end(), g);
            int index = 0;
            for (int i=0;i<5;++i) {
                for (int j=0;j<5;++j) {
                    boardLetters[i][j] = concatString[index];
                    ++index;
                }
            }
        }
        
        void findAllSolutions() {
            // Iterate over the Dictionary and build a trie data structure
        }
    public:
        Dictionary dictionary;
        std::vector<std::string> keywords;
        void drawBoard() {
            // Write the boardArray letters to stdout
            for (int i=0;i<5;++i) {
                for (int j=0;j<5;++j) {
                    std::cout << boardLetters[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        Board(Dictionary dict) {
            dictionary = dict;
            generateKeywords();
            scrambleLetters();
//            drawBoard();
        }
};