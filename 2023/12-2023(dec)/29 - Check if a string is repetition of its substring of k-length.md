## 29. Check if a string is repetition of its substring of k-length
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
This GFG question is a little unclear. In simple terms, it's asking if we can turn a given string into a repeating one by replacing it just once at positions `i` and `j` so that all substrings of length k become repetitive.
```
Example:
s = "ababcdabab"
k = 2
so in this we can replace 0th index substring "ab" with 4th index substring "cd"
```

To solve this question here are the steps:
- First check if the length of the string is divisible by `k`. 
	- If not, it's impossible to form substrings of length k evenly. 
	- If it is divisible, we iterate through the string and maintain a count of each substring of length `k` using an unordered_map. 
	- After counting, we iterate through the map and count how many substrings occur more than once. 
	- The final check is whether the size of the map is less than or equal to 2 (indicating one or two unique substrings) and the count of repeated substrings is at most 1.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n)` where n is the length of the input string. We iterate through the string once.
- **Auxiliary Space Complexity** : `O(n/k)` for the unordered_set, where k is the length of the substring.

### Code (C++)
```cpp
class Solution {
public:
    int kSubstrConcat(int n, string s, int k) {
        if (n % k > 0)
            return 0;

        unordered_map<string,int> mp;
        for (int i = 0; i < n / k; ++i)
            ++mp[s.substr(i * k, k)];
        
        int cnt = 0;
        for(auto i : mp)
            cnt += i.second > 1;

        return (mp.size() <= 2 && cnt <= 1);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.