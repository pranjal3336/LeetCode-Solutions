class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string , char > mp ;
        int n = pattern.length() ;
        vector<string> words;    // Yeh aapka array of strings banega
        stringstream ss(s);      // String s ko stream mein convert karega
        string tempWord;

        // Stream se ek-ek word nikal kar array (vector) mein daalna
        while (ss >> tempWord) {
            words.push_back(tempWord);
        }

        if(pattern.length() != words.size()){
            return false ;
        }

        set<char>used ;

        for(int i = 0 ; i< n ; i++){
           string word = words[i] ;
           char ch     = pattern[i] ;

           if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
              mp[word] = ch ;
              used.insert(ch) ;
           }
           else if(mp[word] != ch){
            return false ;
           }
        }

        return true ;

        
    }
};
