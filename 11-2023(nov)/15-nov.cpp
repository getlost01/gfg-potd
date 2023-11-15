//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int distSubSeq(string s)
    {
        unordered_map<char, int> last;
        int count = 1;

        for (auto ch : s) {
            int newCount = 2 * count;

            if (last.find(ch) != last.end())
                newCount -= last[ch];

            last[ch] = count;
            count = newCount;
        }
        return count;
    }

    string betterString(string s1, string s2) {
        int distSubSeq1 = distSubSeq(s1);
        int distSubSeq2 = distSubSeq(s2);

        return distSubSeq2 > distSubSeq1 ? s2 : s1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends