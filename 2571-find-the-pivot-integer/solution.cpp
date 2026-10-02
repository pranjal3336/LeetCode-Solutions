class Solution {
public:
    int pivotInteger(int n) {
        // int i=1 ;
        // int total = (n*(n+1))/2 ;
        // while(i<=n){
        //     int temp = (i*(i+1))/2 ;
        //     if(temp == (total-temp+i)){
        //         return i ;
        //     }
        //     else if(temp > total/2){
        //         return -1 ;
        //     }
        //     else{
        //         i++ ;
        //     }
        // }
        // return -1 ;
        int total = (n*(n+1))/2 ;

        int ans = sqrt(total) ;

        if(ans*ans == total){
            return ans;
        }
        return -1 ;

    }
};
