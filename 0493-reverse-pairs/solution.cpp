class Solution {
public:
    void merge(vector<int>& nums , int start ,int mid , int end){
        int left = start ;
        int right = mid+1 ;
        vector<int>temp ;
    
        while(left <= mid && right <= end){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]) ;
                left++ ;
            }
            else{
                temp.push_back(nums[right]) ;
                right++ ;
            }
        }

        while(left<=mid){
            temp.push_back(nums[left]) ;
                left++ ;
        }

        while(right<=end){
            temp.push_back(nums[right]) ;
                right++ ;
        }

        for(int i = start ; i<= end ; i++){
            nums[i] = temp[i - start] ;
        }

       
    }

    int countPairs(vector<int>& nums , int start , int mid , int end ){
        int cnt = 0 ;
        int right = mid+1 ;
        for(int j = start ; j<=mid ; j++){
            while(right <= end && nums[j]> (long long)2*nums[right]){
                right++ ;
            }
            cnt += right-(mid+1) ;
        }
        return cnt ;
    }

    int mergeSort(vector<int>& nums , int start , int end ){
        int cnt = 0 ;
        if(start>=end){
            return cnt ;
        }

        int mid = (start+end)/2 ;

        cnt+= mergeSort(nums , start , mid) ;
        cnt+= mergeSort(nums, mid+1 , end) ;
        cnt+= countPairs(nums , start , mid , end ) ;//merge krne se phle hi pairs niklegi 
        merge(nums , start , mid , end) ;
        return cnt ;
    }
    int reversePairs(vector<int>& nums) {
       //iss method se tle aa jayga 
    //    int n = nums.size() ;
    //     int cnt =0 ;
    //     for(int i =0 ; i<n ; i++){
    //         for(int j = i+1 ; j<n ; j++){
    //             if((long long) nums[i] > 2* (long long )nums[j]){
    //                 cnt++ ;
    //             }
    //         }
    //     }
    //     return cnt ;
    int n = nums.size() ;
    return mergeSort(nums , 0 , n-1) ;


    }
};
