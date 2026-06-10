class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        // int n = arr.size() ;
        // int m = arr[0].size() ;

        // vector<pair<int , int>>v ;//iss vector mai saare jha jha 0 present hai uske i and j store kr rha ho yaani row and col number 
        // for(int i =0 ; i<n ; i++){
        //         for(int j = 0 ; j<m ; j++){
        //             if(arr[i][j] == 0){
        //                 v.push_back({i , j}) ;
        //             }
        //         }
        // }

        // for(int k = 0 ; k<v.size() ; k++){//ab hum v vector ko traverse krenge and jo i and j milta jayga uss purri row and column ko 0 krenge 
        //     for(int j = 0;  j < m ; j++){//yha hum uss purri row ko 0 kr rhe hai jo v vector mai i yaani row index  bta rhi hai 0 ka 
        //         arr[v[k].first][j] = 0 ;
        //     }
        //     for(int i =0 ; i<n ; i++){//yha hum uss purri column ko 0 kr rhe hai jo v vector mai j yaani column index  bta rhi hai 0 ka 
        //         arr[i][v[k].second] = 0 ;
        //     }
        // }

        //Tc O(n*m + n*m*(n+m))= O(n*m*(n+m)) and sc O(n+m) hai 

        //hum 2 dummy array jo ki first row and first column honge usse bhi isse solve kr skte hai 
        int n = arr.size() ;
        int m = arr[0].size() ;

        bool col0 = true ; // yeh arr[0][0] ke liye hai agr hume 0th column mai khi bhi 0 mila toh hum col0 ko false mark kr denge kyonki hum first row ko dummy vector le rhe hai and uske phle element ko 0 kr diya toh lgega ki voh row ke liye hai and khi row zero na ho jaaye isliye arr[0][0] ko alg sehandle krna pdega 
        for(int i =0 ; i<n ; i++){
            if(arr[i][0]==0){
                col0 = false ;
            }
            for(int j=1; j<m ;j++){
                if(arr[i][j] ==0){
                    arr[i][0] = arr[0][j] = 0 ;
                }
            }
        }

        //ab hum backward move krenge and dummy array ka use krke row and column ko 0 krenge yaani uss cell  ko 0 tbhi krenge jab either row or column dummy mai 0 hoga 
        for(int i = n-1 ; i>=0 ; i--){
            for(int j=m-1 ; j>=1 ; j--){
                if(arr[i][0] ==0 || arr[0][j] ==0){
                    arr[i][j] = 0 ;
                }
            }
            if(col0 == false ){
                arr[i][0] = 0 ;
            }
        }

        


    }
}; 
