class Solution {
public:
    void dfs(int sr, int sc, int color , vector<vector<int>>& image , vector<vector<bool>>&visited , int startcolor){

        visited[sr][sc] = true ;
        image[sr][sc] = color ;
        int n = image.size() ;
        int m = image[0].size() ;

        int deltarow[] = {0 , -1 , 0 , 1} ;
        int deltacol[] = {-1 , 0 , 1 , 0} ;

        for(int i = 0 ; i<4 ; i++){
            int row = sr + deltarow[i] ;
            int col = sc + deltacol[i] ;

            if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && image[row][col] == startcolor ){
                dfs(row , col , color , image , visited , startcolor) ;
            }
        }




    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //similar hai no of islands wale ki trh 
        int n = image.size() ;
        int m = image[0].size() ;

        vector<vector<bool>>visited(n , vector<bool>(m , false)) ;
        int x = image[sr][sc] ;
        dfs(sr , sc ,  color ,image , visited , x) ;
        return image ;
    }
};
