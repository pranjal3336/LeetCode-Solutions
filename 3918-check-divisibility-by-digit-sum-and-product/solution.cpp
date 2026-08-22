class Solution {
public:
    bool checkDivisibility(int n) {
        int dsum = 0 ;
        int dprod = 1 ;
        int m = n ;
        while(m>0){
            dsum +=m%10 ;
            dprod *= m%10 ;
            m/=10 ;
        }

        if(n%(dsum+dprod) ==0 ){
            return true ;
        }
        return false ;
    }
};
