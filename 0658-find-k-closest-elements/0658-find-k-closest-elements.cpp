class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;

        int left = 0;
        int right = n - 1;

        int leftsub = 0;
        int rightsub = 0;

        while (right - left + 1 > k) {
            leftsub = abs(arr[left] - x);
            rightsub = abs(arr[right] - x);

            if (leftsub > rightsub) {

                left++;
            }

            else {
                right--;
            }
        }
        for (int i = left; i <= right; i++){
            ans.push_back(arr[i]);
    }
    return ans;
}
   
}

;