class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> v(n);
        vector<int> ind(n,0);
        for(int i=0;i<pre.size();i++){
            v[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        vector<int> vis(n,0);
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            vis[node]=1;
            q.pop();
            
            for(int it:v[node]){
                ind[it]--;
                if(ind[it]==0){
                    q.push(it);
                }
            }
        }
        for(int it:vis){
            if(it==0) return {};
        }
            return ans;
        
    }
};
