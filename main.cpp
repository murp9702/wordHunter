#include "Dictionary.h"
#include "Board.h"
#include "Trie.h"
#include <string>
#include <map>
void printIntroduction() {
    std::cout << "Welcome to WordHunter!" << std::endl;
    std::cout << "The goal of the game is to find all the hidden words in the 5x5 board." << std::endl;
    std::cout << "You can enter the words you find in the console." << std::endl;
    std::cout << "Good luck!" << std::endl;
    std::cout << "Press enter to continue..." << std::endl;
    std::string input;
    std::getline(std::cin, input); //wait for user to press enter
    // Clear the console
    for(int i = 0; i < 50; i++) {
        std::cout << std::endl;
    }
}

int main() {
    Dictionary dict;
    Board board(dict);

    // board.generateKeywords();
    // for (const auto &words : dict.dictionary) {
    //     std::cout << "Key: " << words.first << " Value: " << words.second << std::endl;
    // }
    // dict.findFiveLetterWords();
    // for (const auto &fiveLetter : dict.fiveLetterWords) {
    //     std::cout << fiveLetter << std::endl;
    // }
//    for (const auto &keyword : board.keywords) {
//        std::cout << keyword << std::endl;
//    }
    printIntroduction();
    board.drawBoard();
    while(board.keywordsRemaining > 0) {
        std::string input;
        std::cout << "Enter a word: ";
        std::cin >> input;
        if(board.checkWord(input)) {
            std::cout << "Correct!" << std::endl;
            board.keywordsRemaining--;
            std::cout << board.keywordsRemaining << " keywords remaining." << std::endl;
        } else {
            std::cout << "Incorrect!" << std::endl;
            std::cout << board.keywordsRemaining << " keywords remaining." << std::endl;
        }
    }

    return 0;
}