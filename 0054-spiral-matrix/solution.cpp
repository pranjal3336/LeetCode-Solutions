class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int cnt = 0 ;
        int r = arr.size() ;
        int c = arr[0].size() ;
        int sr = 0 ;
        int sc = 0 ;
        int er = r-1 ;
        int ec = c -1 ;
        int total = r*c ;
        vector<int>ans ;

        while(cnt <total){
            for(int i = sc ;cnt <total && i<=ec ; i++){
                ans.push_back(arr[sr][i]) ;
                cnt++ ;
            }
            sr++ ;
            
            for(int i = sr ;cnt <total && i<=er ; i++){
                ans.push_back(arr[i][ec]) ;
                cnt++ ;
            }
            ec-- ;
            for(int i = ec ;cnt <total && i>=sc ; i--){
                ans.push_back(arr[er][i]) ;
                cnt++ ;
            }
            er-- ;
            for(int i = er ;cnt <total && i>=sr ; i--){
                ans.push_back(arr[i][sc]) ;
                cnt++ ;
            }
            sc++ ;

        }
        return ans ;
    }
};
