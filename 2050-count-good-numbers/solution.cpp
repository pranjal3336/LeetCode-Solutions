class Solution {
private:
long long value = 1e9+7 ;
long long  myPow(long long x, long long n) {
    //base case
    if(n==1){
        return x ;
    }

    long long  half = myPow(x , n/2);
    if(n%2==0){
        return (half*half)%value ;
    }
    else{
        return (x*half*half)%value ;
    }


}



public:
    int countGoodNumbers(long long n) {
       long long value = 1e9+7 ; 
       if(n==1){
        return 5 ;
       }
        
       if(n%2==0){
            return ((myPow(5, n/2))%value*(myPow(4, n/2))%value)%value ;
       }
       else{
            return (5*(myPow(5, n/2))%value*(myPow(4, n/2))%value)%value ;
       }

    }
};
