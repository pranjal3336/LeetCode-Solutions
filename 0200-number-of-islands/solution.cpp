class Solution {
public:
    // void bfs(int row , int col ,vector<vector<char>>& grid, vector<vector<int>>&visited ){
    //     visited[row][col] = 1 ;
    //     int n = grid.size() ;
    //     int m = grid[0].size() ;
    //     queue<pair<int , int>>q ;
    //     q.push({row , col}) ;

    //     while(!q.empty()){
    //         int row = q.front().first ;
    //         int col = q.front().second ;

    //         q.pop() ;
    //         /* NOTE: 8 directions wala logic yahan apply nahi hoga.
    //         Kyunki question ke according island sirf horizontally aur vertically connect hote hain, 
    //         diagonally nahi. Isliye hum sirf 4 directions check karenge.
    //         */
    //         //traversing all eight neighbours yhel logic jab lgta jab diagonallly bhi allowed hote neighbours and tb 8 neigbr hote pr iss question mai 4 negibr hi allowed hai diagonal allowed nhi hai 
    //         // for(int deltarow = -1 ; deltarow<=1 ; deltarow++){
    //         //     for(int deltacol = -1 ; deltacol<=1 ; deltacol++){
    //         //         int nbrrow = row + deltarow ;
    //         //         int nbrcol = col + deltacol ;
    //         //         if(nbrrow>=0 && nbrrow<n && nbrcol>=0 && nbrcol<m && grid[nbrrow][nbrcol]== '1' && !visited[nbrrow][nbrcol]){
                        
    //         //             q.push({nbrrow , nbrcol}) ;
                        
    //         //         }
    //         //     }
    //         // }


    //         //traversing all four nbrs up down , left and right inke liye direction arrays agr same row pr upr wala col yaani deltarow = 0 and deltacol = -1 and inhe row and col mai add krenge taaki upr wale cell ko point kre same sab negibrs k liye  

    //         int deltarow[] = {0 , -1 , 0 , 1} ;
    //         int deltacol[] = {-1 , 0 , 1 , 0} ;
    //         for(int i =0 ; i<4 ; i++){
    //             // Apne naye padosi (neighbour) ke coordinates nikalo
    //             int nbrrow = row + deltarow[i] ;
    //             int nbrcol = col + deltacol[i] ;
    //             // 5. Yahan hum 3 conditions check kar rahe hain:
    //         //    a) Boundary check: Naye coordinates grid ke andar hi hone chahiye (0 se leke n-1 aur m-1 tak)
    //         //    b) Land check: Wo padosi cell paani ('0') nahi, balki zameen ('1') hona chahiye
    //         //    c) Visited check: Wo cell pehle se traverse kiya hua nahi hona chahiye (!visited)
    //             if(nbrrow>=0 && nbrrow<n && nbrcol>=0 && nbrcol<m && grid[nbrrow][nbrcol]== '1' && !visited[nbrrow][nbrcol]){
                
    //                 visited[nbrrow][nbrcol] = 1 ;       
    //                 q.push({nbrrow , nbrcol}) ;
                        
    //             }
    //         }

    //     }

    // }

    void dfs(int row , int col , vector<vector<char>>& grid, vector<vector<int>>&visited){

        visited[row][col] = 1 ;
         int n = grid.size() ;
        int m = grid[0].size() ;

        int deltarow[] = {0 , -1 , 0 , 1} ;
            int deltacol[] = {-1 , 0 , 1 , 0} ;
            for(int i =0 ; i<4 ; i++){
                // Apne naye padosi (neighbour) ke coordinates nikalo
                int nbrrow = row + deltarow[i] ;
                int nbrcol = col + deltacol[i] ;
                // 5. Yahan hum 3 conditions check kar rahe hain:
            //    a) Boundary check: Naye coordinates grid ke andar hi hone chahiye (0 se leke n-1 aur m-1 tak)
            //    b) Land check: Wo padosi cell paani ('0') nahi, balki zameen ('1') hona chahiye
            //    c) Visited check: Wo cell pehle se traverse kiya hua nahi hona chahiye (!visited)
                if(nbrrow>=0 && nbrrow<n && nbrcol>=0 && nbrcol<m && grid[nbrrow][nbrcol]== '1' && !visited[nbrrow][nbrcol]){
                
                    dfs(nbrrow , nbrcol , grid , visited) ;
                        
                }
            }




    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        //YHA PR HUM ADJAACENCY LIST NHI BNATE 
        //YHA BFS AND DFS DONO LAG SKTA HAI 
        //yha visited wala jo map bnta tha uski jgh 2d array bnega 
        int cnt = 0 ;
        vector<vector<int>>visited(n , vector<int>(m , 0)) ;
        for(int i =0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                // Agar cell visited nahi hai AUR wo ek zameen ('1') hai
                // Iska matlab hume ek naya island mil gaya!
                if(!visited[i][j] && grid[i][j] == '1'){
                    cnt++ ;// Naye island ke liye count bada do
                    // Ab BFS call kar do. 
                // BFS kya karega? Wo is point se start karke is island ka jitna bhi connected 
                // hissa (zameen) hoga, sabko dhoondh kar visited mark kar dega.
                // Isse faida yeh hoga ki ye aapas me jude hue '1's dubara nayi island ki tarah count nahi honge.
                    //bfs(i , j , grid , visited ) ;
                    //iss question mai dfs bhi lga skte hai 
                    dfs(i , j , grid , visited) ;
                }
            }
        }

        return cnt ;
    }
};
