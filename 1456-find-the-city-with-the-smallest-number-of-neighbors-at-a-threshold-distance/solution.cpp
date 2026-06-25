class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n , vector<int>(n , 1e8)) ;
        for(auto it : edges){
            dist[it[0]][it[1]] = it[2] ;
            dist[it[1]][it[0]] = it[2] ;

        }

        for(int i = 0 ; i<n ; i++){
            dist[i][i] =0 ;
        }

        for(int via =0 ; via < n ; via++){
            for(int i =0 ; i<n ; i++){
                for(int j = 0 ; j<n ;j++){
                    if(dist[i][via] != 1e8 && dist[via][j] != 1e8){
                        dist[i][j] = min(dist[i][j] , dist[i][via]+ dist[via][j] ) ;
                    }
                }
            }
        }

        int maxcnt = n+1  ;
        int city = -1  ;

        for(int i =0 ; i<n ; i++){
            int cnt = 0 ;
            for(int j =0 ; j<n ; j++){
                if(dist[i][j] <= distanceThreshold){
                    cnt++ ;
                }
            }
            if(cnt <= maxcnt){//yeh condition 2 kaam kr rhi hai agr no of cities less than hai threshhold se toh maxcnt ko cnt se replace kr denge and city = i and agr cnt == maxcnt hua toh voh value overwrite ho rhi hai pr city ki new value yaani i hai voh ab city bn jaayga and i humesha aage bd rhe hai toh ques mai given hai agr 2 nodes ki same city hai toh bigger wala node answer hoga aur hum aage traveerse kr rhe hai isliye i ki automattically large value hi city mai aaygi 
                maxcnt = cnt ;
                city = i ;
            }
        }
        return city ;
    }
};
