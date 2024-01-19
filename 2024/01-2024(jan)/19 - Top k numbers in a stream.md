## 19. Top k numbers in a stream
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/top-k-numbers3425/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To solve this problem, I uses an unordered_map `freqMap` to keep track of the frequency of each number in the stream and uses a set, `topKSet`, to maintain the top k numbers along with their frequencies. The set is sorted based on frequencies in descending order and, for ties, by the number itself in ascending order.
- Then, for each element in the stream, the code checks if the number is already present in the `freqMap`.
- If it is, it removes the existing entry for that number from `topKSet` to update the frequency.
- Then, it increments the frequency in the `freqMap` and inserts the updated frequency and number into `topKSet`.
- The set is then iterated to get the top k numbers, and these are stored in a temporary vector.

### Time and Auxiliary Space Complexity

- **Time Complexity:** `O(N*K)`.

- **Auxiliary Space Complexity:** The space complexity is `O(N)` to store the frequency map and the result vector.

### Code (C++)

```cpp
class Solution {
  public:
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }

    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        unordered_map<int, int> freqMap;
        set<pair<int, int>, decltype(&comp)> topKSet(comp);
        vector<vector<int>> result(N);

        for (int i = 0; i < N; ++i) {
            if (freqMap.find(arr[i]) != freqMap.end()) {
                topKSet.erase({freqMap[arr[i]], arr[i]});
            }

            freqMap[arr[i]]++;
            topKSet.insert({freqMap[arr[i]], arr[i]});

            vector<int> temp;
            auto it = topKSet.begin();

            for (int j = 0; j < K && it != topKSet.end(); ++j, ++it) {
                temp.push_back(it->second);
            }

            result[i] = temp;
        }
        return result;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.