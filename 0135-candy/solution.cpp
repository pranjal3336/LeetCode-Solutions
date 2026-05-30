class Solution {
public:
    int candy(vector<int>& ratings) {
        //method 1 time compl O(3N) and space comp O(2N)
        // int n = ratings.size() ;
        // vector<int>left(n) ;
        // left[0] = 1 ;
        // vector<int>right(n) ;
        // right[n-1] = 1 ;

        // //considering left neighbours 
        // for(int i = 1 ; i<n ; i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]  = left[i-1] + 1 ;
        //     }
        //     else{
        //         left[i] = 1 ;
        //     }
        // }

        // //considering right neighbours 
        // for(int i = n-2 ; i>=0 ; i--){
        //     if(ratings[i]>ratings[i+1]){
        //         right[i]  = right[i+1] + 1 ;
        //     }
        //     else{
        //         right[i] = 1 ;
        //     }
        // }

        // int sum = 0 ; 
        // for(int i = 0 ; i<n ; i++){
        //     sum += max(left[i] , right[i]) ;
        // }

        // return sum ;

        //method 2 isme bhi same code hoga bs loop 2 honge and right vector ki need nhi hogi 2 variabls use krenge 
        //time comp O(2N) and space compl O(N) 

        // int n = ratings.size() ;
        // vector<int>left(n) ;
        // left[0] = 1 ;

        // //considering left neighbours 
        // for(int i = 1 ; i<n ; i++){
        //     if(ratings[i]>ratings[i-1]){
        //         left[i]  = left[i-1] + 1 ;
        //     }
        //     else{
        //         left[i] = 1 ;
        //     }
        // }

        // int sum = max(1 , left[n-1]) ; //yeh 1 mtlb right wale array ka jo last index ko 1 maana tha vhi concept hai 
        // int curr = 0 ;
        // int right = 1 ; //yeh right array ka last index ko 1 le rhe hai
        // for(int i = n-2 ; i>=0 ; i--){
        //     if(ratings[i]>ratings[i+1]){
        //         curr = right + 1 ;
        //         right = curr ; 
        //     }
        //     else{
        //         curr = 1 ;  
        //         right = curr ;
        //     }
        //     sum+=max(left[i] , curr) ;
        // }
        // return sum ;

        //method 3 slope method isme peak and down wala concept hai 
        //time comp O(N) hoga kyonki traverse toh kr hi rhe hai lgatar aage bd rhe hai and space comp O(1) hogi 

         int n = ratings.size() ;
        int sum = 1 ;
        int i = 1 ;

        while(i < n){
            //agr flat surface hai 
            if(ratings[i] == ratings[i-1]){
                sum+=1 ;
                i++ ;
            }
            //for upward slope 
            int peak = 1 ;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++ ;
                sum+=peak ;
                i++ ;
            }
            //for downward slope 
            int down = 1 ;
            while(i < n && ratings[i] < ratings[i-1]){
                sum+=down ;
                down++ ;
                i++ ;
            }

            //jab down ward slope khtm ho jaaye toh ek baar down ki value ko peak se compare krenge agr bdi hui toh peak update krenge taaki left and right dono neighbour ko satisfy kre 

            if(down > peak){
                sum += down - peak ;
            }

        }

        return sum ;


    }
};
