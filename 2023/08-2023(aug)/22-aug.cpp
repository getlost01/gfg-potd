//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int findMinOpeartion(vector<vector<int>>a, int n)
    {
        long long sumRow, sumCol;
        long long maxRow=0, maxCol=0, total = 0;
                
        for(int i=0;i<n;i++){
            sumRow = sumCol = 0;
            
            for(int j=0;j<n;j++){
                sumRow += a[i][j];
                sumCol += a[j][i];
                total += a[i][j];
            }
            
            maxRow = max(maxRow, sumRow);
            maxCol = max(maxCol, sumCol);
        }
        
        return max(maxRow*n, maxCol*n) - total;
    } 
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends