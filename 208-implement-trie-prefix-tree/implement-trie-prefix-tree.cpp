class TrieNode{
public:
    TrieNode *children[26];
    bool endofword;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        endofword=false;
    }
};
class Trie{
    TrieNode *root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur=root;
        for(char c:word){
            if(cur->children[c-'a']==nullptr){
                cur->children[c-'a']=new TrieNode;
            }
            cur=cur->children[c-'a'];
        }
        cur->endofword=true;
    }
    
    bool search(string word) {
        TrieNode *cur=root;
        for(char c:word){
            if(cur->children[c-'a']==nullptr){
                return false;
            }
            cur=cur->children[c-'a'];
        }
        return cur->endofword;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur=root;
        for(char c:prefix){
            if(cur->children[c-'a']==nullptr){
                return false;
            }
            cur=cur->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */