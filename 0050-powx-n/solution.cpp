class Solution {
public:
    double myPow(double x, int n) {
       //base case
       if( x==1 || n==0){
        return 1 ;
       }

       if(n<0){
        if(n== INT_MIN){
            return 1/(myPow(x , INT_MAX)*x) ;
        }
        else{
            return 1/myPow(x , -n);
        }
       }

    double half = myPow(x , n/2);
    if(n%2==0){
        return half*half ;
    }
    else{
        return x*half*half ;
    }
    


    }
};
