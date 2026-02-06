class Solution {
public:
    int solve(int index , int buy , vector<int>&prices , vector<vector<int>>&dp , int fee){
        if(index == prices.size()){
            return 0 ;
        }

        if(dp[index][buy] != -1){
            return dp[index][buy]  ;
        }
        int profit = 0;
        if(buy){// buy = 1 show kr rha hai ki hum buy kr skte hai and uske andr bhi humare paas 2 choices hai ki buy kre ya skip kre 
            int buyKaro = - prices[index]+solve(index+1 , 0 , prices , dp , fee) ; // buy krenge toh hume prices wale element ko negative krke add krna hoga kyonki hum buy ke baad sell hi kr skte haii toh hume profit ke liye sell - buy krna hota hai toh hum isko ulta bhi likh skte hai ki -buy + sell yehiuse kra hai and phir recursive call bhej di pr jab humne buy kr liya toh humne buy ki value ko 0 bheja hai 
            int skipKaro = 0 + solve(index+1 , 1 , prices , dp , fee) ; // skip ke case mai hum kuch add nhi kr rhe bs index bda rhe hai and buy ko 1 hi rhne denge kyonki humne skip kra hai yaani abhi hume buy krna hai 
            profit = max(buyKaro , skipKaro)  ;
        }
        else{//else case pr tb  hi aayenge jab buy = 0 hoga yani buy allowed nhi hai 
            int sellKaro = +prices[index]+ solve(index+1 , 1 , prices , dp , fee) - fee; // humne upr wala hi concept use kiya hai sell ko + sell - buy kr rhe hai taaki profit add hota chle and jab sell kr lenge toh buy ko 1 kr denge kyonki ab hum buy kr skte hai 
            int skipKaro = 0 + solve(index+1 , 0 , prices , dp , fee) ;// skip ke case mai hum kuch add nhi kr rhe bs index bda rhe hai and buy ko 0 hi rhne denge kyonki humne skip kra hai yaani abhi humne sell nhi kra yaani hume phle sell krna hog auske baad hi buy kr paaenge 
            profit = max(sellKaro , skipKaro) ;
        }
        dp[index][buy] = profit ;
        return dp[index][buy]  ;

    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size() ;
        vector<vector<int>>dp(n , vector<int>(2 ,-1)) ;
        return solve(0 , 1 , prices , dp , fee) ;
    }
};
