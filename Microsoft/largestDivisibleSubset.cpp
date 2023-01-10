class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> par(n, 0);
        vector<int> t(n, 0);

        for(int i=0; i<n; i++){
            par[i] = i;
        }

        int mx = 0;
        int id = 0;
        for(int i=1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j]==0 && t[i]<(t[j]+1)){
                    t[i] = t[j]+1;
                    par[i] = j;
                }

                if(mx<t[i]){
                    mx = t[i];
                    id = i;
                }
            }
        }

        vector<int> ans;
        while(par[id]!=id){
            ans.push_back(nums[id]);
            id = par[id];
        }

        ans.push_back(nums[id]);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};