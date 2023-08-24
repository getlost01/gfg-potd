//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


class Solution{
  public:

    string multiplyStrings(string s1, string s2) {
        reverse(s1.begin(),s1.end());
        reverse(s2.begin(),s2.end());
       
        bool isNeg1 = 0, isNeg2 = 0;
       
        if(s1.back() == '-') { s1.pop_back(); isNeg1 = 1; }
        if(s2.back() == '-') { s2.pop_back(); isNeg2 = 1; }
       
        while(s1.back() == '0') s1.pop_back();
        while(s2.back() == '0') s2.pop_back();
       
        int len1 = s1.size(), len2 = s2.size();

        string out(len1 + len2, '0');

        for (int i = 0; i < len2; ++i) {
            int carry = 0, j;
            
            for (j = 0; j < len1; ++j) {
                int mul = (s2[i] - '0') * (s1[j] - '0') + (out[i + j] - '0') + carry;
                out[i + j] = (char)('0' + mul % 10);
                carry = mul / 10;
            }
            
            while (carry) {
                int mul = (out[i + j] - '0') + carry;
                out[i + j] = (char)('0' + mul % 10);
                carry = mul / 10;
                ++j;
            }
        }

        while (out.back() == '0') 
            out.pop_back();
        
        if(!out.size())
            return "0";

        if (isNeg1 ^ isNeg2) 
            out += '-';
        
        reverse(out.begin(), out.end());

        return out;
    }
};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends