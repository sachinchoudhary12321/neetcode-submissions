class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({{i,j},0});
            }
        }
        vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
        int ans = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();
            for(auto [dx,dy]:dir){
                int nx = x + dx;
                int ny = y + dy;

                if(nx >= 0 && ny >=0 && nx < n && ny < m && grid[nx][ny] == 1){
                    ans = time+1;
                    grid[nx][ny] = 2;
                    q.push({{nx,ny},ans});
                }
            }


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return ans;
    }
};
