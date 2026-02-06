class Solution {
public:
    int solve(int index , int buy , vector<int>&prices , vector<vector<vector<int>>>&dp , int limit ){
        if(index == prices.size()){
            return 0 ;
        }

        if(limit == 0){
            return 0 ;
        }

        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit]  ;
        }
        int profit = 0;
        if(buy){// buy = 1 show kr rha hai ki hum buy kr skte hai and uske andr bhi humare paas 2 choices hai ki buy kre ya skip kre 
            int buyKaro = - prices[index]+solve(index+1 , 0 , prices , dp , limit) ; // buy krenge toh hume prices wale element ko negative krke add krna hoga kyonki hum buy ke baad sell hi kr skte haii toh hume profit ke liye sell - buy krna hota hai toh hum isko ulta bhi likh skte hai ki -buy + sell yehiuse kra hai and phir recursive call bhej di pr jab humne buy kr liya toh humne buy ki value ko 0 bheja hai 
            int skipKaro = 0 + solve(index+1 , 1 , prices , dp , limit) ; // skip ke case mai hum kuch add nhi kr rhe bs index bda rhe hai and buy ko 1 hi rhne denge kyonki humne skip kra hai yaani abhi hume buy krna hai 
            profit = max(buyKaro , skipKaro) ;
        }
        else{//else case pr tb  hi aayenge jab buy = 0 hoga yani buy allowed nhi hai 
            int sellKaro = +prices[index]+ solve(index+1 , 1 , prices , dp , limit-1 ) ; // humne upr wala hi concept use kiya hai sell ko + sell - buy kr rhe hai taaki profit add hota chle and jab sell kr lenge toh buy ko 1 kr denge kyonki ab hum buy kr skte hai and limit-1 kra hai kyonki iss point ek limit km ho gyi kyonki humne ek bar buy and sell kr liya hai
            int skipKaro = 0 + solve(index+1 , 0 , prices , dp , limit) ;// skip ke case mai hum kuch add nhi kr rhe bs index bda rhe hai and buy ko 0 hi rhne denge kyonki humne skip kra hai yaani abhi humne sell nhi kra yaani hume phle sell krna hog auske baad hi buy kr paaenge 
            profit = max(sellKaro , skipKaro) ;
        }
        dp[index][buy][limit] = profit ;
        return dp[index][buy][limit]  ;

    }

    //method 2 
    int solve1(vector<int>& prices){
        int n = prices.size() ;
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(2 , vector<int>(3 , 0))) ;

        for(int index = n-1 ; index>=0 ; index--){
            for(int buy = 0 ; buy<=1 ; buy++){
                for(int limit = 1 ; limit<=2 ; limit++){//humne limit 1 se liya hai kyonki base case mai 0 wala alraedy cover ho gya kyonki humne dp mai values 0 se initialize kri hai
                    int profit = 0;
                    if(buy){
                        int buyKaro = -prices[index]+dp[index+1][0][limit] ;
                        int skipKaro = 0 + dp[index+1][1][limit] ;
                        profit = max(buyKaro , skipKaro) ;
                    }
                    else{
                        int sellKaro = +prices[index]+dp[index+1][1][limit-1] ;
                        int skipKaro = 0 + dp[index+1][0][limit] ;
                        profit = max(sellKaro , skipKaro) ;
                    }
                    dp[index][buy][limit] = profit ;
                }
            }
        }

        return dp[0][1][2] ;

    }
    int maxProfit(vector<int>& prices) {
        //iss question mai hum bs 2 transaction kr skte hai means 2 baar hi buy and sell kr skte hai
        // int n = prices.size() ;
        // vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(3 , -1))) ;
        // return solve(0 , 1 , prices , dp , 2) ;

        return solve1(prices) ;
    }
};
