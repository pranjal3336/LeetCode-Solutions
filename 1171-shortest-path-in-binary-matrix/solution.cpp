class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;

        if(n ==0 || grid[0][0] == 1 || grid[n-1][n-1] ==1){
            return -1 ;
        }

        if(n==1 && grid[0][0] == 0){
            return 1 ;
        }
        vector<vector<int>>dist(n , vector<int>(n , INT_MAX)) ;

        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq ;

        pq.push({1, {0,0}}) ;
        dist[0][0] = 0 ;
        grid[0][0] = 1 ;

        while(!pq.empty()){
            int d = pq.top().first ;
            int r = pq.top().second.first ;
            int c = pq.top().second.second ;

            pq.pop() ;

            for(int i = -1 ; i<=1 ; i++){
                for(int j = -1 ; j<=1 ; j++){
                    int nbrr = r + i ;
                    int nbrc = c + j ;

                    if(nbrr >=0 && nbrr <n && nbrc >=0 && nbrc < n && grid[nbrr][nbrc] == 0){
                        if(d + 1 < dist[nbrr][nbrc]){
                            dist[nbrr][nbrc] = d + 1 ;
                            grid[nbrr][nbrc] = 1 ;
                            pq.push({d+1 , {nbrr , nbrc}}) ;
                        }
                    }
                }
            }
        }


        if(dist[n-1][n-1] != INT_MAX){
            return dist[n-1][n-1] ;
        }
        return -1 ;

    }
};
