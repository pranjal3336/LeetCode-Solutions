class Solution {
public:

    int solve(vector<int> &arr , map<pair<int, int> , int>&maxi , int left , int right , vector<vector<int>>&dp ){
        //base case --> agr sirf leaf node hai toh hum non leaf node generate nhi kr skte isliye hum 0 return krenge 
        if(left == right){
            return 0 ;
        }
        if(dp[left][right] != -1){
            return dp[left][right] ;
        }
        int ans = INT_MAX ; // hume minimum sum of non leaf node return krna hai 
        for(int k= left ; k<right ;k++){
            ans = min(ans , maxi[{left , k}]*maxi[{k+1 , right}]+solve(arr , maxi , left , k ,dp)+solve(arr ,maxi , k+1 , right ,dp)) ;
        }

        return dp[left][right] = ans ;

    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int> , int> maxi ;//iss  map mai hum kisi range i to j ki maximu wali store krenge from the array given jab hum    partitioning kr rhe honge 
        //below for loop se hum array mai jo partitioning kr rhe hai usse kisi range ke beech maximum value nikal rhe hai jo phir hum solve wale function mai use krenge 
        for(int i=0 ;i<arr.size() ;i++){
            maxi[{i,i}] = arr[i] ;
            for(int j=i+1 ; j<arr.size() ; j++){
                maxi[{i,j}] = max(arr[j] , maxi[{i , j-1}] ) ;
            }

        }
        vector<vector<int>>dp(arr.size() , vector<int>(arr.size() , -1)) ;
        return solve(arr , maxi , 0 , arr.size()-1 , dp) ; // 0 starting index hai and arr.size()-1 last index show kr rha hai array ka 

    }
};
