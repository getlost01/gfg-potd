//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence)
    {
        long long maxNumber = -1;
        stringstream ss(sentence);
        string word;
        while (ss >> word)
        {
            if (all_of(word.begin(), word.end(), ::isdigit))
            {
                long long num = stoll(word);
                if (word.find('9') == string::npos)
                {
                    if (num > maxNumber)
                        maxNumber = num;
                }
            }
        }
        return maxNumber;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends
