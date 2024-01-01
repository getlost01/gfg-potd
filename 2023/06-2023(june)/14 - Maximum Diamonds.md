## 14. Maximum Diamonds

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/chinky-and-diamonds3340/1)

### My Approach

This is a simple `greedy` problem where we have to maximize the number of diamonds in bags at each iteration (from `0` to `k`). We retrieve the maximum number of diamonds from a bag and then put back `half` of the diamonds into the same bag.

To find the maximum number of diamonds at any given moment, I utilize a `priority queue`. Firstly, I push all elements of the `a` array into the priority queue. Then, for `k` iterations, I execute a loop that retrieves the maximum element from the priority queue (which is at the top), removes it, and replaces it with the `halved` value.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n + k log n)`, where `n` is the number of bags (length of array `a`) and k is the number of iterations. Inserting all elements into the priority queue takes O(n) time, and each iteration takes `O(log n)` time for heap operations. Therefore, the overall time complexity is `O(n + k log n)`.
- **Auxiliary Space Complexity**:  `O(n)` since we are using a priority queue to store the elements.

### Code (C++)

```cpp
class Solution {
public:
    long long maxDiamonds(int a[], int n, int k) {
        priority_queue<int> pq;
        for(int i = 0; i < n; ++i)
            pq.push(a[i]);
            
        long long out = 0, pqTop;
        while(k--){
            pqTop = pq.top();
            pq.pop();
            out += pqTop;
            pq.push(pqTop / 2);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.