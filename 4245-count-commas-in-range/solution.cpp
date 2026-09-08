class Solution {
public:
    int countCommas(int n) {
        // if(n<1000){
        //     return 0 ;
        // }
        // int m = n ;
        // int l = 0 ;
        // while(m>0){
        //     l++ ;
        //     m/=10 ;
        // }
        // int x  ;
        // if(l%3 != 0){
        //     x = l/3 ;
        // }
        // else{
        //     x = l/3 -1 ;
        // }

        // return (n-1000+1)*x ;//yaani (n-999)*x ;

        //method 2 
        long long  ans = 0 ;
        if(n>=1000){
            ans+=(n -999) ;
        }
        if(n>=1000000){
            ans+=(n -999999) ;
        }
        if(n>=1000000000){
            ans+=(n -999999999) ;
        }
        return ans ;
    }
};
