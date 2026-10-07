class Solution {
public:

    bool dfs(vector<int>& arr, int index, vector<bool>& visited) {

        if (index < 0 || index >= arr.size())
            return false;

        if (visited[index])
            return false;

        if (arr[index] == 0)
            return true;

        visited[index] = true;

        int jump = arr[index];

        return dfs(arr, index + jump, visited) ||
               dfs(arr, index - jump, visited);
    }

    bool canReach(vector<int>& arr, int start) {

        vector<bool> visited(arr.size(), false);

        return dfs(arr, start, visited);
    }
};