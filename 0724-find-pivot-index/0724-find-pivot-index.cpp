class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int k = 0; k < n; k++) {
            int leftsum = 0;
            int rightsum = 0;

            int left = 0;
            int right = n - 1;

            while (left < k) {
                leftsum += nums[left];

                left++;
            }

            while (right > k) {
                rightsum += nums[right];

                right--;
            }
            if (leftsum == rightsum) {
                return k;
            }
        }
        return -1;
    }
};