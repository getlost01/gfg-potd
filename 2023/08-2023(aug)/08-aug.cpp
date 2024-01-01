//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countFractions(int n, int num[], int den[])
    {
        map<pair<int, int>, int> mp;
        
        for (int i = 0; i < n; ++i)
        {
            int gcd = __gcd(num[i], den[i]);
            ++mp[{num[i] / gcd, den[i] / gcd}]; // In map I have stored the simplified rational numbers.
        }

        int out = 0;
        
        for (auto i : mp)
        {
            int nume = i.first.first;
            int deno = i.first.second;
            int cnt = i.second;
            
            if (i.second)
            {
                int newNume = deno - nume;
                if (nume == newNume)
                {
                    out += (cnt * (cnt - 1)) / 2;
                }
                else if (mp.find({newNume, deno}) != mp.end())
                {
                    out += cnt * mp[{newNume, deno}];
                    mp[{newNume, deno}] = 0;
                }
            }
        }
        return out;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends