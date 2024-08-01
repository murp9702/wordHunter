//
// Created by brennen on 7/24/24.
//

#ifndef WORDHUNTER_TRIE_H
#define WORDHUNTER_TRIE_H


class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }
    TrieNode* getRoot() {
        return root;
    }

    void insert(std::string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool search(std::string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return (node != nullptr && node->isEndOfWord);
    }
};

#endif //WORDHUNTER_TRIE_H
