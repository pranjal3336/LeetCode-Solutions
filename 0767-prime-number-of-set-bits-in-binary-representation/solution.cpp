class Solution {
public:
    bool prime(int &n){
        for(int i=2 ; i<=sqrt(n) ; i++){
            if(n%i == 0){
                return false ;
            }
        }
        return true ;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0 ;
        for(int i = left ; i<= right ; i++){
            int x = __builtin_popcountll(i) ;
            if(x != 1 && prime(x)){
                ans++ ;
            }
        }
        return ans ;
    }
};
