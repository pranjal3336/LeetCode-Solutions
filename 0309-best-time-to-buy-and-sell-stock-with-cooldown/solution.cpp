class Solution {
public:
    int solve(int index , int buy , vector<int>&prices , vector<vector<int>>&dp ){
        if(index >= prices.size() ){
            return 0 ;
        }

       

        if(dp[index][buy] != -1){
            return dp[index][buy]  ;
        }
        int profit = 0;
        if(buy == 1){// buy = 1 show kr rha hai ki hum buy kr skte hai and uske andr bhi humare paas 2 choices hai ki buy kre ya skip kre 
            int buyKaro = - prices[index]+solve(index+1 , 0 , prices , dp ) ;
            int skipKaro = 0 + solve(index+1 , 1 , prices , dp ) ; 
            profit = max(buyKaro , skipKaro) ;
        }
        else{//else case pr tb  hi aayenge jab buy = 0 hoga yani buy allowed nhi hai 
            int sellKaro = +prices[index]+ solve(index+2 , 1 , prices , dp )  ;
            int skipKaro = 0 + solve(index+1 , 0 , prices , dp ) ;
            profit = max(sellKaro , skipKaro) ;
        }
        dp[index][buy]= profit ;
        return dp[index][buy]  ;

    }
    int maxProfit(vector<int>& prices) {
         int n = prices.size() ;
        vector<vector<int>>dp(n ,  vector<int>(2 , -1)) ;
        return solve(0 , 1 , prices , dp ) ;
    }
};
