#include<bits/stdc++.h>
using namespace std;

const int MAX = 27;

class TrieNode
{

    bool isEOW;
    TrieNode* children[MAX];

    friend class Trie;

public:
    TrieNode()
    {
        this->isEOW = false;
        for(int i=0;i<26;i++)
            this->children[i] = NULL;
    }
   
};

class Trie 
{

    TrieNode * t;
   
public: 
    Trie()
    {
        t =  new TrieNode();
    }

    void insert(string s) 
    {   
        TrieNode * temp = t;
        int i=0;

        for(int i=0;i<s.length();i++)   
        {
            int index = s[i]-'a';
            if(!temp->children[index])  {
                temp->children[index] = new TrieNode();
            }
            temp = temp->children[index];
        }
        temp->isEOW = true; 
    }

    bool search(string s)
    {
        TrieNode * temp = t;
        for(int i=0;i<s.length();i++)   
        {
            int index = s[i]-'a';

            if(!temp->children[index])   
                return false;
            
            temp = temp->children[index];
        }
        return (temp != NULL && temp->isEOW == true);
    }

};

int main()
{
    Trie  t =  Trie();
    t.insert("abc");
    t.insert("abcd");
    t.insert("acde");
    t.insert("aadf");
    cout << t.search("abc");
    cout << t.search("abcd");
    cout << t.search("abcdf");
}