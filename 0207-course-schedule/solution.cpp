class Solution {
public:
    bool dfs(unordered_map<int , list<int>>&adj  ,vector<bool>&vis  ,vector<bool>&inRecursion , int node){
        vis[node] = true ;
        inRecursion[node] = true ;

        for(auto &it:adj[node]){
            if(!vis[it] && dfs(adj , vis , inRecursion , it)){
                return true ;
            }
            else if(inRecursion[it] == true){
                return true ;
            }
        }

        inRecursion[node] = false ;
        return false ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses , false) ;
        vector<bool>inRecursion(numCourses , false) ;

        unordered_map<int , list<int>>adj ;
        for(int i=0 ; i<prerequisites.size() ; i++){
            int u = prerequisites[i][0] ;
            int v = prerequisites[i][1] ;

            adj[v].push_back(u) ;
        }

        for(int i=0 ; i<numCourses ; i++){
            if(!vis[i] && dfs(adj , vis , inRecursion , i)){
                return false ;//cycle mil gyi h toh ciurse nhi le skte 
            }
        }
        return true ;
    }
};
