class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int left = 0;

        int sum = 0;
        int minsum = 0;
        int minsize = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target || sum == target) {

                minsize = min(minsize, right - left + 1);

                
                sum -= nums[left];
                left++;
            }
        }
        if(minsize == INT_MAX){
            return 0;
        }
        return minsize;
    }
};