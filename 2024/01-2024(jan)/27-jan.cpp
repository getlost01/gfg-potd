//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string matrixChainOrder(int p[], int n) {
        pair<int, string> dp[n][n];

        for (int gap = 1; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
                if (gap == 1) {
                    string res = "0";
                    res[0] = 'A' + i;
                    dp[i][j] = {0, res};
                } else {
                    dp[i][j] = {INT_MAX, "-1"};
                    for (int k = i + 1; k <= j - 1; k++) {
                        int cost = p[i] * p[k] * p[j] + dp[i][k].first + dp[k][j].first;
                        if (dp[i][j].first > cost) {
                            dp[i][j].first = cost;
                            dp[i][j].second = "(" + dp[i][k].second + dp[k][j].second + ")";
                        }
                    }
                }
            }
        }

        return dp[0][n - 1].second;
    }
};


//{ Driver Code Starts.

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends