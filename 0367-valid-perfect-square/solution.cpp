class Solution {
public:
    bool isPerfectSquare(int num) {
        int s = 1 ;
        int e = num ;

        long long  mid = s + (e-s)/2 ;

        while(s<=e){
            long long a = mid*mid ;
            if(a == num){
                return true ;
            }

            else if(a > num){
                e = mid -1 ;
            }
            else{
                s = mid+1 ;
            }

            mid = s+(e-s)/2 ;
        }
        return false ;
    }

    
};
