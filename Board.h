#include <string>
#include <vector>
#include <iostream>
#include "Dictionary.h"
#include <algorithm>
#include <random>
#include <iostream>

#include "Keywords.h"
#include "Trie.h"


class Board{
    private:
         char boardLetters[5][5];
        // std::vector<std::string> solutions;
        // int keywordsRemaining = 5;
        // int pointTotal = 0;
        Trie dictionaryTrie;
        std::vector<std::vector<bool>> visited;


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
                Keywords* newKeyword = new Keywords(dictionary.fiveLetterWords[numbers[i]]);
                keywords.push_back(newKeyword);
                std::cout << newKeyword->word << std::endl;
            }
//            for (const std::string& keyword : keywords) {
//                dictionaryTrie.insert(keyword);
//            }
        }
        void scrambleLetters() {
            // Take all the keywords and randomly assign all letters
            // to the 5x5 array boardLetters
            std::string concatString;
            for (auto& keyword : keywords) {
                for (const char& c : keyword->word) {
                    concatString += c;
                }
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
        
        void buildTrie() {
             for (const auto &pair : dictionary.dictionary) {
                 std::string word = pair.second->word;
                 dictionaryTrie.insert(word);
             }
        }




    public:
        Dictionary dictionary;
        std::vector<Keywords*> keywords;
        int keywordsRemaining = 5;
        void drawBoard() {
            // Write the boardArray letters to stdout
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    std::cout << boardLetters[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
    bool checkWord(std::string word) {
        // Check if the word is in the dictionary
        // If it is, mark the keyword as found
        for (auto& keyword : keywords) {
            if (keyword->word == word) {
                keyword->foundKeyword = true;
                return true;
            }
        }
        return false;
    }
        Board(Dictionary dict) {
            dictionary = dict;
            visited = std::vector<std::vector<bool>>(5, std::vector<bool>(5, false));
            generateKeywords();
            scrambleLetters();
            buildTrie();
        }
};