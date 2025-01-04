class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        for(char ch = 'a'; ch<='z'; ch++){
            int start = 0;
            int end = s.size()-1;
            while(start<s.size() && s[start]!=ch)start++;
            while(end>=0 && s[end]!=ch)end--;
            unordered_set<char>st;
            start++;
            while(start<end){
                st.insert(s[start++]);
            }
            ans += st.size();
        }
        return ans;
    }
};