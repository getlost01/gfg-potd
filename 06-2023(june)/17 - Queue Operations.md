## 17. Queue Operations

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/queue-operations/1)

### My Approach 1

To perform queue operations, I have implemented the following approach:

- For the `insert()` function, I simply push the given element (`k`) into the queue using the `push()` method.
- For the `findFrequency()` function, I iterate over all the elements in the queue. I compare each element with the given number (`k`) and count the occurrences.
- Finally, I return the frequency count (`c`).

#### Time Complexity

- The `insert()` function has a time complexity of `O(1)` since it performs a single operation to push an element into the queue.
- The `findFrequency()` function has a time complexity of `O(n)` since it iterates over all the elements in the queue to count the occurrences of `k`.

### Code (C++)

```cpp
class Solution{
public:
    void insert(queue<int> &q, int k){
        q.push(k);
    }
    
    int findFrequency(queue<int> &q, int k){
        int sz = q.size();
        int c = 0;
        while(sz--){
            if(q.front() == k)
                ++c;
            q.push(q.front());
            q.pop();
        }
        return c;
    }
};
```

### My Approach 2

Alternatively, you can use a map or hash structure to store the frequency of each element in the queue. Here's the modified approach:

- Declare a map or unordered_map (`hash`) to store the frequency of each element in the queue.
- For the `insert()` function, increment the frequency of the given element (`k`) in the `hash` map and push the element into the queue using the `push()` method.
- For the `findFrequency()` function, return the frequency of the given number (`k`) from the `hash` map.

#### Time Complexity

- The `insert()` function has a time complexity of `O(log n)` since it requires inserting elements into the map, which takes logarithmic time complexity for balanced trees.
- The `findFrequency()` function has a time complexity of `O(log n)` since it performs a lookup operation in the map.

### Code (C++)

```cpp
class Solution{
public:
    map<int, int> hash;
    
    void insert(queue<int> &q, int k){
        ++hash[k];
        q.push(k);
    }
    
    int findFrequency(queue<int> &q, int k){
        return hash[k];
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.