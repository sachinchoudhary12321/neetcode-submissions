class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> prev(n);
        vector<int> next(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }

        while(st.top()!=-1){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.top()==-1)
                next[i] = n;
            else 
                next[i] = st.top();
            st.push(i);
        }
        int ans=0,area=0;
        for(int i=0;i<n;i++){
            area = arr[i]*(next[i]-prev[i]-1);
            ans = max(ans,area);
        }
        return ans;
    }
};
