class Trie {
public:
    struct trieNode{
        bool isEndOfWord ;
        trieNode* children[26] ;

    };

    trieNode * getNode(){
        trieNode* newNode = new trieNode() ;
        newNode -> isEndOfWord = false ;

        for(int i=0 ; i<26 ; i++){
            newNode -> children[i] = NULL ;
        }

        return newNode ;

    }

    trieNode * root ;
    Trie() {
        root = getNode() ;
    }
    
    void insert(string word) {//apple
        trieNode* crawler = root ;
        for(int i=0 ; i<word.length() ; i++){//har char ko check krenge like a then p soon 
            char ch = word[i] ;
            int idx = ch - 'a';

            if(crawler -> children[idx] == NULL){
                crawler -> children[idx] = getNode() ;
            }

            crawler = crawler -> children[idx] ;
        }

        crawler -> isEndOfWord = true ;//jab e pr aayga hai toh word end ko true mark krenge 
    }
    
    bool search(string word) {
        trieNode* crawler = root ;
        for(int i=0 ; i<word.length() ; i++){//har char ko check krenge like a then p soon 
            char ch = word[i] ;
            int idx = ch - 'a';

            if(crawler -> children[idx] == NULL){
               return false ;
            }

            crawler = crawler -> children[idx] ;
        }

        if(crawler != NULL && crawler -> isEndOfWord == true){
            return true ;
        }

        return false ;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root ;
        for(int i=0 ; i<prefix.length() ; i++){//har char ko check krenge like a then p soon 
            char ch = prefix[i] ;
            int idx = ch - 'a';

            if(crawler -> children[idx] == NULL){
               return false ;
            }

            crawler = crawler -> children[idx] ;
        }

        return true ;

    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
