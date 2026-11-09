#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        vector<string> collectWords(TrieNode* node, string prefix);
    public:
        vector<TrieNode*> children;
        bool isEnd;
        
        TrieNode();
        void insert(string word);
        vector<string> getRecommendations(string prefix);
};

#endif