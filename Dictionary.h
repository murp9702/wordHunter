#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Words.h"
#include "Keywords.h"



class Dictionary {
    private:
        void parseCSV(){
            std::ifstream file("../formatted_dictionary.csv");
            if (!file.is_open()) {
                std::cout << "Failed to open file" << std::endl;
            }
            std::string line, value;
            int key = 0;
            std::map<int, Words*> dictionaryMap;

            while (std::getline(file, line)) {
                std::stringstream ss(line);
                std::getline(ss, value, ',');
                Words* newWord = new Words(value);
                dictionaryMap[key] = newWord;
                ++key;
            }
            file.close();
            dictionary = dictionaryMap;

        }
                
        void findFiveLetterWords(){
            for (const auto &word : dictionary) {
                if (word.second->word.length() == 5){

                    fiveLetterWords.push_back(word.second->word);
                }
            }
            std::sort(fiveLetterWords.begin(), fiveLetterWords.end());
        }
    public:
        std::map<int, Words*> dictionary;
        std::vector<std::string> fiveLetterWords;
        
        Dictionary() {
            parseCSV();
            findFiveLetterWords();
        };

};
#endif // DICTIONARY_H