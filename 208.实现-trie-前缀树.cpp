/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trienode{
public:
    Trienode *child[26];
    bool isval;
    Trienode():isval(false){
        for(auto &x : child){
            x = nullptr;
        }
    }
};

class Trie {
public:
    Trienode *root;
    /** Initialize your data structure here. */
    Trie():root(new Trienode()) {};
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trienode *temp = root;
        for(auto x : word){
            int index = x-'a';
            if(!temp->child[index]){
                temp->child[index]= new Trienode();
            }
            temp=temp->child[index];
        }
        temp->isval=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trienode *temp = root;
        for(auto x : word){
            if(!temp) return false;
            temp=temp->child[x-'a'];
        }
        return temp ? temp->isval : false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trienode *temp=root;
        for(auto x : prefix){
            if(!temp) return false;
            temp=temp->child[x-'a'];
        }
        return temp;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

