class Solution {
public:
    //hum check kr rhe h ki newbox tbhi rkhenge jab uski width length and height base wale se kam hogi 
    bool checkforcondition(vector<int> base , vector<int> newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1]  && newBox[2]<=base[2]){
            return true ;
        }
        else{
            return false ;
        }
    }

    int solve2(vector<vector<int>>& arr){
        
        int n = arr.size() ;
        
        vector<int>currRow(n+1 , 0) ;
        vector<int>nextRow(n+1 ,0) ;
        for(int curr = n-1 ; curr>=0 ;curr--){
            for(int prev = curr-1 ; prev >=-1 ; prev--){
                
                int include = 0 ;
                if(prev == -1 || checkforcondition(arr[curr] , arr[prev])){//hum include 2 case mai hi krenge yaa toh voh first element hoga yaani jab prev -1 hoga and yaa toh uska curr element prev element se bda hoga and phir hum recursive call kr denge curr 1 aage bd jayega and prev curr bn chuka hoga isliye humne curr+1 and curr likha h
                    include = arr[curr][2] +  nextRow[curr+1]  ;
                }
                
                int exclude = 0 + nextRow[prev+1] ;//exclude ke case mai bs curr aage bd jatga and prev same rhega 
                
                currRow[prev+1] =  max(include , exclude) ;
                    
            }
            nextRow = currRow ; //har iteration ke baad next curr bn chuka hoga 
            
        }
        
        return nextRow[0] ; //hum prev ko n-1 to -1 tk le rhe h and hume pta h hume prev+1 return krna hoga and jab prev -1 hoga and usme =1 krenge toh prev 0 aa jayga isliye humne dp[0][0] liya h curr toh hum n-1 to 0 tk hi le rhe h 
        
        
    }



    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1 --> sort krenge cuboids ki har row ko jisse last wala element ko height assume krenge and voh last mai aa jayga 
        for(auto &a : cuboids){
            sort(a.begin() , a.end()) ;
        }

        //step 2 --> ab hum w or l ke respect mai sort krenge 
        sort(cuboids.begin() , cuboids.end()) ;

        //step 3 --> longest increasing subsequence wala code use krenge usme kuch changes krenge 
        
        return solve2(cuboids) ;
    }
};
