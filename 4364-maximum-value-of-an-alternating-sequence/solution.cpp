class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n ==1){
            return s ;
        }
        long long  maxi = s + m ;
        return maxi + (1LL * (m-1) * ((n/2) -1)); 
        
    }
};
