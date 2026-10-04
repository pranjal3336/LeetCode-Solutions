class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;

        int sr = 0 ;
        int er = m-1 ;
        int sc = 0 ;
        int ec = n-1 ;

        int total = m*n ;

        vector<int>ans ;
        int cnt = 0 ;
        while(cnt <total){
            
            for(int i = sc ; cnt < total && i<=ec ; i++){
                ans.push_back(mat[sr][i]) ;
                cnt++ ;
            }
            sr++ ;

            for(int i = sr ; cnt < total && i<=er ; i++){
                ans.push_back(mat[i][ec]) ;
                cnt++ ;
            }

            ec-- ;

            for(int i = ec ; cnt < total && i>=sc ; i--){
                ans.push_back(mat[er][i]) ;
                cnt++ ;
            }
            er-- ;

            for(int i = er ; cnt < total && i>=sr ; i--){
                ans.push_back(mat[i][sc]) ;
                cnt++ ;
            }
            sc++ ;


        }

        return ans ;

    }
};
