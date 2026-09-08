class Solution {
public:
    bool dfs(vector<vector<int>>& graph , vector<int>&color , int currNode , int currColor){
        color[currNode] = currColor ;

        for(auto &v: graph[currNode]){
            if(color[v] == color[currNode]){
                return false ;
            }
            else if(color[v] == -1){
                int colorofv = 1 - currColor ;//current node ke color ka opposite le rhe hai agr currColor =1 hua toh v ka color 1-1 = 0 ho jayga and agr current color 0 hua toh v ka color 1 -0 = 1 ho jayga 
                if(dfs(graph , color , v , colorofv) == false){
                    return false ;
                }
            }
        }

        return true ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int>color(n , -1) ;
        
        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){//starting mai color ko 0 rkhunga then uska oppsite lenge yaani 1 
                if( dfs(graph , color , i , 0) == false){
                    return false ;
                }
            }
        }
        return true  ;
    }
};
