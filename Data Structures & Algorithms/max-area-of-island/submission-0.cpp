class Solution {
public:
    void fun(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,int& count){
        
        int n = grid.size();
        int m = grid[0].size();

        if( i >= n || j>=m || j<0 || i<0) return;
        if(vis[i][j]!=0 || grid[i][j]==0) return;
        vis[i][j]=1;
        count++;
        fun(grid,vis,i+1,j,count);
        fun(grid,vis,i,j+1,count);
        fun(grid,vis,i,j-1,count);
        fun(grid,vis,i-1,j,count);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    fun(grid,vis,i,j,count);
                    ans = max(count,ans);
                    count = 0;
                }
            }
        }
        return ans;
    }
};
