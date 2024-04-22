//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int out = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < m; ++j)
                a[i][j] += a[i][j-1];
            if(a[out].back() > a[i].back())
                out = i;
        }
        return out + 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends