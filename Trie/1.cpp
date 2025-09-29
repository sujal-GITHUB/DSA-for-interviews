// Trie Implementation

#include<bits/stdc++.h>
using namespace std;

class Node{
    Node* links[26];
    bool flag;

    public:

    Node(){
        for(int i=0; i<26; i++) 
        links[i] = nullptr;

        flag = false;
    }

    bool containsKey(char ch){
        return links[ch-'a'] != nullptr;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        this->flag = true;
    }
};

class Trie{
    Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix){
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }

            node = node->get(prefix[i]);
        }
        return true;
    }
};