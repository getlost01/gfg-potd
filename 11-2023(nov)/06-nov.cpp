//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[]) {
        vector<int> out;
        
        for(int k = 0; k < q; ++k){
            int sum = 0;
            int hop = queries[k][0];
            int x = queries[k][1];
            int y = queries[k][2];
            
            for(int i = x - hop; i <= x + hop; ++i){
                if(i >= 0 && i < n){
                    if(y - hop >= 0)
                        sum += mat[i][y - hop];
                    if(y + hop < m)
                        sum += mat[i][y + hop];
                }
            }
                
            for(int i = y - hop + 1; i < y + hop; ++i){
                if(i >= 0 && i < m){
                    if(x - hop >= 0)
                        sum += mat[x - hop][i];
                    if(x + hop < n)
                        sum += mat[x + hop][i];
                }
            }
                
            out.push_back(sum);
        }
        return out;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends