## 28. Wildcard String Matching
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/wildcard-string-matching1126/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach

I have implemented a recursive solution with memoization to check if a wildcard pattern matches a given string. The function `solve` takes two indices, `i` and `j`, representing the current positions in the strings `w` and `p` respectively. It explores three possibilities:

1. If the characters at the current positions match or if `w[i]` is a wildcard (`'?'`), move to the next positions in both strings.
2. If `w[i]` is `*`, it explores two options: 
   - Move to the next character in the pattern (`j+1`).
   - Keep the character in the string (`i+1`) and check for a match.
3. Also do check for base condition, 
	- I check if the index `i` has reached the end of the wildcard string. If yes, I return true if the index `j` has also reached the end of the pattern; otherwise, I return false.
	- If the index `j` has reached the end of the pattern but not the wildcard string, I return true only if the current character in the wildcard string is `'*'`; otherwise, I return false.

The recursive calls are memoized using a 2D vector `dp` to avoid redundant calculations.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(m * n)`, where m and n are the lengths of strings `w` and `p` respectively. This is because each cell in the memoization table is computed once, and there are `m * n` cells.
- **Auxiliary Space Complexity**: `O(m * n)` for the memoization table.

### Code (C++)
```cpp
class Solution {
public:
    bool solve(int i, int j, string &w, string &p, vector<vector<int>>& dp){
        if(i == w.size())
            return j == p.size();
            
        if(j == p.size())
            return w[i] == '*' && solve(i + 1, j, w, p, dp);
        
        if(dp[i][j]!=-1)
          return dp[i][j];
      
        bool ans = false;
        
        if(w[i]==p[j] || w[i]=='?')
            ans = solve(i+1,j+1, w, p,dp);
        else if(w[i]=='*')
            ans = solve(i,j+1, w, p,dp) || solve(i+1,j, w, p,dp);
        
        return dp[i][j] = ans;
    }
    
    bool match(string w, string p){
        vector<vector<int>> dp(w.size(), vector<int> (p.size(), -1));
        return solve(0,0,w,p,dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.