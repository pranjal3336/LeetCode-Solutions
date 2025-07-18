class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row =mat.size();
        int col = mat[0].size();

        int a=-1 ;
        int b=-1 ;


        vector<int> ans ;

        // int s=0;
        // int e = row*col -1  ;

        int max = INT_MIN ;

       for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]>=max){
                    max = mat[i][j];
                    a = i;
                    b = j;
                }
            }   
       }
        ans.push_back(a);
        ans.push_back(b);

       return ans ;
    }
};
