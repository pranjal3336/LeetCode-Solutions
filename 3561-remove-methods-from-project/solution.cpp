class Solution {
public:
    void dfs(int node , unordered_map<int , list<int>>&adj  , unordered_map<int , bool>&vis ){
        vis[node] = true ;

        for(auto j : adj[node]){
            if(!vis[j]){
                dfs(j , adj , vis) ;
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int , list<int>>adj ;
        for(int i=0 ; i<invocations.size() ; i++){
            int u = invocations[i][0];
            int v = invocations[i][1] ;
            adj[u].push_back(v) ;

        }
        unordered_map<int , bool>vis ;
        
                dfs(k , adj , vis) ;
            
        

        vector<int>ans ; 
        for(int i=0 ; i<n ; i++){
            if(vis[i] == false){
                ans.push_back(i) ;
            }
        }
        vector<int>ans1 ;
        bool cancel = false ;
        for(int i=0 ; i<ans.size() ; i++){
            if(vis[ans[i]] ==false){
                for(auto j : adj[ans[i]]){
                    if(vis[j] == true){
                        cancel = true ;
                        break ;
                    }
                }
            }
        }
        if(cancel == true){

            for(int i=0 ; i<n ; i++){
                ans1.push_back(i) ;
            }
            return ans1 ;
        }

        return ans ;
    }
};
