class Solution {
public:
    int solveforAlice( int person , vector<int>& piles ,  int i , int M ,  int size ,  vector<vector<vector<int>>>&dp){
        if(i>= size){
            return 0 ;
        }

        if(dp[person][i][M] != -1){
            return dp[person][i][M]  ;
        }

        int stones = 0 ;
        int result ;
        if(person == 1){//agr alice hai toh result -1 lenge 
            result = -1 ;
        }else{//agr bob hai toh rsult bydefault max lenge 
            result = INT_MAX ;
        }

        for(int x = 1 ; x <= min(2*M , size - i) ; x++){
            stones += piles[i + x - 1] ;

            if(person == 1){//alice turn 
                result = max(result , stones + solveforAlice(0 , piles , i+x , max(M , x) , size , dp )) ;
            }
            else{//bob turn 
                result = min(result , solveforAlice(1 , piles , i+x , max(M , x) , size , dp)) ;
            }

        }

        return dp[person][i][M]  = result ;    

    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size() ;
        vector<vector<vector<int>>>dp(2 , vector<vector<int>>(n , vector<int>(n+1 , -1))) ;
        return solveforAlice(1 , piles , 0 , 1 ,  n , dp) ;
    }
};
