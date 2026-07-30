class Solution {
public:
    int minimumPushes(string word) {
        int n =  word.length() ;
        int d = n/8 ;
        int y = d ;
        int cost = 0 ;
        while(y > 0){
            cost += 8 * y ;
            y-- ; 
        }

        int x = n%8 ;
        int ans = x*(d+1) ;

        return ans + cost ;

    }
};
