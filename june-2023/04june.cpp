//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string str)
        {
            stack<string> num;
            stack<char> op;
            string s = "";
            for(auto i: str){
                if(i<'0' || i>'9'){
                    num.push(s);
                    op.push(i);
                    s = "";
                }
                else
                s += i;
            }
            num.push(s);
            s = "";
            while(!op.empty()){
                s += num.top();
                s += op.top();
                num.pop();
                op.pop();
            }
            s += num.top();
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends