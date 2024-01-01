//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        
        map<int,vector<int>> col;
        vector<int> type;
        
        for(int i = 0; i<n;++i){
            if(col.find(types[i])==col.end()){
                col[types[i]] = vector<int>(2,locations[i]);
            }else{
                col[types[i]][0] = min(col[types[i]][0] , locations[i]);
                col[types[i]][1] = max(col[types[i]][1] , locations[i]);
            }
        }

        col[0] = vector<int>(2,0);
        col[1000002] = vector<int>(2,0); 

        for(auto i: col)
            type.push_back(i.first);
            
        int tsz = type.size();
        long long dp[tsz+1][2],lastval,offset;
        dp[tsz][0] = dp[tsz][1] = 0;
        
        for(int i = tsz-1; i>=0; --i){
            for(int li = 1; li>=0; --li){
                auto loc = col[type[i]];
                
                lastval = col[type[i-1]][li];
                offset = abs(loc[0] - loc[1]);
                
                dp[i][li] = offset + min(dp[i+1][1] + abs(lastval - loc[0]), dp[i+1][0] + abs(lastval - loc[1]));
            }
        }
        
        return min(dp[0][0], dp[0][1]);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends