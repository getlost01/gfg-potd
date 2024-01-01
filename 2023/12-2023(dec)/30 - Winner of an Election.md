## 30. Winner of an Election
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

In this problem, I used an unordered map to count the occurrences of each candidate. Then I iterated through the map to find the candidate with the maximum votes, considering lexicographical order in case of a tie.

### Time and Auxiliary Space Complexity

- **Time Complexity:** `O(n)`, where n is the number of votes.
- **Auxiliary Space Complexity:** `O(c)`, where c is the number of unique candidates.

### Code (C++)

```cpp
class Solution{
public:
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> mp;
        for(int i = 0; i < n ; ++i)
            ++mp[arr[i]];
        
        string out;
        int cnt = 0;
        for(auto i: mp){
            if(cnt < i.second){
                cnt = i.second;
                out = i.first;
            } else if(cnt == i.second){
                if(out > i.first)
                    out = i.first;
            }
        }
        return {out, to_string(cnt)};
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.