class DSU{
    public :
    vector<int>parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0;i<n;i++)parent[i] = i;
    }
    int getParent(int u){
        if(parent[u] == u)return u;
        return parent[u] = getParent(parent[u]);
    }
    void unionSize(int u, int v){
        int parentU = getParent(u);
        int parentV = getParent(v);
        if(parentU == parentV)return;
        if(size[parentU]>=size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        else{
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        DSU dsu(m*n);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n; j++){
                if(grid[i][j]){
                    int parentU = dsu.getParent(i*n + j);
                    for(auto dir : directions){
                        int newi = i + dir.first;
                        int newj = j + dir.second;
                        if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]){
                            int parentV = dsu.getParent(newi * n + newj);
                            if(parentU != parentV)dsu.unionSize(parentU, parentV);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(auto length : dsu.size){
            ans = max(ans, length);
        }
        for(int i=0;i<m; i++){
            for(int j= 0;j<n ;j++){
                if(!grid[i][j]){
                    int temp = 0;
                    unordered_set<int>st;
                    for(auto dir : directions){
                        int newi = i + dir.first;
                        int newj = j + dir.second;
                        if(newi>=0 && newi<m && newj>=0 && newj<n && grid[newi][newj]){
                            int parentV = dsu.getParent(newi * n + newj);
                            if(!st.count(parentV)){
                                temp += dsu.size[parentV];
                                st.insert(parentV);
                            }
                        }
                    }
                    ans = max(ans, temp+1);
                }
            }
        }
        return ans;
    }
};