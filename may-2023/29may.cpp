//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> Dictionary, string p) {
        vector<string> out;
        string s;
        for(auto i: Dictionary){
            s = "";
            for(auto j: i){
                if(j>='A' && j<='Z' && s.size()<p.size()){
                    s += j;
                }
            }
            if(s == p)
                out.push_back(i);
        }
        sort(out.begin(),out.end());
        if(out.size()==0) out.push_back("-1");
        return out;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends