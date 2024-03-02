## 02. First element to occur k times
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/first-element-to-occur-k-times5150/1)

### My Approach
- We use an unordered map to store the frequency of each element while iterating through the array.
- At each step, we check if the frequency of the current element equals k. If it does, we return that element.
- If no such element is found, we return -1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(n) - We iterate through the array once.
- **Auxiliary Space Complexity**: O(n) - We use an unordered map to store the frequency of elements.

### Code (C++)
```cpp
class Solution {
public:
    int firstElementKTime(int n, int k, int a[]) {
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; ++i){
            ++mp[a[i]];
            if(mp[a[i]] == k)
                return a[i];
        }
        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
