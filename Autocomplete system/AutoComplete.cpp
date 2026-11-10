#include "AutoComplete.hpp"

TrieNode::TrieNode()
    : children(26, nullptr), isEnd(false) {}

void TrieNode::insert(string word){
    TrieNode* curr = this;
        for (char c : word) {
            int cIdx = c - 'a';
            if (!curr->children[cIdx]) {
                curr->children[cIdx] = new TrieNode();
            }

            curr = curr->children[cIdx];
        }

        curr->isEnd = true;
}

vector<string> TrieNode::getRecommendations(string prefix){
    TrieNode* curr = this;
      for (char c : prefix) {
        int cIdx = c - 'a';

        if (!curr->children[cIdx]) {
          cout << "Prefix not found" << endl;
          return {}; //invalid prefix, because not even the prefix was found
        }

        curr = curr->children[cIdx];
      }

      vector<string> results;
      collectWords(curr, prefix, results);
      return results;
}

void TrieNode::collectWords(TrieNode* node, string prefix, vector<string> &results) {
    if(node->isEnd){ 
        results.push_back(prefix); 
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            collectWords(node->children[i], prefix + char('a' + i), results);
        }
    }

    return;
}