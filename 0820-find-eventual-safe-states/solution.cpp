class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>&graph) {
        int n = graph.size() ;
        vector<int>indegree(n) ;
        unordered_map<int , list<int>>adj ;
        for(int i =0 ; i<n ; i++){
            //hume i to j ko j to i krna hai yaani graph reverse krnege 
            for(auto j : graph[i]){
                adj[j].push_back(i) ;
            }
        }
        //indegree nikalenge for each node  after reversing the graph 
        for(auto i:adj){
            for(auto j : i.second){
                indegree[j]++ ;
            }
        }

        queue<int>q ;
        for(int i =0 ; i<n ; i++){
            if(indegree[i]==0){
                q.push(i) ;
            }
        }
        vector<int>ans ;
        while(!q.empty()){
            int top = q.front() ;
            q.pop() ;
            ans.push_back(top) ;

            for(auto nbr: adj[top]){
                indegree[nbr]-- ;
                if(indegree[nbr]==0){
                    q.push(nbr) ;
                }
            }
        }

        sort(ans.begin() , ans.end()) ;
        return ans ;

    }
};
