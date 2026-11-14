class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1){
            return 1 ;
        }
        set<int>st;
        for(auto i:nums){
            st.insert(i) ;
        }

        int maxlen = 0 ;
        vector<int>temp ;
        while(!st.empty()){
            auto it = *st.begin() ;
            temp.push_back(it) ;
            st.erase(st.begin()) ;
        }

        int i = 0 ;
        while(i<temp.size()){
            int j = i ;
            while(j <temp.size()-1  && temp[j] + 1 == temp[j+1]){
                j++ ;
            }
            maxlen = max(maxlen , j-i+1) ;
            i= j+1 ;
        }

        return maxlen ;
    }
};
