## 19. Find missing in second array
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/in-first-but-second5423/1)

### My Approach
- We create an unordered set to store all elements of array b.
- Then, we iterate through array a. For each element in a, if it's not present in set b, we push it into the output vector.
- Finally, we return the output vector containing the missing elements.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(n + m), where n is the size of array a and m is the size of array b.
- **Auxiliary Space Complexity**: O(m), where m is the size of array b.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> findMissing(int a[], int b[], int n, int m) 
    { 
        unordered_set<int> s;
        vector<int> out;
        for(int i = 0; i < m; ++i) 
            s.insert(b[i]); 
            
        for(int i = 0; i < n; ++i) 
            if(!s.count(a[i])) 
                out.push_back(a[i]);
                
        return out;
    } 
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.