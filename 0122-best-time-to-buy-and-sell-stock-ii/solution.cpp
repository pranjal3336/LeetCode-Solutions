class Solution {
public:
    //iss question mai hum multiple times buy and sell kr skte hai pr ek condition hai ki buy ke baad sell hi krna hoga buy ke baad dubara buy nhi kr skte 
    //recursion + memoization 
    int solve(int index , int buy , vector<int>&prices , vector<vector<int>>&dp){
        if(index == prices.size()){
            return 0 ;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy]  ;
        }
        int profit = 0;
        if(buy){// buy = 1 show kr rha hai ki hum buy kr skte hai and uske andr bhi humare paas 2 choices hai ki buy kre ya skip kre 
            int buyKaro = - prices[index]+solve(index+1 , 0 , prices , dp) ; // buy krenge toh hume prices wale element ko negative krke add krna hoga kyonki hum buy ke baad sell hi kr skte haii toh hume profit ke liye sell - buy krna hota hai toh hum isko ulta bhi likh skte hai ki -buy + sell yehiuse kra hai and phir recursive call bhej di pr jab humne buy kr liya toh humne buy ki value ko 0 bheja hai 
            int skipKaro = 0 + solve(index+1 , 1 , prices , dp) ; // skip ke case mai hum kuch add nhi kr rhe bs index bda rhe hai and buy ko 1 hi rhne denge kyonki humne skip kra hai yaani abhi hume buy krna hai 
            profit = max(buyKaro , skipKaro) ;
        }
        else{//else case pr tb  hi aayenge jab buy = 0 hoga yani buy allowed nhi hai 
            int sellKaro = +prices[index]+ solve(index+1 , 1 , prices , dp) ; // humne upr wala hi concept use kiya hai sell ko + sell - buy kr rhe hai taaki profit add hota chle and jab sell kr lenge toh buy ko 1 kr denge kyonki ab hum buy kr skte hai 
            int skipKaro = 0 + solve(index+1 , 0 , prices , dp) ;// skip ke case mai hum kuch add nhi kr rhe bs index bda rhe hai and buy ko 0 hi rhne denge kyonki humne skip kra hai yaani abhi humne sell nhi kra yaani hume phle sell krna hog auske baad hi buy kr paaenge 
            profit = max(sellKaro , skipKaro) ;
        }
        dp[index][buy] = profit ;
        return dp[index][buy]  ;

    }

    //method 2 --. bottom up approach using tabulation 
    int solve1(vector<int>& prices){
        int n = prices.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(2 ,0)) ;

        for(int index = n-1 ; index>=0 ; index--){
            for(int buy = 0 ; buy<= 1 ;buy++){
                int profit = 0 ;
                if(buy){
                    int buyKaro = -prices[index]+dp[index+1][0] ;
                    int skipKaro = 0 + dp[index+1][1] ;
                    profit = max(buyKaro , skipKaro) ;
                }
                else{
                    int sellKaro = +prices[index]+dp[index+1][1] ;
                    int skipKaro = 0 + dp[index+1][0] ;
                    profit = max(sellKaro , skipKaro) ;
                }

                dp[index][buy] = profit ;
            }
        }

        return dp[0][1] ;
    }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size() ;
        // vector<vector<int>>dp(n , vector<int>(2 ,-1)) ;
        // return solve(0 , 1 , prices , dp) ;

        return solve1(prices) ;
    }
};
