class Solution {
public:
    void dfs(vector<vector<int>>& nums,int x,int y,vector<vector<int>>& vis){
        vis[x][y]=1;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        for(auto [dx,dy]:dir){
            int nx = x + dx;
            int ny = y + dy;

            if(nx >=0 && nx < nums.size() && ny >=0 && ny < nums[0].size() && nums[x][y] <= nums[nx][ny] 
            && vis[nx][ny]==0){
                dfs(nums,nx,ny,vis);
            }
        }


    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<vector<int>> pecific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(pecific[i][0]==0)
                dfs(nums,i,0,pecific);
            if(atlantic[i][m-1]==0){
                dfs(nums,i,m-1,atlantic);
            }
        }
        for(int j=0;j<m;j++){
            if(pecific[0][j]==0)
                dfs(nums,0,j,pecific);
            if(atlantic[n-1][j]==0)
                dfs(nums,n-1,j,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j]==1 && pecific[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
