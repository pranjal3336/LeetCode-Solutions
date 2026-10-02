class Solution {
public:
    typedef pair<int , pair<int , int>>PP ;
    int dr[4] = {-1 ,1,0,0} ;
    int dc[4] = {0,0,-1,1} ;

    int trapRainWater(vector<vector<int>>& arr) {
        int m = arr.size() ;
        int n = arr[0].size() ;

        priority_queue<PP , vector<PP> , greater<PP>>boundaryCells ;
        vector<vector<bool>>vis(m , vector<bool>(n , false)) ;

        //first and last column joki boundary benege pq mai daal rhe hai 
        for(int i=0 ; i<m ; i++){
            for(int j : {0 , n-1}){
                boundaryCells.push({arr[i][j] , {i , j}}) ;
                vis[i][j] = true ;
            }
        }

        //first and last row joki boundary benege pq mai daal rhe hai 
        for(int j=0 ; j<n ; j++){
            for(int i : {0 , m-1}){
                boundaryCells.push({arr[i][j] , {i , j}}) ;
                vis[i][j] = true ;
            }
        }

        int water = 0 ;
        
        while(!boundaryCells.empty()){
            PP p = boundaryCells.top() ;
            boundaryCells.pop() ;

            int h = p.first ;
            int row = p.second.first ;
            int col = p.second.second ;

            for(int i=0 ; i<4 ; i++){
                int nbr = row + dr[i] ;
                int nbc = col + dc[i] ;

                if(nbr >=0 && nbr <m && nbc >=0 && nbc<n && !vis[nbr][nbc]){
                    water += max(h-arr[nbr][nbc] , 0) ;
                    boundaryCells.push({max(h , arr[nbr][nbc]) , {nbr , nbc}}) ;
                    vis[nbr][nbc] = true ;
                }
            }
        }
        return water ;

    }
};
