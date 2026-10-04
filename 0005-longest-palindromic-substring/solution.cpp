class Solution {
public:
    bool isPalindrome(string &a , int l , int r){
        bool ans = true ;

        while(l<r){
            if(a[l] != a[r]){
                ans = false ;
                break ;
            }
            else{
                l++ ;
                r-- ;
            }
        }
        return ans ;
    }
    string longestPalindrome(string s) {
        int startidx = -1 ;
        int maxi = INT_MIN ;
        int n = s.length() ;

        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                if(isPalindrome(s , i , j)){
                    if(j-i+1 > maxi){
                        maxi = j-i+1 ;
                        startidx = i ;
                    }
                }
            }
        }

        return s.substr(startidx , maxi) ;
    }
};
