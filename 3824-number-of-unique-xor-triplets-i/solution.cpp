class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size() ;
        if(n <=2){//agr n 2 ya 2 se kam hai  toh n hi answer hoga 
            return n ;
        }
        //yeh question tricky hai isme answer jo array ka size uski next nearest 2 ki power hoga answer 
        int ans = 1 ;//2^0 = 1 hota hai 
        while(ans <= n){
            ans *= 2 ;
        }

        return ans ;//next nearest 2 ki power hi hai 
    }
};
