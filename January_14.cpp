class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>freq(n+1, 0);
        vector<int>ans(n);
        int commonCount = 0;
        for(int i = 0;i<n; i++){
            freq[A[i]]++;
            freq[B[i]]++;
            if(freq[A[i]]==2){
                commonCount++;
            }
            if(A[i]!=B[i] && freq[B[i]]==2){
                commonCount++;
            }
            ans[i] = commonCount;
        }
        return ans;
    }
};