//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
    vector<string> out;

    void check(string &s, int i, int &n){
        if(i == n){
            out.push_back(s);
            return; 
        }
        
        for(int j = i; j < n; ++j){
            swap(s[i], s[j]);
            check(s, i+1, n); 
            swap(s[i], s[j]); 
        }
    }
  
    vector<string> permutation(string s){
        int n = s.size(); 
        check(s, 0, n); 
        sort(out.begin(), out.end());
        return out; 
    }
};


//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends