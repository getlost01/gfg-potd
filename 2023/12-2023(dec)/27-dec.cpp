//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void fill(int i, int j, vector<vector<int>>& mat, vector<int>& out){
        while(i < mat.size() && j >= 0){
            out.push_back(mat[i][j]);
            ++i;
            --j;
        }
    }
    vector<int> antiDiagonalPattern(vector<vector<int>>& mat) 
    {
        vector<int> out;
        int n = mat.size();
        for(int j = 0; j < n; ++j)
            fill(0, j, mat, out);
        
        for(int i = 1; i < n; ++i)
            fill(i, n-1, mat, out);
        
        return out;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends