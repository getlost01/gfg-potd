//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    vector<bool> isPrime;

    void seive() {
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i < isPrime.size(); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < isPrime.size(); j += i)
                    isPrime[j] = 0;
            }
        }
    }

    int solve(int Num1, int Num2) {
        isPrime = vector<bool>(10000, true);
        seive();

        string tar = to_string(Num2);

        unordered_set<string> vis;
        queue<string> q;
        q.push(to_string(Num1));
        vis.insert(to_string(Num1));
        int lvl = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string curr = q.front(), perm;
                q.pop();

                if (curr == tar)
                    return lvl;

                for (int i = 0; i < 4; ++i) {
                    perm = curr;
                    for (char c = '0'; c <= '9'; ++c) {
                        if (i == 0 && c == '0')
                            continue;

                        perm[i] = c;
                        if (isPrime[stoi(perm)] && vis.find(perm) == vis.end()) {
                            vis.insert(perm);
                            q.push(perm);
                        }
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends