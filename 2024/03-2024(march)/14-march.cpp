//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> col(n,vector<int>(n,0));
        vector<vector<int>> row(n,vector<int>(n,0));
        
        for(int i=0;i<n;++i){
            int sum=0;
            for(int j=n-1;j>=0;--j){
                sum = (a[i][j] == 'O')? 0 : sum + 1;
                col[i][j]=sum;
            }
        }
        
        for(int j=0;j<n;++j){
            int sum=0;
            for(int i=n-1;i>=0;--i){
               sum = (a[i][j] == 'O')? 0 : sum + 1;
               row[i][j]=sum;
            }
        }
        
        int out=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                int sq = min(col[i][j],row[i][j]);
                while(sq > out)
                {
                    if((col[i+sq-1][j])>=sq && (row[i][j+sq-1])>=sq)
                        out=sq;
                    
                    --sq;
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
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends