//
// Created by brennen on 7/21/24.
//

#ifndef WORDHUNTER_WORDS_H
#define WORDHUNTER_WORDS_H


class Words {
public:
    bool isKeyword = false;
    std::string word;
    Words(std::string &word) {
        this->word = word;
    }

};


#endif //WORDHUNTER_WORDS_H
