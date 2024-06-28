//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr)
    {
        vector<std::tuple<int, int, int>> orders;
        for (int i = 0; i < n; ++i)
            orders.emplace_back(std::abs(arr[i] - brr[i]), arr[i], brr[i]);
        sort(orders.rbegin(), orders.rend());
        long long totalTips = 0;
        int countA = 0, countB = 0;
        for (const auto& order : orders)
        {
            int diff = std::get<0>(order);
            int tipA = std::get<1>(order);
            int tipB = std::get<2>(order);
            if ((tipA >= tipB && countA < x) || countB >= y)
            {
                totalTips += tipA;
                countA++;
            }
            else
            {
                totalTips += tipB;
                countB++;
            }
        }
        return totalTips;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends
