class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>mp ;// 1. Har element ki frequency count karo
        vector<int>ans ;
        int n = nums.size() ;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++ ;
        }
    // 2. Min-Heap banao {frequency, element} store karne ke liye hum frequency ke according sort kr rhe hai heap mai 
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq ;
        
        // 3. Heap mein daalte jao aur size > k hote hi sabse chhoti freq pop karo
        for(auto i : mp){
            pq.push({i.second, i.first});
            if (pq.size() > k) {
                pq.pop();
            }
        }
   // 4. Bache hue top K elements ko answer mein nikal lo
        while(!pq.empty()){
            int top = pq.top().second ;//.second se element nikl rha hai 
            pq.pop() ;
            ans.push_back(top) ;

        }
        return ans ;

        

    }
};
