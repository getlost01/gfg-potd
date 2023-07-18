//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    string FirstNonRepeating(string A) {
        vector<int> cnt(26, 0);
        vector<char> last;
        int firstOccur = 0;
        string out = "";

        for (int i = 0; i < A.size(); ++i) {
            cnt[A[i] - 'a']++;
            
            if (cnt[A[i] - 'a'] == 1)
                last.push_back(A[i]);
            
            while (firstOccur < last.size() && cnt[last[firstOccur] - 'a'] > 1) 
                ++firstOccur;
            
            if (firstOccur == last.size()) {
                out += '#';
            } else {
                out += last[firstOccur];
            }
            
        }
        return out;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends