class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length() ;
        int maxlen = 0 ;
        
        unordered_map<char , int>mp ;
        int i = 0 ;
        int j = 0 ;
        int max_freq = 0 ;
        while(j<n){
            mp[s[j]]++ ;
            max_freq = max(max_freq , mp[s[j]]) ;
            // Agar window invalid ho jaye (total chars - max repeating char > k)
            if( (j-i+1) - max_freq > k ){
                mp[s[i]]-- ;
                
                i++ ;
            } 
            // Ab window valid hai, maxlen update kar lo
            maxlen = max(maxlen , j-i+1) ;
            j++ ;
        }
        return maxlen ;
    }
};
