class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        // code here
                vector<int> top(K + 1,0);
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++) {
            mp[arr[i]]++;
            top[K] = arr[i];
            auto it = find(top.begin(), top.end() - 1, arr[i]);
            int index = it - top.begin() - 1;
            for (int j = index ; j >= 0; --j) {
                if (mp[top[j]] < mp[top[j + 1]])
                    swap(top[j], top[j + 1]);
                else if ((mp[top[j]] == mp[top[j + 1]]) && (top[j] > top[j+1]))
                    swap(top[j], top[j + 1]);
                else
                    break;
            }
            vector<int>temp;
            for (int i = 0; i < K && top[i] != 0; ++i)
                temp.push_back(top[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};
