class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size() ;
        sort(begin(tokens) , end(tokens)) ;
        
        int i =0 ;
        int j = n-1 ;
        int maxScore = 0 ;
        int score = 0 ;
        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i] ;
                score++ ;
                maxScore = max(maxScore , score) ;
                i++ ;
            }
            else if(score >=1){
                power += tokens[j] ;
                j-- ;
                score-- ;
            }
            else{
                break ;
            }
            
        }

        return maxScore ;
    }
};
