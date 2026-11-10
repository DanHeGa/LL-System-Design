#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    private:
        void collectWords(TrieNode* node, string prefix, vector<string> &results);
    public:
        vector<TrieNode*> children;
        bool isEnd;
        
        TrieNode();
        void insert(string word);
        vector<string> getRecommendations(string prefix);
};

#endif