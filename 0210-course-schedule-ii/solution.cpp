class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        unordered_map<int , list<int>>adj ;
        for(int i = 0 ; i<pre.size() ; i++){
            int u = pre[i][1] ;
            int v = pre[i][0] ;

            adj[u].push_back(v) ;

        }

        vector<int>indegree(n , 0) ;
        for(auto i : adj){
            for(auto j : i.second){
                indegree[j]++ ;
            }
        }

        queue<int>q ;
        for(int i =0 ; i<n ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }

        vector<int>ans ;
        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            ans.push_back(node) ;

            for(auto nbr : adj[node]){
                indegree[nbr]-- ;
                if(indegree[nbr] == 0){
                    q.push(nbr) ;
                }
            }
        }

        if(ans.size() == n){
            return ans ;
        }
        return {} ;
    }
};
