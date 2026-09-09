class Solution {
public:
    int findParent(int i , vector<int>&parent){
        if(i == parent[i]){
            return i ;
        }

        return parent[i] = findParent(parent[i] , parent) ;
    }

    void unionbyrank(int u , int v , vector<int>&parent , vector<int>&rank){
        int u_par = findParent(u , parent) ;
        int v_par = findParent(v , parent) ;

        if(u_par == v_par){
            return ;
        }

        if(rank[u_par] < rank[v_par]){
            parent[u_par] = parent[v_par] ;
        }
        else if(rank[u_par] > rank[v_par]){
            parent[v_par] = parent[u_par] ;
        }
        else{
            parent[u_par] = parent[v_par] ;
            rank[v_par]++ ;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size() ;
        vector<int>rank(26 , 0) ;
        vector<int>parent(26) ;
        for(int i=0 ; i<26 ; i++){
            parent[i] = i ;
        }
        for(string &s : equations){
            if(s[1] == '='){// yeh a == b wala case hai isme union krege 
               unionbyrank(s[0]-'a' , s[3]-'a' , parent , rank) ;
            }
            
        }
        for(string &s : equations){
            if(s[1] == '!'){//a != b wale case mai a and b ke parent dekhenge agr equal hue toh false return krenge kyonki yeh ek hi set  mai hue toh true return krenge 
               int find_par_u = findParent(s[0]-'a' , parent) ;
               int find_par_v = findParent(s[3] -'a' , parent) ;

               if(find_par_u == find_par_v){
                return false ;
               }
            }
            
        }
        return true ;
    }
};
