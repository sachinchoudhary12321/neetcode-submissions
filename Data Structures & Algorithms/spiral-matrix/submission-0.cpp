class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        int left=0,right=m-1,top=0,bott = n-1;
        while(left<=right && top<=bott){
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            for(int i=top;i<=bott;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            if(bott>=top){
            for(int j=right;j>=left;j--){
                ans.push_back(mat[bott][j]);
            }
            bott--;
            }
            if(right>=left){
            for(int i=bott;i>=top;i--){
                ans.push_back(mat[i][left]);
            }
            left++;
            }
        }
        return ans;
    }
};
