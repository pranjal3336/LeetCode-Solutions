class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        //sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int count =1;
        // int maxicount=0;
        // int element =0;
        // if(n==1){
        //          return nums[0] ;
        // }
        
        // for(int i=1;i<n;i++){
        //     if(nums[i]==nums[i-1]){
        //         count++;
        //     }
        //     else{
        //         count = 1;
        //     }
        //     if(count>maxicount){
        //         maxicount= count;
        //         element = nums[i];
        //     }
        // }
        // return element; 
        //method 2 
       // return nums[nums.size()/2] ;
        //method 3 using hashing 
        // int n = nums.size() ;
        // int m = n/2  ;
        // unordered_map<int , int>mp ;
        // for(int i=0 ; i<n ; i++){
        //     mp[nums[i]]++ ;
        //     if(mp[nums[i]]>m){
        //         return nums[i] ;
        //     }
        // }

        //method 4 moores voting algorithm -->isme jo majority element hoga uski frequency yaa count auro se jyada hi hoga mtlb uski frequecncy bch jaygi end mai and jo element store hoga vhi answer hoga 

        int cnt = 0 ;
        int ans = -1 ;
        int n = nums.size() ;
        for(int i =0 ; i<n ; i++){
            if(cnt == 0){//jab cnt =0 yaani hum yaa toh start kr rhe hai yaa phir jisko majority element maana ttha uski frequency other elements ne cancel out kr di then hum cnt =1 kr denge dubara se jo ab new ith element hai usko majority element consider krke aage move krenge 
                cnt = 1;
                ans = nums[i] ;
                
            }
            else if((ans == nums[i])){ // agr ans yaani jo major element mana hai ith pr vhi aa gya toh cnt++ 
                cnt++ ;
            }
            else{//agr nhi aaya yaani other element aa gya toh cnt-- 
                cnt-- ;
            }
        }

        int count = 0 ;
        for(int i=0 ; i<n ; i++){
            if(ans == nums[i]){
                count++ ;
            }
        }
        //jo majority element hoga uski frequency yaani cnt other lments milkr cancelout nhi kr paayenge yaani ans mai vhi store rhega kyonki hum ans yaa ni majority element ko bdl rhe hai jab uska ith index tk ka cnt cancel out ho chuka hai 

        int mini = (int)n/2 +1 ;
        int finalans = -1 ;
        if(count>=mini){
            finalans =  ans ;
        }

        return finalans ;

        //Note --> moore algo sirf idea deta hai ki jo element aaye hai last mai voh majority element ho skte hai hume unhe confirm krne ke liye manually bhi unki frequency check krne hoti hai agr voh >n/2 yaani n/2+1 ke equal yaa jyada hai toh usse hi finalans bolenge 
        


    }
};
