class Solution {
public:
    vector<int> dxx = {-1, 1, 0, 0};
    vector<int> dyy = {0, 0, 1, -1};
    vector<vector<int>> visited; 

    void dfs(int i, int j, int& maxx, vector<vector<int>>& grid) {
        visited[i][j] = 1;
        maxx += grid[i][j];
        int m = grid.size(), n = grid[0].size(); 

        for (int k = 0; k < 4; k++) {
            int dxxx = i + dxx[k], dyyy = j + dyy[k];
            if (dxxx >= 0 && dxxx < m && dyyy >= 0 && dyyy < n && !visited[dxxx][dyyy] && grid[dxxx][dyyy] > 0) {
                dfs(dxxx, dyyy, maxx, grid);
            }
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<int>(n, 0)); 
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] > 0) {
                    int maxx = 0;
                    dfs(i, j, maxx, grid); 
                    res = max(res, maxx); 
                }
            }
        }
        return res;
    }
};
