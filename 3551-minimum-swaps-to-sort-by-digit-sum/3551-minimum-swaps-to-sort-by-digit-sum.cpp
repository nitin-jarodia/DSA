
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        vector<pair<int, int>> arr;

     
        for (int i = 0; i < n; i++) {
            int d = nums[i];
            int digsum = 0;

            while (d > 0) {
                digsum += d % 10;
                d /= 10;
            }

            arr.push_back({digsum, nums[i]});
        }

        sort(arr.begin(), arr.end());

      
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i].second] = i;
        }

     
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] || mp[nums[i]] == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = mp[nums[j]];
                cycleSize++;
            }

            cnt += cycleSize - 1;
        }

        return cnt;
    }
};
