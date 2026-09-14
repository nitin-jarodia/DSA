class Solution {
public:
    int dp[10005][1005];
    int n;

    int f(vector<int>& nums, int i, int k) {
        if (i >= n - 1) return 0;
        if (k == 0) return INT_MAX;

        if (dp[i][k] != -1) return dp[i][k];

        int ans = INT_MAX;

        for (int j = 1; j <= k && i + j < n; j++) {
            int next = f(nums, i + j, nums[i + j]);
            if (next != INT_MAX) { 
                ans = min(ans, 1 + next);
            }
        }

        return dp[i][k] = ans;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        n = nums.size();
        return f(nums, 0, nums[0]);
    }
};
