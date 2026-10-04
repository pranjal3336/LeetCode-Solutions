class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m = mat.size() ;
        int n = mat[0].size() ;
        set<int>row ;
        set<int>col ;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ;j<n ; j++){
                if(mat[i][j] == 0){
                    row.insert(i) ;
                    col.insert(j) ;
                }
            }
        }

        while(!row.empty()){
            auto front = *row.begin() ;
            for(int j = 0 ; j<n ; j++){
                mat[front][j] = 0 ;
            }
            row.erase(front) ;
        }

        while(!col.empty()){
            auto front = *col.begin() ;
            for(int i = 0 ; i<m ; i++){
                mat[i][front] = 0 ;
            }
            col.erase(front) ;
        }
    }
};
