class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        vector<int> prefix(n);

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {

            int leftsum;

            if (i == 0)
                leftsum = 0;
            else
                leftsum = prefix[i - 1];

            int rightsum = total - leftsum - nums[i];

            if (leftsum == rightsum)
                return i;
        }

        return -1;
    }
};