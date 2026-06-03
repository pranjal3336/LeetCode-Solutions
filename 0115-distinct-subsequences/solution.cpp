class Solution {
public:
    int solve(int i , int j ,string &s, string &t , vector<vector<int>>&dp ){
        //base case 
        if(j>=t.length()){//jab j bahr ho jaaye yaani t jaisi string mil chuki hai tohi 1 return krenge 
            return 1 ;
        }

        if(i>=s.length()){//jab upr wala case fail hoga yaani j abhi bahr nhi hua means t purri cover nhi kri and i bahr ho jaaye means s mai t jaisi mili hi nhi toh 0 return krenge 
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int ans = 0 ;
        if(s[i]==t[j]){// agr s and t ke character match kr jaaye toh 2 case honge yaa toh hum uss particular character ko lenege yaa nhi lenge s mai isliye dono call jaa rhi hai agr s wale ith character ko lenge toh i and j dono increment hoga and agr nhi liya toh sirf i increment hoga like s = bagabag and t = bag toh agr i=0 and j=0 hai toh match krega means hum s[0] wale b ko le bhi skte hai yaa nhi lenge toh aage wale b joki s[4] pr hai usse bhi le skte hai hum all possible try kr rhe hai 
            ans = solve(i+1 , j+1 , s , t ,dp) + solve(i+1 , j , s , t , dp) ;
        }
        else{
            ans = solve(i+1 , j , s , t , dp) ;//agr match nhi krte character toh sirf i aagre bdta hai 
        }

        return dp[i][j] =  ans ;
    }
    //tabulation method 
    int solveTab(string s, string t){
        int n = s.length() ;
        int m = t.length() ;
        vector<vector<unsigned int>>dp(n+1 , vector<unsigned int>(m+1 , 0)) ;//intger overflow naa ayye isliye unsigned int likha hai LeetCode ke compiler ne tumhe line 40 par rok diya hai kyunki tum do bohot bade numbers ko add kar rahe ho:962,925,175 + 1,429,094,300 = 2,392,019,475Ek standard 32-bit signed int ki maximum capacity $2^{31} - 1$ (yaani 2,147,483,647) hoti hai. Kyunki tumhara addition is limit ko cross kar gaya, C++ usko memory mein store nahi kar paaya aur usne runtime error phek diya.

        for (int i = 0; i <= n; i++) {//jab t string cover ho chuki hai yaani j m ke equal aa gya yaani j  ==m hogya means m-1 se bahr ho jaaye toh hum uss last column mai har row ke liye 1 put kr denge and baaki dp array ko 0 se toh initialize kr rhe hai isliye second base case ko dekhne ki jrurat nhi hai humne top down approach first base case handle kr liya 
            dp[i][m] = 1;
        }

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(s[i]==t[j]){
                    dp[i][j] = dp[i+1][j+1] + dp[i+1][j] ;
                }
                else{
                    dp[i][j] = dp[i+1][j] ;
                }
            }
        }

        return dp[0][0] ;
    }

    int solveoptimization(string s, string t){
        int n = s.length() ;
        int m = t.length() ;

        vector<unsigned int>curr(m+1) ;//yeh last row se above wali row ko show kr rha hai 
        vector<unsigned int>front(m+1 ) ;//yeh last row ko show kr rha hai 
        //hum dono row ke last column ko 1 lenge jaise upr tabulation mai last column ko 1 se fill kr rhe the  
        curr[m] = 1 ;
        front[m] = 1;

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(s[i]==t[j]){
                    curr[j] = front[j+1] + front[j] ;
                }
                else{
                    curr[j] = front[j] ;
                }
            }
            front = curr ;
        }

        return front[0] ;

    }
    int numDistinct(string s, string t) {
        // int n = s.length() ;
        // int m = t.length() ;
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1)) ;
        // return solve(0 , 0 , s , t, dp) ;

       // return solveTab(s , t) ;
       return solveoptimization(s , t) ;
    }
};
