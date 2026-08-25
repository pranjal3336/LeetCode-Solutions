class Solution {
public:
    int reverse(int x) {
        long long y = x ;
        long long a = abs(y) ;
        long long  ans = 0 ;

        while(a>0){
            long long  last = a%10 ;
            ans = ans*10 + last ;
            a= a/10 ;
        }

        if(ans <= INT_MAX && ans >= INT_MIN){
            if(x <0){
                return -1*ans ;
            }
            else{
                return ans ;
            }
        }

        return 0 ;

        
    }
};
