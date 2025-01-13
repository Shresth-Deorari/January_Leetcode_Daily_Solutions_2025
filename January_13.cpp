class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        int ans = 0;
        for(auto i : s){
            freq[i-'a']++;
        }
        for (auto i : freq) {
            if (i > 0) { 
                ans += i % 2 ? 1 : 2;
            }
        }
        return ans;
    }
};