//
// Created by brennen on 7/21/24.
//

#ifndef WORDHUNTER_KEYWORDS_H
#define WORDHUNTER_KEYWORDS_H

#include "Words.h"

class Keywords : public Words {
public:
    bool foundKeyword;
    Keywords(std::string &word) : Words(word){
        foundKeyword = false;
        word = word;
    }
};


#endif //WORDHUNTER_KEYWORDS_H
