//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) 
    {
        size_t slash1 = str.find('/');
        size_t comma = str.find(',');
        size_t space = str.find(' ');
        size_t slash2 = str.find('/', comma);
        
        int a = stoi(str.substr(0, slash1));
        int b = stoi(str.substr(slash1 + 1, comma - slash1 - 1));
        int c = stoi(str.substr(comma + 2, slash2 - comma - 2));
        int d = stoi(str.substr(slash2 + 1));
        
        long long left = static_cast<long long>(a) * d;
        long long right = static_cast<long long>(c) * b;
        
        if (left > right)
            return to_string(a) + "/" + to_string(b);
        else if (left < right)
            return to_string(c) + "/" + to_string(d);
        else return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends
