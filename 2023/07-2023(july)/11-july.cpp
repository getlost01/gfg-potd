//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

class Solution {
public:
    int findK(int a[MAX][MAX], int n, int m, int k) {
        
        int kth = 0;
        int istart = 0, iend = n - 1, jstart = 0, jend = m - 1;
        
        while (istart <= iend && jstart <= jend) {
            for (int j = jstart; j <= jend; ++j) {
                ++kth;
                if (k == kth) return a[istart][j];
            }
            ++istart;
            
            for (int i = istart; i <= iend; ++i) {
                ++kth;
                if (k == kth) return a[i][jend];
            }
            --jend;
            
            for (int j = jend; j >= jstart; --j) {
                ++kth;
                if (k == kth) return a[iend][j];
            }
            --iend;
            
            for (int i = iend; i >= istart; --i) {
                ++kth;
                if (k == kth) return a[i][jstart];
            }
            ++jstart;
        }
    }
};



//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends