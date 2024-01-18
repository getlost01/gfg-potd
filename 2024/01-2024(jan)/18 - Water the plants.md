## 18. Water the plants
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/water-the-plants--170646/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I am using a greedy approach to find the minimum number of sprinklers needed to water all the plants, here is the approach.
- For each plant, determine the range it can be watered. This is done by considering the plant's position and its sprinkler range.
- Update a vector `range` to store the maximum rightmost position each position can be watered.
- Traverse the plants and count the number of sprinklers needed based on the updated `range` vector. 
	- Also check, If any position is not covered by any sprinkler, return -1. 
	- Otherwise, count the number of sprinklers needed to water all the plants.

### Time and Auxiliary Space Complexity

- **Time Complexity:** The algorithm has a time complexity of `O(N*max(gallery[i]))`, where N is the number of plants, and max(gallery[i]) is the range of water sprinkler.
- **Auxiliary Space Complexity:** The algorithm uses `O(N)` extra space to store the `range` vector.

### Code (C++)

```cpp
class Solution {
public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<int> range(n, -1);

        for(int i = 0; i < n ; ++i){
            int l = max(0, i - gallery[i]);
            int r = min(n - 1, i + gallery[i]);
            for(int j = l; j <= r; ++j){
                range[j] = max(range[j], r);
            }
        }
        
        int count = 0, last = -1;

        for (int i = 0; i < n; ++i) {
            if (range[i] == -1) {
                return -1;
            }

            if (i > last) {
                ++count;
                last = range[i];
            }
        }
        return count;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.