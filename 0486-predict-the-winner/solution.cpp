class Solution {
public:
    int solve(vector<int>& nums , int i , int j , vector<vector<int>>&dp){
        // Base Case: Agar pointers cross ho gaye, toh score 0 add hoga
        if(i>j){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        // Choice 1: Player 1 ne i-th element pick kiya.
        // Agla player smart hai, wo aisi choice karega jisse humein minimum score mile (optimal play).
        int take_i = nums[i] + min(solve(nums , i+2 , j , dp) , solve(nums , i+1 , j-1 , dp )) ;
        // Choice 2: Player 1 ne j-th element pick kiya.
        // Yahan bhi opponent minimum score ensure karega hamare liye.
        int take_j = nums[j] + min(solve(nums ,i+1  , j-1 , dp) , solve(nums , i, j-2 , dp)) ;

        return dp[i][j]  = max(take_i , take_j) ;
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin() , nums.end() , 0) ;
        int n = nums.size() ;
        vector<vector<int>>dp(n , vector<int>(n , -1)) ;
        // Player 1 ka maximum possible score nikal rahe hain range [0, n-1] mein
        int player1_score = solve(nums , 0 , n-1 , dp) ;
        // Player 2 ka score total sum me se Player 1 ka score minus karke mil jayega
        int player2_score = sum - player1_score ;
        // Agar Player 1 ka score Player 2 ke barabar ya zyada hai, toh Player 1 jeet jayega
        if(player1_score >= player2_score){
            return true ;
        }

        return false ;


    }
};
