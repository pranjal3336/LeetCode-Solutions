class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
        int i=0;
        int j=k-1;
        while(i<=j ){
            swap(nums[i++], nums[j--]);
        }

        int m= k;
        int n= nums.size()-1;
        while(m<=n){
            swap(nums[m++], nums[n--]);
        }

    }
};
