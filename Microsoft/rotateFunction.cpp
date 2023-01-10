class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            sum+=nums[i];
            ans+=nums[i]*i;
        }

        int res = ans;

        int idx = n-1;
        for(int i=1; i<n; i++){
            ans = ans - (nums[idx]*(n-1)) + (sum-nums[idx]);
            idx--;
            res = max(res, ans);
        }

        return res;
    }
};