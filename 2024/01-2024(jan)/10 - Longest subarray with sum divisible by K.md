## 10. Longest subarray with sum divisible by K
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I approached this problem using a hashmap to store the remainder of the cumulative sum when divided by `k`. The key idea is to find two indices with the same remainder to get a subarray whose sum is divisible by `k`.
- I initialized a hashmap `mp` with an initial entry of {0, -1}, indicating that the sum 0 is seen at index -1.
- I iterated through the array, updating the cumulative sum and calculating the remainder when divided by `k`.
- To handle negative remainders, I added `k` to the remainder if it was negative.
- If the remainder was already in the hashmap, I updated the maximum subarray length `out` by comparing it with the difference between the current index and the index stored in the hashmap for that remainder. Otherwise, I added a new entry in the hashmap.
- The final result is the length of the longest subarray with a sum divisible by `k`.

### Time and Auxiliary Space Complexity
- **Time Complexity**: `O(n)`, where n is the size of the array. The algorithm processes each element of the array once.
- **Auxiliary Space Complexity**: `O(min(n, k))`, where `n` is the size of the array. The hashmap `mp` stores at most `min(n, k)` entries.

### Code (C++)
```cpp
class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int out = 0, sum = 0;
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            int rem = sum % k;
            
            if (rem < 0)
                rem += k;
            
            if (mp.find(rem) != mp.end())
                out = max(out, i - mp[rem]);
            else
                mp[rem] = i;
        }
        
        return out;
    }
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.