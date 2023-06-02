//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    int dfs(int n, int m, vector<vector<int>> &g,vector<bool>& vis,int node){
        int out = 1;
        vis[node] = 1;
        for(auto i: g[node]){
            if(!vis[i]){
                out += dfs(n,m,g,vis,i);
            }
        }
        return out;
    }

  
    vector<int> kPrime;
    void precompute(){
        vector<int> isPrime(1e6+1, true);
        isPrime[0]=false;
        isPrime[1]=false;
        for (int i=2;i<=1e6+1;++i){
            if(isPrime[i]==true){
                kPrime.push_back(i);
                for (int j=2*i;j<=1e6+1;j+=i){
                    isPrime[j]=false;
                }
            }
        }
    }
    
    int helpSanta(int n, int m, vector<vector<int>> &g){
        vector<bool> vis(n+1,0);
        int out = -1;
        for(int i = 1;i<=n;++i){
            if(!vis[i]){
                out = max(out,dfs(n,m,g,vis,i));
            }
        }
        if(out>1){
            out = kPrime[out-1];
        }else out = -1;
        return out;
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends