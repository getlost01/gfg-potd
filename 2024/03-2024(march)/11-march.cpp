//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution {
public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n, int x)
    {
        int sz = n * n;
        int l = 0, r = sz - 1;
        int cnt = 0;
        
        while (l < sz && r >= 0)
        {
            int sum = mat1[l / n][l % n] + mat2[r / n][r % n];
            
            if (sum == x) {
                l++;
                r--;
                ++cnt;
            }
            else if (sum > x)
                --r;
            else
                ++l;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.


int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;

        vector<vector<int>> mat1(n, vector<int>(n, -1));
        vector<vector<int>> mat2(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat1[i][j];
        	}
        }

        for(int i = 0; i < n; i++)
        {
        	for(int j = 0; j < n; j++)
        	{
        		cin >> mat2[i][j];
        	}
        }

        Solution ob;

        cout << ob.countPairs(mat1, mat2, n, x) << "\n";

    }

    return 0;
}
// } Driver Code Ends