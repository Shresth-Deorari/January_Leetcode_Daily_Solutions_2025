class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int>rows(m, n);
        vector<int>cols(n, m);
        unordered_map<int,int>mp;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                mp[mat[i][j]] = i*n + j;
            }
        }
        int ans = -1;
        for(int i =0;i<arr.size();i++){
            int coor = mp[arr[i]];
            int x = coor/n;
            int y = coor%n;
            rows[x]--;
            cols[y]--;
            if(rows[x]==0 || cols[y]==0)return i;
        }
        return 0;
    }
};