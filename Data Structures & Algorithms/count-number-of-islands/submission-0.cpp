class Solution {
public:
    void fun(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis){
        if(vis[i][j]==1) return;
        vis[i][j] = 1;

        if(i+1 < grid.size() && grid[i+1][j]=='1')  fun(grid,i+1,j,vis);
        if(j+1 < grid[0].size() && grid[i][j+1]=='1') fun(grid,i,j+1,vis);
        if(i-1 >= 0 && grid[i-1][j]=='1') fun(grid,i-1,j,vis);
        if(j-1 >= 0 && grid[i][j-1]=='1') fun(grid,i,j-1,vis);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    fun(grid,i,j,vis);
                    count++;
                }
            }
        }
        return count;
    }
};
