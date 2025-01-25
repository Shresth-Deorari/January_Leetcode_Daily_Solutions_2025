class UnionFind{
public:
    vector<int>size;
    vector<int>parent;
    UnionFind(int n){
        size.resize(n,1);
        parent.resize(n,0);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
    } 
    
    int findParent(int u){
        if(parent[u] == u)return u;
        return parent[u] = findParent(u);
    }
    
    void union(int u, int v){
        int parentU = findParent(u);
        int parentV = findParent(v);
        if(parentU != parentV){
            if(size[parentU]>=size[parentV]){
                parent[parentV] = parentU;
                size[parentU] += size[parentV];
            }
            else{
                parent[parentU] = parentV;
                size[parentV] += size[parentU];
            }
        }
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>temp = nums;
        sort(temp.begin(), temp.end());
        UnionFind dsu(n); 
        for(int i = 1;i<n; i++){
            if(temp[i] - temp[i-1] <= limit){
              dsu.union(i, i-1);
            }    
        }
        unordered_map<int,vector<int>>mp;
        for(int i = 0;i<n;i++){
            int parentI = dsu.findParent(i);
            mp[parentI].push_back(i);
        }
        vector<int>ans(n);
        for(int i = 0;i<n;i++){
            int curr = nums[i];
            int parentCurr = dsu.findParent(curr);
            int smallest = mp[parentCurr][0];
            mp[parentCurr].erase(mp[parentCurr].begin());
            ans[i] = smallest;
        } 
        return ans;
    }
};

