//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K)
    {
        pair<int, int> last={0, K};
        int n=S.size();
        int index=0;
        while(index < n)
        {
            if(S[index] != '0')
            {
                if(K)
                    --K;
                else break;
                index++;
            }
            else
            {
                while(index<n and S[index]=='0')
                    index++;
                last={index, K};
            }
        }
        stack<int>num;
        int start=last.first;
        K=last.second;
        for(int i = start; i < n; i++
        {
            while(num.size() and num.top()>(S[i]-'0') and K)
            {
                K--;
                num.pop();
            }
            
            num.push(S[i]-'0');
        }
        
        while(num.size() and K--)
            num.pop();
        string ans="";
        while(num.size())
        {
            ans+=to_string(num.top());
            num.pop();
        }
        reverse(ans.begin(), ans.end());
        if(ans=="")
            ans="0";
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
