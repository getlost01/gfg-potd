//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void getLSP(string& pat, vector<int>& lsp) {
        int sz = 0, i = 1;
        lsp[0] = 0;
        while (i < pat.size()) {
            if (pat[i] == pat[sz]) lsp[i++] = ++sz;
            else if (sz == 0) lsp[i++] = 0;
            else sz = lsp[sz - 1];
        }
    }

    vector<int> search(string pat, string txt) {
        int n = pat.size(), m = txt.size();
        vector<int> ls(n), ans;

        getLSP(pat, ls);

        int i = 0, j = 0;
        while (i < m) {
            if (txt[i] == pat[j]) {
                ++i;
                ++j;
            }
            if (j == n) {
                ans.push_back(i - j + 1);
                j = ls[j - 1];
            } else if (i < m && txt[i] != pat[j]) {
                if (!j) i++;
                else j = ls[j - 1];
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends