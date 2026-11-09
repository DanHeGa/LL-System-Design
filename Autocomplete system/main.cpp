#include <string>
#include <fstream>
#include <iostream>
#include "AutoComplete.hpp"

using namespace std;

int main() {
    int inputType;
    cout << "File input or manual? File(1), manual(2)" << endl;
    cin >> inputType;

    bool fileInput = inputType == 1 ? true : false;
    if (fileInput) {
        ifstream file("input.txt");
        if (!file) {
            cerr << "Could not open input.txt" << endl;
            return 1;
        }

        int vocabSize;
        file >> vocabSize;
        
        string word;
        vector<string> vocab;
        for (int i = 0; i < vocabSize; i++) {
            file >> word;
            vocab.push_back(word);
        }

        int prefixQuant;
        string prefix;
        file >> prefixQuant;
        file >> prefix;

        //instance of trie
        TrieNode* root = new TrieNode();
        for (string w : vocab) {
            root->insert(w);
        }
        
        string currPrefix = "";
        for (char c : prefix) {
            currPrefix += c;
            vector<string> subRes = root->getRecommendations(currPrefix);
            if (subRes.size() > 3) subRes.resize(3); 
            for(int i = 0; i < 3; i++) {
                if (i == 2) {
                    cout << subRes[i];    
                } else {
                    cout << subRes[i] << ", ";
                }
            }
            cout << endl;
        }
    } else { //console input
        int vocabSize;
        cin >> vocabSize;

        vector<string> vocabulary;
        string newWord;
        for (int i = 0; i < vocabSize; i++) {
            cin >> newWord;
            vocabulary.push_back(newWord);
        }

        int prefixQuant;
        string prefix;
        cin >> prefixQuant;
        cin >> prefix;

        //instance of trie
        TrieNode* root = new TrieNode();
        for (string w : vocabulary) {
            root->insert(w);
        }
        
        string currPrefix = "";
        for (char c : prefix) {
            currPrefix += c;
            vector<string> subRes = root->getRecommendations(currPrefix);
            if (subRes.size() > 3) subRes.resize(3); //limit recommendations to 3
            for(int i = 0; i < 3; i++) {
                if (i == 2) {
                    cout << subRes[i];    
                } else {
                    cout << subRes[i] << ", ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}