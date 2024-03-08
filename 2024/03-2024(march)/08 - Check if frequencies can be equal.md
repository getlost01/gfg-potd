## 08. Check if frequencies can be equal
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/check-frequencies4211/1)

### My Approach
- I iterate through the given string and count the frequency of each character using an unordered_map.
- I find the minimum and maximum frequencies among all characters.
- I check if the difference between the maximum and minimum frequencies is more than 1. If it is, return 0 (false).
- I count the number of characters having the minimum frequency.
- I check if the difference between the total number of unique characters and the number of characters with the minimum frequency is at most 1. If it is, return 1 (true), indicating that frequencies can be made equal.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O`(N)`, where N is the length of the input string.
- **Auxiliary Space Complexity** : At most, 26 unique characters can be used, resulting in a time complexity of `O(26)`

### Code (C++)
```cpp
class Solution {
public:
    bool sameFreq(string s)
    {
        unordered_map<char,int> cnt;
        for(auto i: s)
            cnt[i]++;
        
        int nin, nax;
        nin = nax = cnt[s[0]];
        
        for(auto i: cnt){
            nin = min(nin, i.second);
            nax = max(nax, i.second);
            if(nax - nin > 1)
                return 0;
        }
        
        int cnin = 0;
        for(auto i: cnt)
            if(i.second == nin)
                ++cnin;
            
        return cnt.size() - cnin <= 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.