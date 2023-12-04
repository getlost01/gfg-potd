//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution {
public:
    string add(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res;

        while (i >= 0 && j >= 0) {
            int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
            --j;
        }
        while (i >= 0) {
            int sum = (num1[i] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --i;
        }
        while (j >= 0) {
            int sum = (num2[j] - '0') + carry;
            res += (sum % 10) + '0';
            carry = sum / 10;
            --j;
        }
        if (carry)
            res += carry + '0';
            
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool solve(string& s, int i, int j, int k) {
        string num1 = s.substr(i, j - i);
        string num2 = s.substr(j, k - j);
        string sum = add(num1, num2);

        int n = sum.size();
        int len = k + n;

        if (len > s.size())
            return false;

        string currSum = s.substr(k, n);

        if (currSum != sum)
            return false;
        if (len == s.size())
            return true;
        return solve(s, j, k, len);
    }

    int isSumString(string& s) {
        int n = s.size();
    
        for (int j = 1; j < n; ++j) 
            for (int k = j + 1; k < n; ++k) 
                if (solve(s, 0, j, k))
                    return true;

        return false;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends