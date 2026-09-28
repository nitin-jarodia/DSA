class Solution {
public:

        void permute(vector<int> &nums, set<vector<int>> &ans,
                 vector<int> &ds, vector<int> &freq) {

        if (ds.size() == nums.size()) {
            ans.insert(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;

                permute(nums, ans, ds, freq);

                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> ans;
        vector<int> ds;
        vector<int> freq(nums.size(), 0);

        permute(nums, ans, ds, freq);
vector<vector<int>> res(ans.begin(), ans.end());

return res;
    }
};