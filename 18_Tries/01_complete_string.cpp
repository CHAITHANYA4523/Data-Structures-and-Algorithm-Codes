#include <bits/stdc++.h> 

struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private: Node *root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            //move to reference trie
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string prefix) {
        Node *node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(node->containsKey(prefix[i])){
                node = node->get(prefix[i]);
                if(node->isEnd() == false) return false; 
            }
            else return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &word : a){
        trie.insert(word);
    }
    string longest = "";
    for(auto &word : a){
        if(trie.checkIfPrefixExists(word)){
            if(longest.size() < word.size()){
                longest = word;
            }
            else if(longest.size() == word.size() && word < longest){
                longest = word;
            }
        }
    }
    if(longest == "") return "None";
    return longest;
}