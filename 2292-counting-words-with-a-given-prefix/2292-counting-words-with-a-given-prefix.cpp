struct TrieNode {
TrieNode* child[26];
int freq=0;
}*trie;
class Solution {
public:
    void insert(string &s){
       TrieNode *top =trie;
       for(char ch:s){
          if(top->child[ch-'a']==nullptr)top->child[ch-'a']=new TrieNode();
          top=top->child[ch-'a'];
          top->freq++;
       }
    }
    int search(string &s){
       TrieNode *top =trie;
       for(char ch:s){
          if(top->child[ch-'a']==nullptr)return 0;
          top=top->child[ch-'a'];
     
       }
       return top->freq;
    }
    int prefixCount(vector<string>& words, string pref) {
        trie=new TrieNode();
        for(string word:words){
            insert(word);
        }
        return search(pref);
    }
};