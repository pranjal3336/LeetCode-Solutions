class Solution {
public:
    bool allzero(vector<int>&count){
      for(int &i : count){
          if(i!= 0){
              return false ;
          }
      }
      return true ;
  }
    vector<int> findAnagrams(string txt, string pat) {
        int k = pat.length() ;
        vector<int>count(26 , 0) ;
        for(int i =0  ; i<k ; i++){
            char ch = pat[i] ;
            count[ch - 'a']++ ;
            
        }
        
        int i = 0 ;
        int j = 0 ;
        int n = txt.length() ;
        vector<int>ans ;
        while(j<n){
            count[txt[j] - 'a']-- ;
            if(j-i+1 == k){
                if(allzero(count)){
                    ans.push_back(i) ;
                }
                
                count[txt[i] - 'a']++ ;
                i++ ;
            }
            
            j++ ;
        }
        
        return ans ;
    }
};
