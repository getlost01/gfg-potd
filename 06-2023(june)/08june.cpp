//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    
    string s = "";
    void perm(int n){
        int i,j;
        for(i = n-2;i>=0;--i){
            if(s[i]<s[i+1])
                break;
        }
        for(j = n-1; j>i;--j){
            if(s[j]>s[i])
                break;
        }
        swap(s[j],s[i]);
        sort(s.begin()+i+1,s.end());
    }
    string kthPermutation(int n, int k)
    {
        for(int i = 1;i<=n;++i)
            s += (char)('0'+i);
        while(--k)
            perm(n);
            
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends