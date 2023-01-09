class Solution {
public:
    void solve(int i, vector<int> &t, vector<vector<int> > &ans, int k, int n){
        if(n==0 && k==0){
            ans.push_back(t);
            return;
        }

        if(i==10){
            return;
        }

        if(i<=n){
            t.push_back(i);
            solve(i+1, t, ans, k-1, n-i);
            t.pop_back();
        }
        

        solve(i+1, t, ans, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;

        vector<int> t;

        solve(1, t, ans, k, n);

        return ans;
    }
};