class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
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


        while(!q.empty()){
            int node = q.front() ;
            q.pop() ;
            n-- ;
            for(auto nbr : adj[node]){
                indegree[nbr]-- ;
                if(indegree[nbr] == 0){
                    q.push(nbr) ;
                }
            }
        }

        return n==0 ;


    }
};
