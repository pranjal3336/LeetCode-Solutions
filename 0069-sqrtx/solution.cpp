class Solution {
public:
    int mySqrt(int x) {
        if(x == 1) return 1 ;
        if(x ==0) return 0 ;
        long long  sqr = 0 ;
        for(long long i =1 ; i*i<=x; i++){
           sqr = i ;
        }

        return sqr ;
    }
};
