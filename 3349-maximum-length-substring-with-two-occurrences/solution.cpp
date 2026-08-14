class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int , int>mp ;
        int ans = 0 ;
        
        int j = 0 ;
        for(int i=0 ; i<s.length() ; i++){
            while(j< s.length() && mp[s[j]]  + 1 <= 2){
                mp[s[j]]++ ;
                j++ ;
            }
            ans = max(ans , j - i) ;
            mp[s[i]]-- ;
        }

        return ans ;
    }
};
