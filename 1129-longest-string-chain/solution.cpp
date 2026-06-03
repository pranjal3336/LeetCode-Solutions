class Solution {
public:
    bool check(string &s1 , string &s2){
        if(s1.length()+1 != s2.length()){
            return false ;
        }

        int first = 0 ;
        int second = 0 ;

        while( second < s2.length()){
            if(s1[first] == s2[second]){
                first++ ;
                second++ ;
            }
            else{
                second++ ;
            }
        }

        if(first == s1.length() && second == s2.length()){
            return true ;
        }
        else{
            return false ;
        }
    }
    static bool cmp(string& s1 , string& s2){
        return s1.length() < s2.length() ;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size() ;
        vector<int>dp(n, 1) ;
        sort(words.begin() , words.end() , cmp) ;
        int maxi = 1 ;
        for(int i =0 ; i<n ; i++){
            for(int prev = 0 ; prev <i ; prev++){
                if(check(words[prev] , words[i]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev] ;
                }
            }
            maxi = max(dp[i] , maxi) ;
        }

        return maxi ;
    }
};
