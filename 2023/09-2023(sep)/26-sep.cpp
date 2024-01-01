//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> out;

        sort(arr.begin(), arr.end());

        for (int q1 = 0; q1 < n; ++q1) {
            if (q1 > 0 && arr[q1] == arr[q1 - 1])
                continue;

            for (int q2 = q1 + 1; q2 < n; ++q2) {
                if (q2 > q1 + 1 && arr[q2] == arr[q2 - 1])
                    continue;

                int q3 = q2 + 1, q4 = n - 1;

                while (q3 < q4) {
                    int sum = arr[q1] + arr[q2] + arr[q3] + arr[q4];

                    if (sum == k) {
                        out.push_back({ arr[q1], arr[q2], arr[q3], arr[q4] });
                        q3++;
                        q4--;

                        while (q3 < q4 && arr[q3] == arr[q3 - 1])
                            q3++;
                        while (q3 < q4 && arr[q4] == arr[q4 + 1])
                            q4--;
                    } else if (sum < k)
                        q3++;
                    else
                        q4--;
                }
            }
        }
        return out;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends