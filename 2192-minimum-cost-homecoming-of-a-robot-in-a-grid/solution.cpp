class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int srow = startPos[0] ;
        int scol = startPos[1] ;

        int erow = homePos[0] ;
        int ecol = homePos[1] ;


        int cost = 0 ;

        if(srow < erow){
            for(int i = srow +1 ; i<= erow ; i++){
                cost += rowCosts[i] ;
            }
        }
        else{
            for(int i = srow -1 ; i>= erow ; i--){
                cost += rowCosts[i] ;
            }
        }


        if(scol < ecol){
            for(int i = scol +1 ; i<= ecol ; i++){
                cost += colCosts[i] ;
            }
        }
        else{
            for(int i = scol -1 ; i>= ecol ; i--){
                cost += colCosts[i] ;
            }
        }

        return cost ;
    }
};
