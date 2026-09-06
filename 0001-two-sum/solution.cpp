class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     //humne index map krane ke baad 2 pointer hi use kiya hai 
    //   vector<pair<int , int>> v;
    //   for(int i=0 ; i<nums.size() ; i++){
    //     v.push_back({nums[i] , i}) ;
    //   } 
       
    //    sort(v.begin() , v.end()) ;
    //    int i = 0 ; 
    //    int j = v.size() -1 ;

    //    while(i<j){
    //     if(v[i].first + v[j].first == target){
    //         return {v[i].second , v[j].second} ;
    //     }
    //     else if( v[i].first + v[j].first < target){
    //         i++ ;
    //     }
    //     else{
    //         j-- ;
    //     }
    //    } 

    //    return {0,0} ;

        unordered_map<int , int >mp ;
        for(int i=0 ; i<nums.size() ; i++){
            if(mp.find(target - nums[i]) != mp.end()){
                return {mp[target-nums[i]] , i} ;
            }
            mp[nums[i]] = i ;
        }
        return {0,0} ;
    }
};
