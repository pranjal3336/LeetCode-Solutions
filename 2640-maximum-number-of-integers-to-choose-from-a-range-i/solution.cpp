class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0 ;
        unordered_set<int >st ;
        int m = banned.size() ;
        for(int i=0 ; i<m ; i++){
            st.insert(banned[i]) ;
        }
        int sum = 0 ;
        for(int i = 1 ; i <=n ; i++){
            if(st.find(i) != st.end()){
                continue  ;
            }
            if(sum + i <= maxSum){
                sum+=i ;
                ans++ ;
            }
            else{
                break ;
            }
        }

        return ans ;
    }
};
