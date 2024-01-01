## 05. Top K Frequent Elements in Array
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/top-k-frequent-elements-in-array/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach

When there is top K, by intuition priority queue comes into our mind. So I use a hash map to count the frequency of each element. 
- Then, I use a priority queue (max-heap) to keep track of the K most frequent elements. 
- I iterate through the map, pushing each element and its frequency into the priority queue. Once the queue size exceeds K, I pop the element with the highest frequency, ensuring that only the top K frequent elements remain in the queue. 
- Finally, I return the elements from the priority queue.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N log K)`, where `N` is the number of elements in the input array. Building the frequency map takes `O(N)` time, and inserting and extracting elements from the priority queue takes `O(log K)` time.
- **Auxiliary Space Complexity**: `O(N)`, where `N` is the number of elements in the input array.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto i : nums)
            ++mp[i];
        
        priority_queue<pair<int, int>> pq;
        
        for (auto itr : mp) {
            pq.push({itr.second, itr.first});
        }
        
        vector<int> out;
        while (!pq.empty() && k--) {
            out.push_back(pq.top().second);
            pq.pop();
        }
        
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.