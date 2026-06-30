class Solution {
public:
    int numberOfSubstrings(string s) {

        //yeh optimal approach nhi hai 
        // unordered_map<char , int>mp ;
        // int cnt =0 ;
        // int cnt1 = 0 ;
        // for(int i=0 ; i<s.length(); i++){
        //     string temp = "";
        //     for(int j=i ; j<s.length() ; j++){
        //         temp+=s[j] ;
        //         mp[s[j]]++ ;
        //         cnt1++ ;
        //         if(temp.length() < 3 || mp['a'] <1 || mp['b'] <1 || mp['c'] <1){
        //             cnt++ ;
        //         }
        //     }
        //     mp['a'] = 0 ;
        //     mp['b'] =0 ;
        //     mp['c'] =0 ;
            
        // }

        // return cnt1 - cnt ;

        int last_seen[3] = {-1 , -1 ,-1} ;
        int cnt = 0 ;

        for(int i=0 ; i<s.length() ; i++){

            last_seen[s[i] - 'a'] = i ;

            if(last_seen[0] != -1 &&  last_seen[2] != -1 && last_seen[2] != -1 ){
                int mini = min(last_seen[0] , min(last_seen[1] , last_seen[2])) ;
                cnt += (mini+1) ;
            }
        }

        return cnt ;
    }
};
