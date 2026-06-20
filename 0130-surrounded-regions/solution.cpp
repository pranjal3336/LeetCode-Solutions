class Solution {
public:
    void dfs(int row , int col , vector<vector<char>>& mat ,vector<vector<bool>> &visited ){
        visited[row][col] = true ;
        int n =mat.size() ;
        int m = mat[0].size() ;
        //nbrs 4 hi honge up down , left and right 
        int drow[] = {0 , -1 , 0 , 1} ;
        int dcol[] = {-1 , 0 , 1 , 0} ;

        for(int i = 0 ; i < 4 ; i++){
               
                int nbrrow = row + drow[i] ;
                int nbrcol = col + dcol[i] ;
                //out of bound nhi hona chahiye and visited bhi na ho and O bhi ho 
                if(nbrrow > 0 && nbrrow < n && nbrcol > 0 && nbrcol < m &&  !visited[nbrrow][nbrcol] && mat[nbrrow][nbrcol]== 'O'){
                    dfs(nbrrow , nbrcol , mat , visited) ;
                }   
        }

    }

    void solve(vector<vector<char>>& mat) {
        
        int n =mat.size() ;
        int m = mat[0].size() ;
        
       
        vector<vector<bool>> visited(n , vector<bool>(m , false)) ;
        //yha hum phle jo bhi boundary wale O hai unki dfs call chla rhe hai and usse connected jitne bhi O honge voh visited mark kr denge kyonki voh boundary pr hai yaa boundary wale se connected hai toh har trf se X se covered nhi hai 
        //iss loop ki jgh 2 loop lga skte hai first for first and last rows and second loop for first and last col
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < m ; j++){
        //         if(mat[i][j] == 'O' && ((i==0 || i==n-1) || (j==0 || j==m-1))){
        //             dfs(i  , j , mat , visited) ;
        //         }
        //     }
        // }

        for(int i =0 ; i<n ; i++){
            //first column
            if(mat[i][0] == 'O' && !visited[i][0]){
                dfs(i , 0 , mat , visited) ;
            }
            //last column
            if(mat[i][m-1]== 'O' && !visited[i][m-1]){
                dfs(i , m-1 , mat , visited) ;
            }  
        }
         for(int j =0 ; j<m ; j++){
            //first row
            if(mat[0][j] == 'O' && !visited[0][j]){
                dfs(0 , j , mat , visited) ;
            }
            //last row
            if(mat[n-1][j]== 'O' && !visited[n-1][j]){
                dfs(n-1 , j , mat , visited) ;
            }  
        }
        
        //ab yha hum jo bcche hue O honge yaani jo visit nhi ho paaye yaani ki voh covered region hai and unhe X se replace kr denge 
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(!visited[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X' ;
                }
            }
        }

        
    }
};
