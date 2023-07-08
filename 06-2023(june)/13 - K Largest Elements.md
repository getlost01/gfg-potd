## 13. K Largest Elements

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1)

### My Approach

To find the `k` largest elements from a given array, I have used the following approach:

- I am using a min-heap implemented as a priority queue to identify the `k` largest elements from the given array.
- I iterate through the array and insert each element into the priority queue.
- If the size of the priority queue exceeds `k`, I remove the smallest element from the queue.
- After iterating through all the elements, I pop elements from the priority queue and store them in a vector.
- Since the elements in the priority queue are in increasing order, I reverse the order of the elements in the vector.
- Finally, I return the vector containing the `k` largest elements.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n log k)`, where `n` is the size of the array and `k` is the number of largest elements required. This is because for each element, we perform an insertion and potential removal operation in the priority queue, which takes O(log k) time.
- **Auxiliary Space Complexity**: `O(n)` because we use an additional array `out` of size `n` and the priority queue (pq) stores at most `k` elements, resulting in an auxiliary space complexity of `O(k)`.

### Code (C++)

```cpp
class Solution{
public:
    vector<int> kLargest(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<int> out;
            
        for(int i = 0; i < n; ++i){
            pq.push(arr[i]);
            if(pq.size() > k)
                pq.pop();
        }
            
        while(!pq.empty()){
            out.push_back(pq.top());
            pq.pop();
        }
            
        reverse(out.begin(), out.end());
            
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.