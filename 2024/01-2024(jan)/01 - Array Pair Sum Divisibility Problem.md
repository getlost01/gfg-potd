## 01. Array Pair Sum Divisibility Problem
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I approached this problem by counting the occurrences of each element's remainder when divided by `k`. Then, I checked whether pairs of remainders that should sum up to `k` have the same frequency. 

- Check if the size of the input array is even; return false if not.
- Count the occurrences of each remainder when divided by `k`.
- Compare the frequencies of remainders at positions `l` and `r` where `l` starts from 1 and `r` starts from `k-1` and moves towards each other.
  - If frequencies don't match, return false.
- Check the middle element (if `k` is odd) and the remainder `0`.
  - If either of them has an odd frequency, return false.
- If all checks pass, return true.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n), where n is the size of the input vector.
- **Auxiliary Space Complexity** : O(k), where k is the input parameter.

### Code (C++)
```cpp
class Solution {
public:
    bool canPair(vector<int> nums, int k) {
        if(nums.size() % 2 != 0)
            return false;
            
        vector<int> cnt(k, 0);
        
        for(auto i: nums)
            ++cnt[i % k];
        
        int l = 1, r = k - 1;
        
        while(l < r){
            if(cnt[l] != cnt[r])
                return false;
            ++l;
            --r;
        }
        
        if((l == r && cnt[l] % 2 != 0) || cnt[0] % 2 != 0)
            return false;
        
        return true;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.