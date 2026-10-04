class Solution {
public:
    bool check(string &a , string &b){
        if(a.length() > b.length()){
            return false ;
        }

        int idx1  = b.find(a) ;
       

        int idx2 = b.rfind(a) ;

        if(idx1 == 0 &&  idx2+a.length() == b.length()){
            return true ;
        }
        return false ;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size() ;
        int cnt = 0 ;
        for(int i=0 ; i<n ; i++){
            for(int j= i+1 ; j<n ; j++){
                if(check(words[i] , words[j])){
                    cnt++ ;
                }
            }
        }
        return cnt ;
    }
};
