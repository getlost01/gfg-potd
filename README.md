# GFG Problem Of The Day

## Today - 16 June 2023
### Que - Min Time

[Question Link](https://practice.geeksforgeeks.org/problems/95bb244da24edd6214086ff934886ccda6ed9da8/1)


### My approach
- Simply find the maximum and minimum values for any type and store them in a collection called `col`.
- We start from 0 and end at 0, so we store the start type and end type as 0.
- Since at any position `i`, we have the choice to either go to the minimum value or the maximum value, we use dynamic programming (DP) to explore all possibilities using the given recurrence relation.

#### The recursive solution with memoization 
But this will give TLE at `1110/1120` test case
```
    long long check(map<int,vector<int>>& col, int i,int tsz, vector<int>& type,int li,vector<vector<int>>& dp){
        if(i == tsz)
        return 0;
        
        if(dp[i][li] != -1)
            return dp[i][li];
        
        auto loc = col[type[i]];
        long long lastval = col[type[i-1]][li];
        long long offset = abs(loc[0] - loc[1]);
        
        dp[i][li] = offset + min(check(col,i+1,tsz,type,1,dp) + abs(lastval - loc[0]), check(col,i+1,tsz,type,0,dp) + abs(lastval - loc[1]));
        return dp[i][li];
    
    }
```


### Code (c++) (Optimize Tabulation form)
```
class Solution {
  public:
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        
        map<int,vector<int>> col; // container to store the fruit types with respective min max value.
        vector<int> type;   // to store different type of fruit we have
        
        for(int i = 0; i<n;++i){
            if(col.find(types[i])==col.end()){
                col[types[i]] = vector<int>(2,locations[i]);
            }else{
                col[types[i]][0] = min(col[types[i]][0] , locations[i]);
                col[types[i]][1] = max(col[types[i]][1] , locations[i]);
            }
        }

        col[0] = vector<int>(2,0); // since we start from 0 so put type 0 as zero
        col[1000002] = vector<int>(2,0); // since we end to 0 so put type 0 as zero

        for(auto i: col)
            type.push_back(i.first);
            
        int tsz = type.size();  // total types of fruits we have
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
```

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)