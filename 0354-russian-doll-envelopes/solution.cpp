class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b){
    // pehle width check
    if(a[0] == b[0]){
        // agar width same hai → height badi wali pehle
        return a[1] > b[1];
    }
    // warna width chhoti wali pehle
    return a[0] < b[0];
}
    
    int DpWithBinarySearch(vector<int>& arr , int n){
        if(n==0){
            return 0 ;
        }
        
        vector<int>ans ;
        ans.push_back(arr[0]) ; //hum starting ka element toh lenge hi
        
        //loop for remaining elements 
        for(int i =1 ;i<n ;i++){
            if(arr[i]>ans.back()){//hum ans wale ke last element ko arr ke current element se compare kr rhe h agrr arr ka element bda h toh usse push kr denge ans mai 
                ans.push_back(arr[i]) ;
            }
            
            else{
                //yha hum jab aayenge jab arr ka element ans wale vector ke last element se chota h toh hum arr ke element se just bde element ka index nikal rhe h using lower bound inbuilt function of binary search and uss index ki jgh arr ke lement ko daal rhe h 
                int index = lower_bound(ans.begin() , ans.end() , arr[i]) - ans.begin() ;
                ans[index] = arr[i] ;
            }
        }
        
        return ans.size() ;//jo final mai ans wala vector milega uski length or size hi answer hoga 
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // step 1 → width asc, same width pe height desc
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int>height ;
        for(auto &a : envelopes){
            height.push_back(a[1]) ;
        }

        // step 2 → LIS / DP
        return DpWithBinarySearch(height , height.size());
    }
};
