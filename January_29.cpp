class DSU{
    vector<int>parent;
    vector<int>size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n, 0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    }
    int findParent(int u){
        if(parent[u] == u)return u;
        return parent[u] = findParent(parent[u]);
    }
    void unionSize(int u, int v){
        int parentU = findParent(u);
        int parentV = findParent(v);
        if(size[parentU] >= size[parentV]){
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        else{
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        vector<int>ans;
        for(auto i : edges){
            int parentU = dsu.findParent(i[0]-1);
            int parentV = dsu.findParent(i[1]-1);
            if(parentU != parentV){
                dsu.unionSize(parentU, parentV);
            }
            else{
                ans = i;
            }
        }
        return ans;
    }
};