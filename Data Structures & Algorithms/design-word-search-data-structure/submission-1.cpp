class TrieNode {
    public:
        TrieNode* children[26];
        bool endOfWord;

        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
            endOfWord = false;
        }
};
class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c: word){
            int i = c-'a';
            if(curr->children[i] == nullptr){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
       return dfs(word, 0, root);
    }
private: 
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* curr = root;
        for(int i=j;i<word.size();i++){
            char c = word[i];
            if(c == '.'){
                for(int k=0;k<26;k++){
                   if(curr->children[k] != nullptr && dfs(word, i+1, curr->children[k])){
                        return true;
                   }
                }
                return false;
            }
            else {
                if(curr->children[c-'a'] == nullptr){
                    return false;
                }
                curr = curr->children[c-'a'];
            }
        }
        return curr->endOfWord;
    }
};
