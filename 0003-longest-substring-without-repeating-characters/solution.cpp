class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>mp ;
        int n = s.length() ;
        if(n==0){
            return 0 ;
        }
        int ans = INT_MIN ;
        int j = 0 ;
        for(int i=0 ; i<n ; i++){
            while(j<n && mp[s[j]] == 0){//yaani voh character nhi h phle se map mai tbhi include krenge
                mp[s[j]]++ ;
                j++ ;
            }
            ans = max(ans , j-i) ;
            mp[s[i]]-- ;
        }
        return ans ;
        
    }
};
