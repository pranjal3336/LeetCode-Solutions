class Solution {
public:
    struct trieNode{
        bool isEndOfWord ;
        trieNode* children[26] ;
    } ;

    trieNode* getNode(){
        trieNode* newNode = new trieNode() ;
        newNode -> isEndOfWord = false ;
        for(int i=0 ; i<26 ; i++){
            newNode -> children[i] = NULL;
        }

        return newNode ;
    }

    void insert(trieNode* root , string &word){
        trieNode* crawler = root ;

        for(int i=0 ; i<word.length() ; i++){
            char ch = word[i] ;
            int idx = ch - 'a' ;

            if(crawler -> children[idx] == NULL){
                crawler -> children[idx] = getNode() ;
            }

            crawler = crawler -> children[idx] ;
        }

        crawler -> isEndOfWord = true ;
    }

    void prefix(trieNode* root , string &ans){
        trieNode* crawler = root ;

        while(crawler -> isEndOfWord != true){//end of word nhi hona chahiye 
            int idx ;
            int cnt = 0  ;

            for(int i=0 ; i<26 ; i++){
                if(crawler->children[i] != NULL){
                    cnt++ ;
                    idx = i ;
                }
            }
            //one child hi hone chahiye longest prefix ke liye 
            if(cnt == 1){
                ans.push_back('a' + idx);
                crawler = crawler -> children[idx] ;
            }
            else{//vrna break kr denge 
                break ;
            }

        }
    }
    string longestCommonPrefix(vector<string>& strs) {
        // trieNode* root = getNode() ;

        // for(string &word : strs){
        //     insert(root , word) ;
        // }

        // string ans = "" ;

        // prefix(root , ans) ;

        // return ans ;

        sort(strs.begin() , strs.end()) ;
        int n = strs.size() ;

        string ans = "" ;
        int i = 0 ;
        int j = 0 ; 
        string a = strs[0] ;
        string b = strs[n-1] ;
        while(i< a.length() && j < b.length()){
            if(a[i] == b[j]){
                ans.push_back(a[i]) ;
                i++ ; 
                j++ ;
            }
            else{
                break ;
            }
           
        }

        return ans ;


        
    }
};
