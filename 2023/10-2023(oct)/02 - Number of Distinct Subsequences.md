## 2. Number of Distinct Subsequences

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1)

### My Approach

I solved this problem using dynamic programming. Here's the intution behind it:

- To calculate the number of unique subsequences for the 'ith' character, it's simply double the number of subsequences for the 'i-1th' character.
- However, there's a catch. We need unique subsequences, so we check the last occurrence of the current character and subtract it from the total number of subsequences to get our final answer.

```js
let s = "ngfg"

- { "" } = 1
- { "", "n" } = 2 , for i = 0
- { "", "n" , "g", "ng" } = 4 , for i = 1
- { "", "n" , "g", "f", "ng", "gf", "nf", "ngf" } = 8 , for i = 2
- { "", "n" , "g", "f", "ng", "gf", "gg", "nf", "gg", "ngf", "ngg", "nfg", "gfg", "ngfg" } = 14 , for i = 3

In the last step, since the last occurrence of 'g' is at index 1, we have already included subsequences like {"g", "ng"}. So, our final answer is 16 - 2 = 14.
```

Here's how it works:

- Create a vector `last` of size 26, initialized with -1. This vector will store the last occurrence of each character in the string `s`.
- Create a dynamic programming array `dp` of size `n+1`, where `n` is the length of the input string `s`. Initialize `dp[0]` to 1 because there is one empty subsequence.
- Loop through the characters of the string `s` from left to right (index `i` from 1 to `n`).
	- Calculate `dp[i]` as `dp[i-1]*2`, which represents the total number of subsequences that include the current character `s[i-1]`.
	- Find the last occurrence of the current character `s[i-1]` using the `last` vector.
	- If `lastOccur` is not -1 (i.e., the character has occurred before), subtract `dp[lastOccur]` from `dp[i]`. This step removes the count of subsequences that include duplicate characters, ensuring distinct subsequences.
	- Perform modulo `mod` to keep the values of `dp[i]` within a valid range.
	- Update the `last` vector with the current index `i-1` for the character `s[i-1]`.
- Return `dp[n]`, which represents the total number of distinct subsequences of the input string `s`."

### Time and Auxiliary Space Complexity

- **Time Complexity**: The algorithm runs in `O(n)` time, where n is the length of the input string `s`.
- **Auxiliary Space Complexity**: The algorithm uses `O(26)` extra space for the `last` vector and `O(n)` space for the `dp` array, resulting in a total auxiliary space complexity of `O(n)`.

### Code (C++)
```cpp
class Solution {
public:
    int mod = 1e9 + 7;
    
    int distinctSubsequences(string s) {
        int n = s.size();
        
        vector<int> last(26, -1);
        long long dp[n + 1];
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] * 2;
            int lastOccur = last[s[i - 1] - 'a'];
            
            if (lastOccur != -1) {
                dp[i] -= dp[lastOccur];
                if (dp[i] < 0)
                    dp[i] += mod;
            }
            dp[i] %= mod;
            last[s[i - 1] - 'a'] = i - 1;
        }
        return dp[n];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.