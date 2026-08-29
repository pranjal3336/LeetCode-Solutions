class Solution {
public:
    int mySqrt(int x) {
        // if(x == 1) return 1 ;
        // if(x ==0) return 0 ;
        // long long  sqr = 0 ;
        // for(long long i =1 ; i*i<=x; i++){
        //    sqr = i ;
        // }

        // return (int)sqr ;

        int l = 0 ;
        int r = x ;

        int mid = (l+r)/2 ;
        int result = 0 ;
        while(l<=r){
            long long sqr = 1LL * mid *mid ;

            if(sqr == x){
                result = mid ;
                break ;
            }
            else if(sqr <x){
                result = mid ;
                l = mid+1 ;
            }
            else{
                r = mid -1 ;
            }

            mid = (l+r)/2 ;

        }

        return result ;
    }
};
