class Solution {
public:
    void dfs(vector<vector<int>>& isConnected , int n , unordered_map<int , bool>&visited , int node , vector<int>&ans){
        ans.push_back(node) ;
        visited[node] = true ;

        for(int j = 0 ; j<n ;j++ ){
            if((isConnected[node][j] == 1 && j != node)&&  visited[j] == false){
                dfs(isConnected , n , visited , j , ans) ;
            }
        }



    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //yeh ques bhi same no of components count krne wala hai 
        int n = isConnected.size() ;//show no of vertex 
        int cnt = 0 ;
        vector<int>ans ;
        unordered_map<int , bool>visited ;
        for(int i =0 ; i<n ; i++){
            if(!visited[i]){
                cnt++ ;
                dfs(isConnected , n , visited , i , ans) ;//hum dfs or bfs kuch bhi lga skte hai 

            }
        }

        return cnt ;
    }
};
