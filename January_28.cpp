class DSU {
    vector<int> parent;
    vector<int> size;
    vector<int> fishSum;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        fishSum.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int getParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = getParent(parent[u]);
    }

    void unionSize(int u, int v, int fishU, int fishV) {
        int parentU = getParent(u);
        int parentV = getParent(v);

        if (parentU == parentV) return;

        if (size[parentU] >= size[parentV]) {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
            fishSum[parentU] += fishSum[parentV];
        } else {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
            fishSum[parentV] += fishSum[parentU];
        }
    }

    void addFish(int u, int fish) {
        int parentU = getParent(u);
        fishSum[parentU] += fish;
    }

    int getFishSum(int u) {
        return fishSum[getParent(u)];
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalCells = m * n;
        DSU dsu(totalCells);

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int current = i * n + j;
                    dsu.addFish(current, grid[i][j]);

                    for (auto dir : directions) {
                        int newi = i + dir.first;
                        int newj = j + dir.second;

                        if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] > 0) {
                            int neighbor = newi * n + newj;
                            dsu.unionSize(current, neighbor, grid[i][j], grid[newi][newj]);
                        }
                    }
                }
            }
        }

        int maxFish = 0;
        for (int i = 0; i < totalCells; i++) {
            if (grid[i / n][i % n] > 0) {
                maxFish = max(maxFish, dsu.getFishSum(i));
            }
        }

        return maxFish;
    }
};
