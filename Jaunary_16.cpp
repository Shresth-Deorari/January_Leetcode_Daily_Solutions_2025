class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        if(n&1){
            for(auto i : nums2){
                ans ^= i;
            }
        }
        if(m&1){
            for(auto i : nums1){
                ans ^=i;
            }
        }
        return ans;
    }
};