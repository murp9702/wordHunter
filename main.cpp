#include "Dictionary.h"
#include "Board.h"
#include <string>
#include <map>


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
    board.drawBoard();

    return 0;
}