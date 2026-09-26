class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.length() ;
        if(numFriends == 1){
            return word ;
        }
        
        int l = n - (numFriends -1) ;
        string ans = "" ;
        int cantake ;
        for(int i=0 ; i<n ; i++){
            cantake  = min(l , n-i) ;
            ans = max(ans , word.substr(i , cantake)) ;

        }
        return ans ;
    }
};
