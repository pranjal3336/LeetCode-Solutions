class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i = 0 ;
        int j = 0 ;
        int n = arr.size() ;
        vector<int>temp(n , INT_MAX) ;
        int currSum = 0 ;
        int res = INT_MAX ;
        int bestmin = INT_MAX ;
        while(j<n){
            currSum+=arr[j] ;
            while(currSum>target){
                currSum -=arr[i] ;
                i++ ;
            }

            if(currSum == target){
                int len = j-i+1 ;
                if(i>0 && temp[i-1] != INT_MAX){
                    res = min(res , len + temp[i-1]) ;
                }
                bestmin = min(bestmin , len) ;
            }
            temp[j] = bestmin ;
            j++ ;
        }

        if(res == INT_MAX){
            return -1 ;
        }
        return res ;
    }
};
