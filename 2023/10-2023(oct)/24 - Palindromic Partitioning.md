## 24. Palindromic Partitioning
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1)

![](https://badgen.net/badge/Level/Hard/red)

### My Approach

I use recursion and memoization DP to find the minimum number of cuts required to partition a given string into palindromic substrings. 
- I maintain a 2D DP array, `dp`, where `dp[i][j]` represents the minimum number of cuts needed to make the substring `str[i...j]` a palindrome. 
- To compute `dp[i][j]`, I iterate over all possible substrings within the range `(i, j)`. 
	- If the substring is already a palindrome, `dp[i][j]` is set to 0. 
	- If not, I calculate `dp[i][j]` by considering all possible cuts between `i` and `j` and choose the minimum.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n*n)`, where n is the length of the input string `str`.
- **Auxiliary Space Complexity**: `O(n*n)`, as we use a 2D DP array of size n x n.

### Code (C++)
```cpp
class Solution {
public:
    bool isPalin(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i;
            --j;
        }
        return true;
    }
    
    int check(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if (isPalin(i, j, s)) return dp[i][j] = 0;
        
        int out = INT_MAX;
        for (int k = i; k < j; ++k) {
            if (isPalin(i, k, s)) {
                out = min(out, 1 + check(k + 1, j, s, dp));
            }
        }
        return dp[i][j] = out;
    }
    
    int palindromicPartition(string str) {
        int n = str.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        check(0, n - 1, str, dp);
        return check(0, n - 1, str, dp);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.